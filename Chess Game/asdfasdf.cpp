#include <iostream>
#include <vector>
#include <cstdlib> 
#include <cmath>

#include <SFML/Graphics.hpp>

const int size = 720;
const int board_size = 8;
const int cell_size = size / board_size;

sf::Vector2f get_location(sf::Vector2f indices){
    return sf::Vector2f(indices.x * cell_size, indices.y * cell_size);
}

sf::Vector2f get_indices(sf::Vector2f coordinates){
    if(0 <= coordinates.x and coordinates.x < size and 0 <= coordinates.y and coordinates.y < size){
        return sf::Vector2f(std::floor(coordinates.x / cell_size), std::floor(coordinates.y / cell_size));
    } else {
        return sf::Vector2f(-1, -1);
    }
}

int board[board_size][board_size] = {
    { 0,  0,  0,  0,  0,  0,  0,  0};
    { 1,  1,  1,  1,  1,  1,  1,  1};
    { 0,  0,  0,  0,  0,  0,  0,  0};
    { 0,  0,  0,  0,  0,  0,  0,  0};
    { 0,  0,  0,  0,  0,  0,  0,  0};
    { 0,  0,  0,  0,  0,  0,  0,  0};
    {-1, -1, -1, -1, -1, -1, -1, -1};
    { 0,  0,  0,  0,  0,  0,  0,  0};
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(size, size), "It Works!");
    window.setFramerateLimit(60);

    loader.load_files();

    sf::Sprite board;
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
        auto mouse_location = sf::Vector2f(sf::Mouse::getPosition(window));
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            } else if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    click_state = 1;
                    held = &pawn;

                    //get location
                }
            } else if(event.type == sf::Event::MouseButtonReleased){
                if(click_state != 1 or held == NULL){
                    std::cerr << "Release with no press" << '\n';
                    return -1;
                }

                pawn.setPosition(get_location(get_indices(mouse_location)));

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
