#include <ncurses/curses.h>

int main (void){
	initscr ();
	noecho ();
	refresh (); // tends to fix some unexpected issues
		

	printw("Hello world!");	
	mvprintw (1, 0,
						"Goodbye, world!");
	move (0, 1);
	getch ();
	/*w*/clrtoeol ();		
	getch ();

	for (int i = 2; i < 6; ++i) mvprintw (i*2, 0, 
																				"Everything below should clear");
	move (4, 8);
	getch ();
	/*w*/clrtobot ();
	getch ();
	erase ();	
	
	
	for (int i = 0; i < 6; ++i) mvprintw (i, i*i,
																				"Hello world!");
	getch ();
	/*w*/erase ();	// soft clear	
	getch ();
	
	
	for (int i = 0; i < 6; ++i) mvprintw (i, i*i,
																				"Hello world!");
	getch ();
	/*w*/clear ();	// hard clear
	getch ();


	getch ();
	endwin ();

	return 0;
}
