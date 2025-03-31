#include <SFML/Graphics.hpp>

#include "./include/constants.h"
#include "./include/flock.h"
#include "./include/slider.h"
#include "./include/tunableparams.h"
#include "./include/ui.h"

int main()
{
    // For smooth edges on shapes
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "My Window", sf::Style::Default, sf::State::Windowed, settings);

    // Fixes visual tearing casued by out of sync window with screen
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    Flock flock(750);
    UI ui;



    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        window.clear();
        flock.draw(window, mousePos);
        
        ui.draw(window, mousePos);
        window.display();
    }
}
