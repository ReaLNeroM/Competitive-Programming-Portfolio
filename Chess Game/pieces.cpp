#include "helper.h"
#include <iostream>

namespace Pieces {
	sf::Sprite board[8][8];
	sf::Texture pieces[2][7];

	void init_textures(){
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < Magic::pieces; j++){
				pieces[i][j].loadFromFile(Magic::location[i][j]);
				pieces[i][j].setSmooth(true);
			}
		}
	}

	void init(){
		init_textures();

		for(int i = 0; i < Magic::board_size; i++){
			for(int j = 0; j < Magic::board_size; j++){
				sf::Texture* t = NULL;
				if(Magic::initial[i][j] == 0){
					t = &pieces[0][0];
				} else if(Magic::initial[i][j] > 0){
					t = &pieces[0][Magic::initial[i][j]];
				} else if(Magic::initial[i][j] < 0){
					t = &pieces[1][-Magic::initial[i][j]];
				}

				board[i][j].setTexture(*t);
				board[i][j].setScale((double) Magic::cell_size / t->getSize().x, 
										(double) Magic::cell_size / t->getSize().y);
				board[i][j].setPosition(sf::Vector2f(j * Magic::cell_size, i * Magic::cell_size));
			}
		}
	}

	sf::Sprite* find(sf::Vector2i v){
		v = Helper::get_indices(v);
		return &board[v.y][v.x];
	}

	void draw(sf::RenderWindow &window){
		for(int i = 0; i < Magic::board_size; i++){
			for(int j = 0; j < Magic::board_size; j++){
				if(!Helper::check_null_sprite(board[i][j], &pieces[0][0])){
					window.draw(board[i][j]);
				}
			}
		}
	}

	bool move(sf::Sprite& x, sf::Vector2f start, sf::Vector2i y){
		if(Helper::check_null_sprite(board[y.y][y.x], &pieces[0][0])){
			board[y.y][y.x].setPosition(start);
			x.setPosition(sf::Vector2f(y * Magic::cell_size));
			std::swap(board[y.y][y.x], x);
		} else {
			board[y.y][y.x].setTexture(pieces[0][0]);
			x.setPosition(sf::Vector2f(y * Magic::cell_size));
			std::swap(board[y.y][y.x], x);
		}
	}
}