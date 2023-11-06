#include <ncurses/curses.h>
#include "menu.hpp"

int main (void){

	initscr ();
	noecho ();
	cbreak ();


	WINDOW *win = newwin (LINES/2, COLS/2, LINES/4, COLS/4);
	box (win, 0, 0);

	Menu menus[3] = {
		Menu ("File", 'f'),
		Menu ("Config", 'c'),
		Menu ("Misc", 'm'),
	};

	MenuBar menu_bar (win, menus, 3);	

	menu_bar.draw();	

	int ch;
	while ( (ch = wgetch (win)) ){
		menu_bar.handle_trigger(ch);
		menu_bar.draw();
	}




	endwin ();
	return 0;
}

