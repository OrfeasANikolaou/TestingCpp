#include <ncurses/curses.h>
void background_color_change(int );

int main(void){

	initscr();
	noecho();
	refresh();
	if (!has_colors()) return -1;
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	background_color_change(1);

	WINDOW* win = newwin(30, 150,
											 LINES/2-15, COLS/2-75);
	box (win, 0, 0);
	wrefresh(win);

	getch();	
	wclear(win);	
	wrefresh(win);
	delwin(win); 	// malloc free new delete
	// delwin doesn't delete the visual representation of the window

	getch();
	endwin();
	return 0;
}
void background_color_change(int color){

	for (int i = 0; i < LINES; ++i){
		move(i, 0);
		chgat (-1, A_NORMAL, 1, NULL);
		refresh();
	}

}
