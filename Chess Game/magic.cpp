#include "magic.h"

namespace Magic {
	const int size = 1920;
	const int boardSize = 8;
	const int cellSize = size / boardSize;
	const int pieces = 7;

	type initialType[][boardSize] = {
	    { rook , knight, bishop , queen , king , bishop, knight, rook  },
	    { pawn , pawn  , pawn   , pawn  , pawn , pawn  , pawn  , pawn  },
	    { blank, blank , blank  , blank , blank, blank , blank , blank },
	    { blank, blank , blank  , blank , blank, blank , blank , blank },
	    { blank, blank , blank  , blank , blank, blank , blank , blank },
	    { blank, blank , blank  , blank , blank, blank , blank , blank },
	    { pawn , pawn  , pawn   , pawn  , pawn , pawn  , pawn  , pawn  },
	    { rook , knight, bishop , queen , king , bishop, knight, rook  }
	};

	color initialColor[][boardSize] = {
		{black, black, black, black, black, black, black, black},
		{black, black, black, black, black, black, black, black},
		{none , none , none , none , none , none , none , none },
		{none , none , none , none , none , none , none , none },
		{none , none , none , none , none , none , none , none },
		{none , none , none , none , none , none , none , none },
		{white, white, white, white, white, white, white, white},
		{white, white, white, white, white, white, white, white}
	};

	std::string boardString = "img/board.png";
	std::string possibleMove = "img/highlight.png";
	
	int pieceValue[] = {
		0, 1, 3, 3, 5, 9, 1000
	};

	std::string location[][pieces] = {
		{"img/blank.png", 
			"img/white_pawn.png", 
			"img/white_knight.png", 
			"img/white_bishop.png", 
			"img/white_rook.png", 
			"img/white_queen.png",
			 "img/white_king.png"},
		{"img/blank.png", 
			"img/black_pawn.png", 
			"img/black_knight.png", 
			"img/black_bishop.png", 
			"img/black_rook.png", 
			"img/black_queen.png", 
			"img/black_king.png"}
	};

	sf::Texture pieceTextures[2][7];
}