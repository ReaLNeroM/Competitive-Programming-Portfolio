#pragma once

#include <SFML/Graphics.hpp>
#include "magic.h"

namespace Helper {
	sf::Vector2i get_indices(sf::Vector2i);
	sf::Vector2i get_location(sf::Vector2i);
	bool check_null_sprite(sf::Sprite, sf::Texture*);
}