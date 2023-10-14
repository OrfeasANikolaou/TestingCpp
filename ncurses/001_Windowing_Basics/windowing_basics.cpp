#include <ncurses.h>
#include <ncurses/curses.h>
WINDOW* make_ok_layout(int const, int const);
int main(void){
	initscr();
	raw(); 		//explicit declaration so interrupts don't work
	noecho();	// when typing nothing gets printed on the screen	
	//cbreak(); // default behaviour, but nice to explicitly declare it if going to use it 
						// useful for testing
	
	int height, width, start_y, start_x;
	// height width are in line numbers

	mvprintw(19, 103, "WINDOW 2 OK");
	mvprintw(24, 103, "WINDOW 3 OK");
	refresh();
	// things on screen should go before windows since they break them

	height = 5; width = 20; start_y = 5; start_x = 100;
	WINDOW* win1 = newwin(height, width, start_y, start_x); 
	box(win1, 0, 0);	//box(win, COL, ROW) shows the char you want to use for left_right, upper_lower
										//0, 0 for COL ROW make it the default, which looks pretty nice 
	//	wborder(WINDOW*, left, right, top, bot, left_top_corner, right_top_corner, l_b_c, r_b_c);
	//	wborder(win1, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'); WOW THIS WAS SO UGLY
	mvwprintw(win1,2, 7,"Hello");	

	// refresh() makes terminal contents appear 					 (refreshes terminal)
	// wrefresh(win) makes contents of window appear 			 (refreshes wi1)	
	// must use wrefresh() for a window, refresh() won't do it
	wrefresh(win1);

	WINDOW* win2 = newwin(3, 6, 20, 105);
 	mvwprintw(win2, 1, 2, "OK");
	wborder(win2, '[', ']', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(win2);	
	
	WINDOW* win3 = make_ok_layout(25, 105);
	wmove(win3, 0, 0);
	wrefresh(win3);
	for (size_t i = 0; i < 1000000000; ++i);
	wprintw(win3, " BREAKWINDOW  :D");	
	wrefresh(win3);
	
	getchar();	
	endwin();
	return 0;
}


WINDOW* make_ok_layout(int const start_y, int const start_x){
	WINDOW* w = newwin(3, 6, start_y, start_x);	
	mvwprintw(w, 1, 2, "OK");
	wborder(w, '[', ']', ' ', ' ', ' ', ' ', ' ', ' ');
	return w;
}
