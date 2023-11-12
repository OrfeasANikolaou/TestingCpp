#include <ncurses.h>
/* do stuff start colors etc */
#define COLOR_NEWCOLOR 8 // mexri 255
// 0 - 7 already taken
int main(){
init_color(COLOR_NEWCOLOR, 0-999, 0-999, 0-999);
init_pair(1, COLOR_NEWCOLOR, COLOR_WHITE);
attron(COLOR_PAIR(1));
//check terminal for COLORS and COLOR_PAIRS constants
}
