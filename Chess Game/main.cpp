#include <iostream>
#include <vector>
#include <cstdlib> 

#include <SFML/Graphics.hpp>
#include "magic.h"
#include "helper.h"
#include "piece.h"
#include "pieceHandler.h"

int main(){
	sf::RenderWindow window(sf::VideoMode(Magic::size, Magic::size), "It Works!");
	window.setFramerateLimit(60);

	PieceHandler::init();

	sf::Texture boardImage;
	boardImage.loadFromFile(Magic::boardString);

	sf::Sprite board;
	board.setTexture(boardImage, true);
	board.setPosition(0.f, 0.f);
	board.setScale((double) Magic::size / boardImage.getSize().x, 
					(double) Magic::size / boardImage.getSize().y);

	int clickState = 0;
	Piece::Base *held = NULL;

	Magic::color side = Magic::color::white;

	while (window.isOpen()){
		sf::Event event;
		auto mouseLocation = sf::Mouse::getPosition(window);

		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			} else if(event.type == sf::Event::MouseButtonPressed){
				if(event.mouseButton.button == sf::Mouse::Left){
					held = PieceHandler::find(mouseLocation);

					if(held->getColor() != side){
						held = NULL;
					} else {
						clickState = 1;
					}
				}
			} else if(event.type == sf::Event::MouseButtonReleased){
				if(clickState != 1 or held == NULL){
					continue;
				}

				if(held->attemptMove(PieceHandler::board, Helper::getIndices(mouseLocation))){
					if(side == Magic::color::white){
						side = Magic::color::black;
					} else {
						side = Magic::color::white;
					}
				}

				clickState = 2;
				held = NULL;
			}
		}

		if(clickState == 1){
			if(held == NULL){
				std::cerr << "No unit selected" << '\n';
				return -1;
			}

			held->setSpritePosition(sf::Vector2f(mouseLocation.x - Magic::cellSize / 2.0, 
												 mouseLocation.y - Magic::cellSize / 2.0));
		}

		window.draw(board);
		PieceHandler::draw(window, side);
		if(held != NULL){
			held->draw(window);
		}

		window.display();
	}

	return 0;
}