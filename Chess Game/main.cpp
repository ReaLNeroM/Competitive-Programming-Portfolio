#include <iostream>
#include <vector>
#include <cstdlib> 

#include <SFML/Graphics.hpp>
#include "magic.h"
#include "helper.h"
#include "piece.h"
#include "board.h"
#include "gameHandler.h"
#include "chessAI.h"

 int main(){
	sf::RenderWindow window(sf::VideoMode(Magic::size, Magic::size), "It Works!");
	window.setFramerateLimit(60);

	BoardStructure::init();

	sf::Texture boardImage;
	boardImage.loadFromFile(Magic::boardString);

	sf::Sprite board;
	board.setTexture(boardImage, true);
	board.setPosition(0.f, 0.f);
	board.setScale((double) Magic::size / boardImage.getSize().x, 
					(double) Magic::size / boardImage.getSize().y);

	int clickState = 0;
	Piece::Base *held = NULL;

	auto x = AI::getBestMove();

	while (window.isOpen()){
		sf::Event event;
		auto mouseLocation = sf::Mouse::getPosition(window);

		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			} else if(event.type == sf::Event::MouseButtonPressed){
				if(event.mouseButton.button == sf::Mouse::Left){
					held = BoardStructure::find(mouseLocation);

					if(held != NULL){
						clickState = 1;
					}
				} else if(event.mouseButton.button == sf::Mouse::Right and held == NULL){
					BoardStructure::undoMove();
					x = AI::getBestMove();
				}
			} else if(event.type == sf::Event::MouseButtonReleased){
				if(clickState != 1 or held == NULL){
					continue;
				}

				if(GameHandler::attemptMove(*held, Helper::getIndices(mouseLocation), true)){
					x = AI::getBestMove();
					GameHandler::checkWin();
				}			

				clickState = 2;
				held = NULL;
			}
		}


		window.draw(board);

		if(x != std::pair<sf::Vector2i,sf::Vector2i>{{-1, -1}, {-1, -1}}){
			// GameHandler::attemptMove(BoardStructure::board[x.first.y][x.first.x], x.second, false);
			sf::Vector2f startPos = sf::Vector2f(x.first.x * Magic::cellSize, x.first.y * Magic::cellSize);
			sf::Vector2f nextPos = sf::Vector2f(x.second.x * Magic::cellSize, x.second.y * Magic::cellSize);
			sf::CircleShape startPosCircle(Magic::cellSize / 2.0);
			sf::CircleShape nextPosCircle(Magic::cellSize / 2.0);
			startPosCircle.setFillColor(sf::Color::Green);
			nextPosCircle.setFillColor(sf::Color::Red);
			startPosCircle.setPosition(startPos);
			nextPosCircle.setPosition(nextPos);
			window.draw(startPosCircle);
			window.draw(nextPosCircle);
		}

		if(clickState == 1){
			if(held == NULL){
				std::cerr << "No unit selected" << '\n';
				return -1;
			}

			held->cleared = true;

			sf::Sprite x;
			x.setPosition(sf::Vector2f(mouseLocation.x - Magic::cellSize / 2.0, 
												 mouseLocation.y - Magic::cellSize / 2.0));
			x.setScale(sf::Vector2f((double) Magic::cellSize / Magic::pieceTextures[held->pieceColor][held->pieceType].getSize().x, 
											   (double) Magic::cellSize / Magic::pieceTextures[held->pieceColor][held->pieceType].getSize().y));
   			x.setTexture(Magic::pieceTextures[held->pieceColor][held->pieceType]);
			window.draw(x);
		}

		BoardStructure::drawPieces(window);

		window.display();

		if(clickState == 1 and held != NULL){
			held->cleared = false;
		}
	}

	return 0;
}
