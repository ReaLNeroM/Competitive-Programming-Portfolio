#include "piece.h"

namespace Piece {
	Base::Base(){}

	Base::Base(int newPieceType, Magic::color newPieceColor, sf::Vector2i newPos){
		pieceType = newPieceType;
		pieceColor = newPieceColor;
		cleared = false;
		boardPos = newPos;
		pieceTexture = &Magic::pieceTextures[pieceColor][newPieceType];

		setSprite(sf::Vector2f((double) Magic::cellSize / pieceTexture->getSize().x, 
							   (double) Magic::cellSize / pieceTexture->getSize().y), 
							   sf::Vector2f(newPos.x * Magic::cellSize, newPos.y * Magic::cellSize));
	}

	Magic::color Base::getColor(){
		return pieceColor;
	}

	void Base::setType(int newPieceType){
		pieceType = newPieceType;
	}

	void Base::setPosition(sf::Vector2i newPos){
		pieceSprite.setPosition(sf::Vector2f(newPos * Magic::cellSize));
		boardPos = newPos;
	}

	void Base::setSprite(sf::Vector2f scale, sf::Vector2f spritePos){
		pieceSprite.setTexture(*pieceTexture);
		pieceSprite.setScale(scale);
		pieceSprite.setPosition(spritePos);
	}


	bool Base::checkDestroyed(){
		return cleared;
	}

	void Base::setDestroyed(){
		cleared = true;
		pieceColor = Magic::color::none;
	}

	void Base::setSpritePosition(sf::Vector2f newPos){
		pieceSprite.setPosition(newPos);
	}

	void Base::draw(sf::RenderWindow& window){
		if(cleared)
			return;

		window.draw(pieceSprite);
	}

	bool Base::attemptMove(Piece::Base board[][8], sf::Vector2i newPos){
		if(!Helper::withinBounds(newPos) or boardPos == newPos or board[newPos.y][newPos.x].pieceColor == pieceColor){
			pieceSprite.setPosition(sf::Vector2f(boardPos * Magic::cellSize));
			return false;
		}

		switch (pieceType) {
		case 1:
			if (!pawnValidateMove(board, newPos)){
				pieceSprite.setPosition(sf::Vector2f(boardPos * Magic::cellSize));
				return false;
			}	
			break;
		case 2:
			if (!knightValidateMove(board, newPos)){
				pieceSprite.setPosition(sf::Vector2f(boardPos * Magic::cellSize));
				return false;
			}	
			break;
		case 3:
			if (!bishopValidateMove(board, newPos)){
				pieceSprite.setPosition(sf::Vector2f(boardPos * Magic::cellSize));
				return false;
			}	
			break;
		case 4:
			if (!rookValidateMove(board, newPos)){
				pieceSprite.setPosition(sf::Vector2f(boardPos * Magic::cellSize));
				return false;
			}	
			break;
		case 5:
			if (!queenValidateMove(board, newPos)){
				pieceSprite.setPosition(sf::Vector2f(boardPos * Magic::cellSize));
				return false;
			}	
			break;
		case 6:
			if (!kingValidateMove(board, newPos)){
				pieceSprite.setPosition(sf::Vector2f(boardPos * Magic::cellSize));
				return false;
			}	
			break;
		}

		if(pieceType == 1 and (newPos.y == 0 or newPos.y == Magic::boardSize - 1)){
			pawnUpgrade();
		}

		sf::Vector2i prevPos = boardPos;

		firstMove = false;
		pieceSprite.setPosition(sf::Vector2f(newPos * Magic::cellSize));
		boardPos = newPos;

		board[newPos.y][newPos.x].setDestroyed();

		std::swap(board[prevPos.y][prevPos.x], board[newPos.y][newPos.x]);

		return true;
	}

	void Base::pawnUpgrade(){
		std::cout << "What piece would you like to upgrade to? (1 for a knight, 2 for a bishop, 3 for a rook, and 4 for a queen)" << std::endl;
		int x;
		std::cin >> x;

		if(x <= 0 or x >= 5){
			std::cerr << "INVALID, ASSUMING QUEEN" << std::endl;
			x = 4;
		}

		x++;

		*this = Base(x, pieceColor, boardPos);
	}

	bool Base::pawnValidateMove(Piece::Base board[][8], sf::Vector2i newPos){
		int step = 0;
		if(pieceColor == Magic::color::black){
			step = 1;
		} else {
			step = -1;
		}

		if(boardPos.x == newPos.x){
			if(boardPos.y + step == newPos.y and board[newPos.y][newPos.x].checkDestroyed()){
				return true;
			} else if(firstMove and boardPos.y + 2 * step == newPos.y and board[boardPos.y + step][boardPos.x].checkDestroyed() and
																			board[boardPos.y + 2 * step][boardPos.x].checkDestroyed()){
				return true;
			}
		} else if(boardPos.x - 1 == newPos.x and boardPos.y + step == newPos.y and !board[newPos.y][newPos.x].checkDestroyed()){
			return true;
		} else if(boardPos.x + 1 == newPos.x and boardPos.y + step == newPos.y and !board[newPos.y][newPos.x].checkDestroyed()){
			return true;
		}
		//TODO: handle en-passant

		return false;
	}

	bool Base::knightValidateMove(Piece::Base board[][8], sf::Vector2i newPos){
		sf::Vector2i newPosCopy = newPos - boardPos;
		int a = std::abs(newPosCopy.x), b = std::abs(newPosCopy.y);

		if((a == 2 and b == 1) or (a == 1 and b == 2)){
			return true;
		}

		return false;
	}

	bool Base::bishopValidateMove(Piece::Base board[][8], sf::Vector2i newPos){
		if(boardPos.x + boardPos.y != newPos.x + newPos.y and std::abs(boardPos.x - boardPos.y) != std::abs(newPos.x - newPos.y)){
			return false;
		}

		sf::Vector2i tempPos = boardPos;

		while(tempPos != newPos){
			if(tempPos.x < newPos.x){
				tempPos.x++;
			} else if(tempPos.x > newPos.x){
				tempPos.x--;
			}
			if(tempPos.y < newPos.y){
				tempPos.y++;
			} else if(tempPos.y > newPos.y){
				tempPos.y--;
			}

			if(tempPos != newPos and !board[tempPos.y][tempPos.x].checkDestroyed()){
				return false;
			}
		}

		return true;
	}
	
	bool Base::rookValidateMove(Piece::Base board[][8], sf::Vector2i newPos){
		if(boardPos.x != newPos.x and boardPos.y != newPos.y){
			return false;
		}

		sf::Vector2i tempPos = boardPos;

		while(tempPos != newPos){
			if(tempPos.x < newPos.x){
				tempPos.x++;
			} else if(tempPos.x > newPos.x){
				tempPos.x--;
			}
			if(tempPos.y < newPos.y){
				tempPos.y++;
			} else if(tempPos.y > newPos.y){
				tempPos.y--;
			}

			if(tempPos != newPos and !board[tempPos.y][tempPos.x].checkDestroyed()){
				return false;
			}
		}

		return true;
	}

	bool Base::queenValidateMove(Piece::Base board[][8], sf::Vector2i newPos){
		if(bishopValidateMove(board, newPos) or rookValidateMove(board, newPos)){
			return true;
		}

		return false;
	}
	
	bool Base::kingValidateMove(Piece::Base board[][8], sf::Vector2i newPos){
		sf::Vector2i newPosCopy = newPos - boardPos;
		int a = std::abs(newPosCopy.x), b = std::abs(newPosCopy.y);

		if(std::max(a, b) == 1){
			return true;
		}
		//handle castling

		return false;
	}
}
