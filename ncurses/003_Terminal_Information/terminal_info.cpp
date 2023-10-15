#include <ncurses.h>
#include <ncurses/curses.h>

int main(void){
	initscr();
	noecho();
	raw();
	
	int row, col, brow, bcol, mrow, mcol;

	//outputs cursor location into row, col;
	getyx(stdscr, row, col);
	//outputs beggining location of window / stdscrn
	getbegyx(stdscr, brow, bcol);
	//outputs height and width of window / stdscrn
	getmaxyx(stdscr, mrow, mcol);

	printw("Current cursor location line n: %d col n: %d\n"
				 "Beginning location of stdscr: line n: %d col n: %d\n"
				 "stdscr Height: %d Width %d\n",
				 	row, col,
					brow, bcol,
					mrow, mcol);

	refresh();

	
	getchar();
	endwin();

	return 0;
}
