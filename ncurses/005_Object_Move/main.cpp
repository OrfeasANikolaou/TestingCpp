#include <ncurses.h>
#include "./headers/player.hpp"

int main (void){
	initscr ();
	raw ();
	noecho ();
	cbreak ();
	
	int y, x;
	getmaxyx (stdscr, y, x);
	WINDOW* field = newwin (25, 100,
													y/2-17, x/2-50);
	box (field, 0, 0);
/*	border ('|', '|', 
					'-', '-', 
					'+', '+', '+', '+');
*/
	box (stdscr, 0, 0);
	refresh (); wrefresh (field);	

	Player* p = new Player (field, 
												 1,1,
												 '@');;
	do{
		p->display ();
		wrefresh (field);
	}while(p->get_mv () != 'x');
	refresh (); wrefresh (field);	



	endwin ();
	return 0;
}
