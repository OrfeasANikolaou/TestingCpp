#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <ncurses.h>
#endif

class Player{
	public:
		Player (WINDOW* cw, int y, int x, char c);

		void mv_l (void);
		void mv_r (void);
		void mv_u (void);
		void mv_d (void);
		int get_mv (void);
		void display (void);
	private:
		int loc_y, loc_x, max_y, max_x;
		char ID;
		WINDOW* window;
};
