#include "menu.hpp"
#include <ncurses/curses.h>
#include <string>
//MENU
Menu::Menu (std::string txt, int trgr) : text (txt), trigger (trgr) {}


//MENUBAR

MenuBar::MenuBar (WINDOW* w, Menu* m, size_t n) : win (w), menus (m), num_menus (n), 
																									selected_menu(-1) {
	int curr_pos = 2; // so it looks nice
	
	for (int i = 0; i < this->num_menus; ++i){
		this->menus[i].start_x = curr_pos;
		curr_pos += this->menus[i].text.length() + 1;
	}
}  


void MenuBar::draw (void) const {

	for (int i = 0; i < this->num_menus; ++i){
		int temp_x = this->menus[i].start_x;
		std::string temp_txt = this->menus[i].text;
		if (selected_menu == i)	wattron (win, A_STANDOUT);
		mvwprintw (this->win, 0, temp_x, "%s", temp_txt.c_str() );
		wattroff (win, A_STANDOUT);
	}

}

void MenuBar::handle_trigger (int trigger) {
	
	for (int i = 0; i < this->num_menus; ++i){
		if ( trigger == this->menus[i].trigger ){
			this->selected_menu = i;	
		}
	}

}
