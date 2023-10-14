#include <ncurses.h>
#include <iostream>
#include <ncurses/curses.h>
/* ATTRIBUTES
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
	raw();
	noecho();
/*	
	printw("This is a test\n");
	
	attron(A_NORMAL);
	printw("This is a test\n");
	attroff(A_NORMAL);

	attron(A_STANDOUT);
	printw("This is a test\n");
	attroff(A_STANDOUT);


	attron(A_REVERSE);
	printw("This is a test\n");
	attroff(A_REVERSE);

	attron(A_BLINK);
	printw("This is a test\n");
	attroff(A_BLINK);

	attron(A_DIM);
	printw("This is a test\n");
	attroff(A_DIM);

	attron(A_BOLD);
	printw("This is a test\n");
	attroff(A_BOLD);
*/
	
	if(!has_colors()){
		printw("Term does not have colors, press any key to exit.");
		refresh();
		getchar();
		endwin();
		std::cerr << "ERROR: TERMINAL NOT SUPPORTING COLORS" << std::endl; 
		return -1;
	}
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN); //pair ID, Foreground, Background
	
	attron(COLOR_PAIR(1));
	printw("Look, mom! I'm on the telly!\n");
	attroff(COLOR_PAIR(1));
	refresh();

	// maybe could add this as a menu option for the project
	if(can_change_color()){
		printw("Can change color\n");
//		init_color(COLOR_some_color, red (0,999), green (0, 999), blue (0,999);
	}	
	refresh();	
	getchar();
	endwin();
	return 0;
}
