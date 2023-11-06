#include <ncurses/curses.h>
void unhilight_opts (WINDOW*);
int main (void){

	initscr ();
	noecho ();
	cbreak ();

	int yMax, xMax;
	getmaxyx (stdscr, yMax, xMax);

	WINDOW *win = newwin (yMax/2, xMax/2, yMax/4, xMax/4);
	box (win, 0, 0);

	mvwprintw (win, 0, 2, "File");
	mvwprintw (win, 0, 7, "Config");
	mvwprintw (win, 0, 14, "Misc");

	int ch;
	while ( (ch = wgetch (win)) ){
		switch (ch){
			case 'f': case 'F':
				unhilight_opts (win);
				wattron (win, A_STANDOUT);
				mvwprintw (win, 0, 2, "File");
				wattroff (win, A_STANDOUT);
				break;	
			case 'c': case 'C':
				unhilight_opts (win);
				wattron (win, A_STANDOUT);
				mvwprintw (win, 0, 7, "Config");
				wattroff (win, A_STANDOUT);
				break;	
			case 'm': case 'M':
				unhilight_opts (win);
				wattron (win, A_STANDOUT);
				mvwprintw (win, 0, 14, "Misc");
				wattroff (win, A_STANDOUT);
				break;
			default:
				unhilight_opts (win);
				break;	
		}		
		mvwprintw(win, 5, 1, "%d", LINES);
		mvwprintw(win, 6, 1, "%d", COLS);
	}




	endwin ();
	return 0;
}

void unhilight_opts (WINDOW* w){


	mvwprintw (w, 0, 2, "File");
	mvwprintw (w, 0, 7, "Config");
	mvwprintw (w, 0, 14, "Misc");
	

}
