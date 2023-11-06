#include <ncurses/curses.h>
#include <string>
#ifndef _MENU_HPP
#define _MENU_HPP

class Menu{
	public:
		Menu (std::string, int trigger); 
		
		//setters
		void SET_start_x (int);

		//getters
		std::string GET_text (void) const;
		int GET_start_x (void) const;
		int GET_trigger (void) const;
	private:
		int start_x;
		std::string text;
		int trigger;
};

class MenuBar{
	public:
		MenuBar (WINDOW*, Menu*, size_t );
		void draw (void) const;
		void handle_trigger (int );
	private:
		WINDOW* win;
		Menu *menus;
		int num_menus;
		int selected_menu;
};

#endif
