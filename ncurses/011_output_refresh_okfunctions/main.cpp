#include <ncurses/curses.h>
void blue_background(void);
int main (void){

	initscr ();
	noecho ();
	refresh ();

	if ( !has_colors ()) return -1;
	start_color ();
	init_pair (1, COLOR_WHITE, COLOR_BLUE);
	blue_background ();	
	//idlokok
	//idcok
	
	
	//clearok										// INSTEAD OF REFRESHING WHAT CHANGED REFRESHES EVERYTHING
	//immedok										// DRAWING FUNCTIONS WON'T NEED (w)refresh ()
	//leaveok										// CURSOR MOVES IN MEMORY BUT DOESN'T GET REFRESHED
	//scrollok	(WINDOW*, bool) // ADDS SCROLLING EFFECT INSTEAD OF CHAGING LAST CHAR WHEN WINDOW IS FULL 
	move (0, 0);			 



	WINDOW* win = newwin (30, 140, 
												LINES/2-15, COLS/2-70);
	leaveok (win, 1);	// CURSOR MOVES IN MEMORY BUT DOESN'T GET REFRESHED
	box (win, 0, 0);
	
	
	wmove (win,
				 7,7);
	wprintw (win,
					"Hello world");

	wrefresh (win);


	getch ();
	endwin ();
	return 0;
}
void blue_background(void){
	for (int i = 0; i < LINES; ++i){
		move (i, 0);
		chgat (-1, A_NORMAL, 1, NULL);
		refresh ();
	}
}
