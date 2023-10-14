#include <ncurses.h>
#include <iostream>
int main(void){
/*
 * initscr()
 * refresh()
 * move(ROW, COL)
 * printw(printf parameters) scanw(scanf parameters) mvprinw(move() printw()) mvscanf(move() scanw())
 * endwin()
 */
	//init screen
	//set up memory and clear screen
	initscr();
	refresh();
	/*	[0,0][0,1][0,2]...
			[1,0][1,1][1,2]...
			[2,0][2,1][2,2]...
			.			.		.
	 */
	// move(y,x)
	// move(ROW, COL);	
	move(20, 120);
	printw("Hello World!\n");
	
	std::string str = "ncurses rocks!";	
	move(21, 120);
	printw("%s", str.c_str());
	
	move(24,100);
	printw("Enter character to view its int value in the ASCII table: ");
	refresh();
	int c = getch();

	// IN CASE THE END USER DECIDES TO PRESS THE ENTER KEY
	mvprintw(25,124, "\'");
	mvprintw(25,125, "%c", c);
	mvprintw(25,126, "\'");
	mvprintw(25,127, ": %d", c);

	mvprintw(0, 0, "If you notice this you are super-duper!");
	move(25,130);

	mvprintw(27,105, "Press any key to clear(), and again to exit");
	getch(); clear();
	
	refresh(); 
	getch();
	endwin();
	//free memory and end ncurses
	return 0;
}
