#include <ncurses.h>
#include <ncurses/curses.h>

int main(void){
	initscr();
	raw();
	noecho();
	cbreak();
	halfdelay(10);
	nodelay(stdscr, false);
	timeout(-1);
	int c;
	while( (c = getch()) != 'x' ){
		wprintw(stdscr, "%c\n", c);
	}



	endwin();
	return 0;
}
