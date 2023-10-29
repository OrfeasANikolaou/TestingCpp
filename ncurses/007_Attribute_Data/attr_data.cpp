#include <ncurses/curses.h>
#include <iostream>
int main(void){
	initscr();
	raw();
	noecho();
	cbreak();
	if ( !has_colors() ) {endwin(); std::cout << "Terminal doesn't have colors" << std::endl;}
	start_color();

	init_pair (1, COLOR_GREEN, COLOR_BLACK);
	init_pair (2, COLOR_WHITE, COLOR_BLUE);

	attr_t some_attr = COLOR_PAIR(2);
	//attr_t sasdasd = PAIRS | ATTRIBUTES | ATTRIBUTES...
	attroff(1);
	attron(some_attr);
	wprintw(stdscr, "HELLO WORLD\n");
	attroff(some_attr);

//	doesn't store attributes
//	int c = 'a' | A_REVERSE | COLOR_PAIR(1);	

//  stores attributes
		chtype c = 'a' | A_REVERSE | COLOR_PAIR(1);	

	mvwaddch (stdscr, 10, 50, c);

	getch();
	endwin();
	return 0;
}
