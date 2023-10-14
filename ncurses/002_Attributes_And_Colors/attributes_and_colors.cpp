#include <ncurses.h>
#include <ncurses/curses.h>
	//attron()
	//attroff() attribute on/off
	
	/*
	 * A_NORMAL
	 * A_STANDOUT
	 * A_REVERSE
	 * A_BLINK
	 * A_DIM
	 * A_BOLD
	 * A_PROTECT
	 * A_INVIS
	 * A_ALTCHARSET
	 * A_CHARTEXT
	 */
int main(void){
	initscr();
	
	
	attron(A_NORMAL);
	printw("This is a test\n");
	attroff(A_NORMAL);
	
	
	
	getchar();	
	endwin();
	return 0;
}
