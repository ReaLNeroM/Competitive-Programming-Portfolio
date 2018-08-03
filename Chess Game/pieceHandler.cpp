#include "pieceHandler.h"

namespace PieceHandler {
	Piece::Base board[8][8];

	void initTextures(){
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < Magic::pieces; j++){
				Magic::pieceTextures[i][j].loadFromFile(Magic::location[i][j]);
				Magic::pieceTextures[i][j].setSmooth(true);
			}
		}
	}

	void init(){
		initTextures();

		for(int i = 0; i < Magic::boardSize; i++){
			for(int j = 0; j < Magic::boardSize; j++){
				Magic::color assignedColor = Magic::color::none;
				
				if(Magic::initial[i][j] > 0){
					assignedColor = Magic::color::white;
				} else if(Magic::initial[i][j] < 0){
					assignedColor = Magic::color::black;
				}

				int pieceType = std::abs(Magic::initial[i][j]);
				board[i][j].setPosition(sf::Vector2i(j, i));

				if(assignedColor != Magic::color::none){
					board[i][j] = Piece::Base(pieceType, assignedColor, sf::Vector2i(j, i));
				}
			}
		}
	}

	Piece::Base* find(sf::Vector2i v){
		v = Helper::getIndices(v);
		if(Helper::withinBounds(v)){
			return &board[v.y][v.x];
		}

		return NULL;
	}

	void draw(sf::RenderWindow &window, Magic::color currSide){
		for(int i = 0; i < Magic::boardSize; i++){
			for(int j = 0; j < Magic::boardSize; j++){
				if(!board[i][j].checkDestroyed()){
					if(currSide == board[i][j].getColor()){
						sf::RectangleShape rectangle(sf::Vector2f(Magic::cellSize, Magic::cellSize));
						rectangle.setPosition(sf::Vector2f(j * Magic::cellSize, i * Magic::cellSize));
						rectangle.setFillColor(sf::Color(0, 0, 0, 0));
						rectangle.setOutlineColor(sf::Color(127, 255, 0, 255));
						rectangle.setOutlineThickness(12.5);
						window.draw(rectangle);
					}

					board[i][j].draw(window);
				}
			}
		}
	}
}
