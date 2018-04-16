#`include "helper.h"

namespace Helper {
	sf::Vector2i get_indices(sf::Vector2i v){
		if(0 <= v.x and v.x < Magic::size and 0 <= v.y and v.y < Magic::size){
			return sf::Vector2i(v.x / Magic::cell_size, v.y / Magic::cell_size);
		} else {
			return sf::Vector2i(-1, -1);
		}
	}
	sf::Vector2i get_location(sf::Vector2i v){
		v = get_indices(v);
		return sf::Vector2i(v.x * Magic::cell_size, v.y * Magic::cell_size);
	}
}