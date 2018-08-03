#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "magic.h"
#include "helper.h"

namespace Piece {
	class Base {
	protected:
		Magic::color pieceColor = Magic::color::none;
		int pieceType = 0;
		bool cleared = true;
		bool firstMove = true;
		sf::Sprite pieceSprite;
		sf::Vector2i boardPos;
		sf::Texture* pieceTexture = NULL;
	public:
		Base();
		Base(int, Magic::color, sf::Vector2i);
		Magic::color getColor();
		void setType(int);
		bool attemptMove(Piece::Base board[][8], sf::Vector2i);
		void setPosition(sf::Vector2i);
		void reloadTexture();
		void setSprite(sf::Vector2f, sf::Vector2f);
		void setSpritePosition(sf::Vector2f);
		void setDestroyed();
		bool checkDestroyed();
		void draw(sf::RenderWindow&);

		void pawnUpgrade();
		bool pawnValidateMove(Piece::Base board[][8], sf::Vector2i);
		bool knightValidateMove(Piece::Base board[][8], sf::Vector2i);
		bool bishopValidateMove(Piece::Base board[][8], sf::Vector2i);
		bool rookValidateMove(Piece::Base board[][8], sf::Vector2i);
		bool queenValidateMove(Piece::Base board[][8], sf::Vector2i);
		bool kingValidateMove(Piece::Base board[][8], sf::Vector2i);
	};
}