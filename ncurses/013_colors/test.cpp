#include <ncurses.h>
#include <iostream>
int main(void){
	initscr();
	start_color();
	printw("n. COLORS: %d\nn.COLOR PAIRS: %d", COLORS, COLOR_PAIRS);
	getch();
	endwin();
	return 0;
}
