#include "piece.h"

namespace Piece {
	Base::Base(){}

	Base::Base(Magic::color newPieceColor, Magic::type newPieceType, sf::Vector2i newPos){
		pieceColor = newPieceColor;
		pieceType = newPieceType;
		cleared = false;
		moveId = 0;
		boardPos = newPos;
		pawnTwoRowJump = false;
		pieceTexture = &Magic::pieceTextures[pieceColor][newPieceType];

		setSprite(sf::Vector2f((double) Magic::cellSize / pieceTexture->getSize().x, 
							   (double) Magic::cellSize / pieceTexture->getSize().y), 
							   sf::Vector2f(newPos.x * Magic::cellSize, newPos.y * Magic::cellSize));
	}

	Magic::color Base::getColor(){
		return pieceColor;
	}

	sf::Vector2i Base::getBoardPos(){
		return boardPos;
	}

	void Base::clearTexture(){
		pieceSprite.setTexture(Magic::pieceTextures[Magic::color::none][0]);
	}

	void Base::reloadTexture(){
		pieceSprite.setTexture(*pieceTexture);
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

	void Base::setSpritePosition(sf::Vector2f newPos){
		pieceSprite.setPosition(newPos);
	}

	void Base::setDestroyed(){
		cleared = true;
		clearTexture();
	}

	void Base::revertDestroyed(){
		cleared = false;
		reloadTexture();
	}

	bool Base::checkDestroyed(){
		return cleared or pieceColor == Magic::color::none;
	}

	void Base::draw(sf::RenderWindow& window){
		if(cleared)
			return;

		window.draw(pieceSprite);
	}
}
