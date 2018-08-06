#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "magic.h"
#include "helper.h"

namespace Piece {
	class Base {
	public:
		Magic::color pieceColor = Magic::color::none;
		Magic::type pieceType;
		bool cleared;
		int moveId;
		bool pawnTwoRowJump;
		sf::Sprite pieceSprite;
		sf::Vector2i boardPos;
		sf::Texture* pieceTexture;
		Base();
		Base(Magic::color, Magic::type, sf::Vector2i);
		Magic::color getColor();
		sf::Vector2i getBoardPos();
		void clearTexture();
		void reloadTexture();
		void setPosition(sf::Vector2i);
		void setSprite(sf::Vector2f, sf::Vector2f);
		void setSpritePosition(sf::Vector2f);
		void setDestroyed();
		void revertDestroyed();
		bool checkDestroyed();
		void draw(sf::RenderWindow&);
	};
}