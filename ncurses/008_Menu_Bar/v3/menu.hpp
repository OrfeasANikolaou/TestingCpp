#include <ncurses/curses.h>
#include <string>
#ifndef _MENU_HPP
#define _MENU_HPP

class Menu{
  friend class MenuBar;
  public:
    Menu (std::string , int , std::string*, int ); 
    void select_next_item (void);
    void select_prev_item (void);
  private:
    int start_x;
    std::string text;
    int trigger;
    std::string* items;
    int num_items;
    int selected_item;
};

class MenuBar{
  public:
    MenuBar (WINDOW*, Menu*, size_t );
    void draw (void) ;
    void handle_trigger (int );
    void reset (void);
    void draw_menu (Menu , bool );
    void draw_menu_items (Menu );
  private:
    WINDOW* win;
    Menu *menus;
    int num_menus;
    int selected_menu;
    WINDOW* menu_win;
};

#endif
