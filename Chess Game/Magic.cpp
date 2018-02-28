#pragma once

namespace Magic {
	const int size = 720;
	const int board_size = 8;
	const int cell_size = size / board_size;

	int board[][board_size] = {
	    { 0,  0,  0,  0,  0,  0,  0,  0},
	    { 1,  1,  1,  1,  1,  1,  1,  1},
	    { 0,  0,  0,  0,  0,  0,  0,  0},
	    { 0,  0,  0,  0,  0,  0,  0,  0},
	    { 0,  0,  0,  0,  0,  0,  0,  0},
	    { 0,  0,  0,  0,  0,  0,  0,  0},
	    {-1, -1, -1, -1, -1, -1, -1, -1},
	    { 0,  0,  0,  0,  0,  0,  0,  0}
	};	
}