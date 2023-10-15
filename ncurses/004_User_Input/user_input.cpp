#include <ncurses.h>
#include <iostream>
int main(void){
	initscr();
	raw();
	noecho();
//	cbreak();
	
	int y, x;
	getmaxyx(stdscr, y, x);

	/* MKWINDOW AND SHOW IT */
	WINDOW* win = newwin (6, 25, 
												y-10, x/2-20);
	box(win, 0, 0);
	refresh(); 
	
	/* INIT CHOICES AND HL SETTINGS*/
	std::string choices[]  {"choice1", "choice2", "choice3", };
	size_t hl = 0;
	keypad(win, true);
	size_t choices_sz = sizeof(choices) / sizeof(std::string);
	
	while(1){
		/* prints choices, and highlights the one with hl index */
		for (size_t i = 0; i < choices_sz; ++i){
			if (i == hl) {	wattron(win, A_REVERSE); wattron(win, A_BLINK); }
			mvwprintw(win, i+1, 1, "%s", choices[i].c_str());
			wattroff(win, A_REVERSE);	wattroff(win, A_BLINK);
		}

		/* getchar to go up and down, doesn't exit the while loop if user inputs anything else */
		int c = wgetch(win);
		switch (c){
			case KEY_UP: case 'k': 
				--hl;
				if (hl > choices_sz-1) hl = 0; //size_t hl, (0, UINT64_MAX)
				break;
			case KEY_DOWN: case 'j':
				++hl;
				if (hl > choices_sz-1) hl = choices_sz-1;
				break;
			default:
				// file.open() / std::cerrr << extended error log add wrong key pressed during selection ? TBD
				break;
		}
		
		/* except for the enter key, which selects the highlighted choice */
		if ( c == '\n' ){
				/* it also removes the hightlight on the choice, and adds an arrow */
				wattroff(win, A_REVERSE); wattroff(win, A_BLINK);
				mvwprintw(win, hl+1, 1, "%s <--", choices[hl].c_str());
			refresh(); wrefresh(win);
			break;
		}
	}
	/* do something with selected choice */	
	mvwprintw(win, 
						choices_sz+1,1, 
						"You entered: %s", choices[hl].c_str());
	wrefresh(win);



	getchar();
	endwin();

	return 0;
}
