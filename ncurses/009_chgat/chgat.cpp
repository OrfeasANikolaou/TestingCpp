#include <ncurses/curses.h>
#include <cstring>
#include <chrono>
#include <thread>

int main (void){
	initscr ();
	
	if ( !has_colors ()) return -1;
	
	start_color ();
	init_pair (1, COLOR_WHITE, COLOR_BLUE);
	init_pair (2, COLOR_WHITE, COLOR_RED);

//	int chgat(number of char, attribute, color_pair, NULL);
// 	chgat mvchgat wchgat mvwchgat 

	chgat (5, A_REVERSE, 0, NULL);
	move (1, 5);
	chgat(-1, A_REVERSE, 0, NULL); //until eol

	move (2,0);	
	chgat (1000000, A_REVERSE, 0, NULL); //again until eol

	mvprintw (1,10, "Testing"); // replaces the chgat attributes and color

	mvprintw (5, 20, "another test");
	mvchgat (5, 20, strlen ("another test"), A_REVERSE, 0, NULL); // puts the atts and colors 
																																// without replacing the text
	refresh();
	std::this_thread::sleep_for (std::chrono::seconds(1));	

	WINDOW* win = newwin (20,150, 
												LINES/2-10, COLS/2-75);
	box(win, 0, 0);
	
	for (size_t i = 0; i < LINES; ++i){
		move (i, 0);
		chgat (-1, A_NORMAL, 1, NULL);
	}

	refresh ();
	wrefresh (win);
	getch ();
	endwin ();
	return 0;
}
