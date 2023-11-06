#include <ncurses/curses.h>
#include <string>
#ifndef _MENU_HPP
#define _MENU_HPP

class Menu{
	friend class MenuBar;
	public:
		Menu (std::string, int trigger); 
		
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
