#include "menu.hpp"
#include <ncurses/curses.h>
#include <string>
//MENU
Menu::Menu (std::string txt, int trgr, std::string* itms, int n_itms) : 
  text (txt), trigger (trgr), items(itms), num_items(n_itms), selected_item(0) {}


void Menu::select_next_item(void){
  ++this->selected_item;
  if (this->selected_item >= this->num_items) this->selected_item = 0;
}
void Menu::select_prev_item(void){
  --this->selected_item;
  if (this->selected_item < 0) this->selected_item = num_items - 1;
}

//MENUBAR

MenuBar::MenuBar (WINDOW* w, Menu* m, size_t n) : win (w), menus (m), num_menus (n), 
                                                  selected_menu(-1) {
  int curr_pos = 2; // so it looks nice

  for (int i = 0; i < this->num_menus; ++i){
    this->menus[i].start_x = curr_pos;
    curr_pos += this->menus[i].text.length() + 1;
  }
  int yMax, xMax, yBeg, xBeg;
  getmaxyx(this->win, yMax, xMax);
  getbegyx(this->win, yBeg, xBeg);
  this->menu_win = newwin(yMax - 2, xMax - 2, yBeg + 1, xBeg + 1); 
  keypad(this->menu_win, true);
  wrefresh(this->menu_win);
}  


void MenuBar::draw (void) {

  for (int i = 0; i < this->num_menus; ++i){
    draw_menu(menus[i], selected_menu == i);
  }
  selected_menu = -1;
}

void MenuBar::handle_trigger (int trigger) {

  for (int i = 0; i < this->num_menus; ++i){
    if ( trigger == this->menus[i].trigger ){
      this->selected_menu = i;
    }
  }

}

void MenuBar::reset(void){

  for (int i = 0; i < this->num_menus; ++i){
    int temp_x = this->menus[i].start_x;
    std::string temp_txt = this->menus[i].text;
    mvwprintw (this->win, 0, temp_x, "%s", temp_txt.c_str() );
  }
  wrefresh(this->win);
}

void MenuBar::draw_menu(Menu menu, bool is_selected){
  int start_x = menu.start_x;
  std::string text = menu.text;
  if (is_selected) wattron(this->win, A_STANDOUT);
  mvwprintw (this->win, 0, start_x, "%s", text.c_str());
  wattroff (this->win, A_STANDOUT);
  wrefresh (this->win);
	int ch;
  draw_menu_items(menu);
  wrefresh(menu_win);
  while (is_selected &&
        (ch = wgetch(this->menu_win) )){
    switch (ch){
      case KEY_UP: 
        menu.select_prev_item();
        break;
      case KEY_DOWN: 
        menu.select_next_item();
        break;
      default:
				is_selected = false;
        break;
    }
    draw_menu_items(menu);
  }
  werase(menu_win);
	wrefresh(menu_win);
	reset();
}

void MenuBar::draw_menu_items(Menu menu){
  int xMax = getmaxx(menu_win);
  for (int i = 0; i < menu.num_items; ++i){
    mvwprintw (menu_win, i, 0, "%s", menu.items[i].c_str());
    if (menu.selected_item == i){
      mvwchgat (menu_win, i, 0, xMax, A_NORMAL, 1, NULL); 
                                      //attr   color NULL
    }
    else {
      mvwchgat (menu_win, i, 0, xMax, A_STANDOUT, 0, NULL); 
    }
  }
}

