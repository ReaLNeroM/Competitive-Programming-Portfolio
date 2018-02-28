#include <iostream>
#include <vector>
#include <cstdlib> 

#include <SFML/Graphics.hpp>

const int size = 720;
const int board_size = 8;
const int cell_size = size / board_size;

sf::Vector2f get_indices(int x, int y){
    if(0 <= x and x < size and 0 <= y and y < size){
        return sf::Vector2f((x / cell_size) * cell_size, (y / cell_size) * cell_size);
    } else {
        return sf::Vector2f(-1, -1);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(size, size), "It Works!");
    window.setFramerateLimit(60);

    sf::Texture board_image, pawn_image;
    if(!board_image.loadFromFile("board.png")){
        std::cerr << "SMOTAN";
        return -1;
    }
    if(!pawn_image.loadFromFile("pawn.png")){
        std::cerr << "SMOTAN";
        return -1;
    }
    sf::Sprite board, pawn;
    board.setTexture(board_image, true);
    board.setPosition(0.f, 0.f);
    board.setScale((double) size / board_image.getSize().x, 
                    (double) size / board_image.getSize().y);
    pawn.setTexture(pawn_image, true);
    pawn.setPosition(0.f, 0.f);
    pawn.setScale((double) cell_size / pawn_image.getSize().x,
                    (double) cell_size / pawn_image.getSize().y);


    int click_state = 0;
    sf::Sprite *held = NULL;

    while (window.isOpen()){
        sf::Event event;
        auto mouse_location = sf::Mouse::getPosition(window);
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            } else if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    click_state = 1;
                    held = &pawn;
                }
            } else if(event.type == sf::Event::MouseButtonReleased){
                if(click_state != 1 or held == NULL){
                    std::cerr << "Release with no press" << '\n';
                    return -1;
                }

                pawn.setPosition(get_indices(mouse_location.x, mouse_location.y));
                // pawn.setPosition()
                // place it where it is

                click_state = 2;
                held = NULL;
            }
        }

        if(click_state == 1){
            if(held == NULL){
                std::cerr << "Impossible" << '\n';
                return -1;
            }

            held->setPosition(mouse_location.x - cell_size / 2.0, mouse_location.y - cell_size / 2.0);
        }

        window.draw(board);
        window.draw(pawn);

        window.display();
    }

    return 0;
}