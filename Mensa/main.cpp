#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    std::shared_ptr< Game > game = std::make_shared< Game >();

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Mensa");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        game->Update();
        game->Draw( window );
    }

    return 0;
}