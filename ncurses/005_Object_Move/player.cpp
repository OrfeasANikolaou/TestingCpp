#include "./headers/player.hpp"
#include <ncurses.h>
Player::Player (WINDOW* cw, int y, int x, char c){
	this->window = cw;
	this->loc_y = y; this->loc_x = x;
	this->ID = c;
	getmaxyx (this->window, this->max_y, this->max_x);
	keypad (this->window, true);	
}

void Player::mv_l (void){
	mvwaddch (this->window, 
						this->loc_y, this->loc_x, 
						' ');
	if (!(--this->loc_x)) this->loc_x = 1;
}
void Player::mv_r (void){
	mvwaddch (this->window, 
						this->loc_y, this->loc_x, 
						' ');
	if (++this->loc_x == this->max_x - 1) this->loc_x = this->max_x - 2;
}
void Player::mv_u (void){
	mvwaddch (this->window, 
						this->loc_y, this->loc_x, 
						' ');
	if (!(--this->loc_y)) this->loc_y = 1;
}
void Player::mv_d (void){
	mvwaddch (this->window, 
						this->loc_y, this->loc_x, 
						' ');
	if (++this->loc_y == this->max_y - 1) this->loc_y = this->max_y - 2;
}
int Player::get_mv (void){
	int ret = wgetch (this->window);
	switch (ret){
		case KEY_LEFT: case 'h': 
			this->mv_l ();
			break;
		case KEY_RIGHT: case 'l': 
			this->mv_r ();
			break;
		case KEY_UP: case 'k': 
			this->mv_u ();
			break;
		case KEY_DOWN: case 'j': 
			this->mv_d ();
			break;
		default:
			// do some extended error log
			break;	
	}
	return ret;
}
void Player::display (void){
	//addch ()
	mvwaddch (this->window,
						this->loc_y, this->loc_x,
						this->ID);
}
