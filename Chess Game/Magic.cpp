#include "magic.h"

namespace Magic {
	const int size = 720;
	const int board_size = 8;
	const int cell_size = size / board_size;
	const int pieces = 7;

	int initial[][board_size] = {
	    { 2,  3,  4,  5,  6,  4,  3,  2},
	    { 1,  1,  1,  1,  1,  1,  1,  1},
	    { 0,  0,  0,  0,  0,  0,  0,  0},
	    { 0,  0,  0,  0,  0,  0,  0,  0},
	    { 0,  0,  0,  0,  0,  0,  0,  0},
	    { 0,  0,  0,  0,  0,  0,  0,  0},
	    {-1, -1, -1, -1, -1, -1, -1, -1},
	    {-2, -3, -4, -5, -6, -4, -3, -2}
	};
	
	std::string location[][pieces] = {
		{"Images/blank.png", "Images/white_pawn.png", "Images/white_rook.png", "Images/white_knight.png", "Images/white_bishop.png", "Images/white_queen.png", "Images/white_king.png"},
		{"Images/blank.png", "Images/black_pawn.png", "Images/black_rook.png", "Images/black_knight.png", "Images/black_bishop.png", "Images/black_queen.png", "Images/black_king.png"}
	};
}