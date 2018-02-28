#pragma once

#include <SFML/Graphics.hpp>
#include "magic.h"

namespace Pieces {
	extern sf::Sprite board[8][8];
	extern sf::Texture pieces[2][7];

	void init_textures();
	void init();
	sf::Sprite* find(sf::Vector2i);
	void draw(sf::RenderWindow&);
	bool move(sf::Sprite&, sf::Vector2f, sf::Vector2i);
}