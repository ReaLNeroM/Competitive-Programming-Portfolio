#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

const double PI = 3.14159265358979;
const double radius = 10.0;

int main(){
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(2.0 * radius);
	shape.setFillColor(sf::Color::Green);

	double ypos = 50.0, xpos = 50.0;
	double movement = 0.792;

	shape.setPosition(xpos, ypos);
	sf::Clock clock;

	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
				return 0;
			}
		}

		if(clock.getElapsedTime().asMilliseconds() > 2){
			clock.restart();
			ypos += sin(movement);
			xpos += cos(movement);

			shape.setPosition(xpos, ypos);

			double previous_movement = movement;

			auto x = shape.getGlobalBounds();

			int change = 0;

			if(!(0.0 < x.left and x.left + x.width < 200.0)){
				if(movement >= 0.f){
					movement = PI - movement;
				} else {
					movement = -PI - movement;
				}

				change++;
			} else if(!(0.0 < x.top and x.top + x.height < 200.0)){
				movement = -movement;

				change++;
			}

			if(change){
				ypos -= sin(previous_movement);
				xpos -= cos(previous_movement);
			}

			shape.setPosition(xpos, ypos);

			window.clear();
			window.draw(shape);
			window.display();
		}
	}

}
