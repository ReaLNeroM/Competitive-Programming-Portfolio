#include <iostream>
#include <vector>
#include <cstdlib> 

#include <SFML/Graphics.hpp>
#include "magic.h"
#include "helper.h"
#include "pieces.h"

int main(){
	sf::RenderWindow window(sf::VideoMode(Magic::size, Magic::size), "It Works!");
	window.setFramerateLimit(60);

	Pieces::init();

	sf::Texture board_image;
	board_image.loadFromFile("Images/board.png");
	sf::Sprite board;
	board.setTexture(board_image, true);
	board.setPosition(0.f, 0.f);
	board.setScale((double) Magic::size / board_image.getSize().x, 
					(double) Magic::size / board_image.getSize().y);

	int click_state = 0;
	sf::Sprite *held = NULL;
	sf::Vector2f held_coord(0, 0);

	while (window.isOpen()){
		sf::Event event;
		auto mouse_location = sf::Mouse::getPosition(window);
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			} else if(event.type == sf::Event::MouseButtonPressed){
				if(event.mouseButton.button == sf::Mouse::Left){
					click_state = 1;
					held = Pieces::find(mouse_location);
					held_coord = held->getPosition();
				}
			} else if(event.type == sf::Event::MouseButtonReleased){
				if(click_state != 1 or held == NULL){
					std::cerr << "Release with no press" << '\n';
					return -1;
				}

				Pieces::move(*held, held_coord, Helper::get_indices(mouse_location));
				// held->setPosition(sf::Vector2f(Helper::get_location(sf::Vector2i(mouse_location.x, mouse_location.y))));

				click_state = 2;
				held = NULL;
			}
		}

		if(click_state == 1){
			if(held == NULL){
				std::cerr << "Impossible" << '\n';
				return -1;
			}

			held->setPosition(mouse_location.x - Magic::cell_size / 2.0, mouse_location.y - Magic::cell_size / 2.0);
		}

		window.draw(board);
		Pieces::draw(window);

		window.display();
	}

	return 0;
}