#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace Magic {
	enum color {
		none = -1,
		white,
		black
	};

	extern const int size;
	extern const int boardSize;
	extern const int cellSize;
	extern const int pieces;

	extern int initial[8][8];
	
	extern std::string boardString;
	
	extern std::string location[2][7];
	extern sf::Texture pieceTextures[2][7];
}