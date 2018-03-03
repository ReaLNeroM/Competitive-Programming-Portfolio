#include "magic.h"

namespace Magic {
	const int size = 1920;
	const int board_size = 8;
	const int cell_size = size / board_size;
	const int pieces = 7;

	int initial[][board_size] = {
	    {-2, -3, -4, -5, -6, -4, -3, -2},
	    {-1, -1, -1, -1, -1, -1, -1, -1},
	    { 0,  0,  0,  0,  0,  0,  0,  0},
	    { 0,  0,  0,  0,  0,  0,  0,  0},
	    { 0,  0,  0,  0,  0,  0,  0,  0},
	    { 0,  0,  0,  0,  0,  0,  0,  0},
	    { 1,  1,  1,  1,  1,  1,  1,  1},
	    { 2,  3,  4,  5,  6,  4,  3,  2}
	};

	std::string board_string = "img/board.png";
	
	std::string location[][pieces] = {
		{"img/blank.png", 
			"img/white_pawn.png", 
			"img/white_rook.png", 
			"img/white_knight.png", 
			"img/white_bishop.png", 
			"img/white_queen.png",
			 "img/white_king.png"},
		{"img/blank.png", 
			"img/black_pawn.png", 
			"img/black_rook.png", 
			"img/black_knight.png", 
			"img/black_bishop.png", 
			"img/black_queen.png", 
			"img/black_king.png"}
	};
}