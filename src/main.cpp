#include <SFML/Graphics.hpp>

#include "./include/constants.h"
#include "./include/bird.h"
#include "./include/flock.h"
int main()
{
    // For smooth edges on shapes
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "My Window", sf::Style::Default, sf::State::Windowed, settings);

    Flock flock(100);

    // Fixes visual tearing casued by out of sync window with screen
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        

        window.clear();
        flock.draw(window);
        window.display();
    }
}
