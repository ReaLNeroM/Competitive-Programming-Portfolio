#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "helper.h"
#include "magic.h"
#include "piece.h"

namespace PieceHandler {
	extern Piece::Base board[8][8];

	void initTextures();
	void init();
	Piece::Base* find(sf::Vector2i);
	void draw(sf::RenderWindow&, Magic::color);
}