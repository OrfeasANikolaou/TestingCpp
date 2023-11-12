#include <ncurses/curses.h>
#include "menu.hpp"

int main (void){

  initscr ();
  noecho ();
  cbreak ();
  if (!has_colors ()) return -1;
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  WINDOW *win = newwin (LINES/2, COLS/2, LINES/4, COLS/4);
  box (win, 0, 0);

  std::string menu_file[] = {"opt1", "opt2", "opt3", "opt4"};
  std::string menu_config[] = {"opt5", "opt6"};
  std::string menu_misc[] = {"about", "help"};
  Menu menus[3] = {
    Menu ("File", 'f', menu_file, sizeof (menu_file) / sizeof (std::string)),
    Menu ("Config", 'c', menu_config, sizeof (menu_config) / sizeof (std::string)),
    Menu ("Misc", 'm', menu_misc, sizeof (menu_misc) / sizeof (std::string)),
  };

  MenuBar menu_bar (win, menus, 3);
  menu_bar.draw();
  int ch;
  while ( (ch = wgetch (win)) ){
    menu_bar.handle_trigger(ch);
    menu_bar.draw();
  }


  endwin ();
  return 0;
}


