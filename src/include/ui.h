


#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "slider.h"


class UI {

private:



public:
    sf::RectangleShape top;
    sf::RectangleShape left;
    sf::RectangleShape right;
    sf::RectangleShape bottom;

    SliderSFML matchingFactorSlider;
    SliderSFML centeringFactorSlider;
    SliderSFML avoidFactorSlider;
    SliderSFML maxSpeedSlider;
    SliderSFML minSpeedSlider;



    UI();
    ~UI() = default;


    void draw(sf::RenderWindow& target, sf::Vector2i mousePos);

};

#endif
