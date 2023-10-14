#include <ncurses.h>
#include <iostream>
int main(void){
	//init screen
	//set up memory and clear screen
	initscr();
	
	//fflush()
	
	refresh();
	/*
			[0,0][0,1][0,2]...
			[1,0][1,1][1,2]...
			[2,0][2,1][2,2]...
			.			.		.
			.			.		.
	 */
	// move(y,x)
	// y = number of enters
	// x = number of spaces
	// ....................away from [0,0]
	// move(ROW, COL);	
	move(20, 120);

	printw("Hello World!\n");
	std::string str = "ncurses rocks!";	
	
	move(21, 120);
	
	printw("%s", str.c_str());
	getch();

	refresh();
	
	endwin();
	//free memory and end ncurses
	return 0;
}
