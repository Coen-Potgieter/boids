#ifndef SLIDER_H
#define SLIDER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include "./tunableparams.h"
#include "./constants.h"

class SliderSFML
{
	sf::RectangleShape slider;
	sf::RectangleShape axis;
	sf::Font font;
    std::optional<sf::Text> text;
	float minValue;
	float maxValue;
	float xCord;
	float yCord;
	float axisWidth;
	float axisHeight;
	float sliderWidth;
	float sliderHeight;
	float sliderValue;
    std::string sliderName;
public:
	SliderSFML();
	sf::Text returnText(float x, float y, std::string z, int fontSize, sf::Text::Style textStyle);
	void create(float min, float max);
	void logic(sf::RenderWindow &window, sf::Vector2f mousePos);
	float getSliderValue();
	void setSliderValue(float newValue);
	void setSliderPercentValue(float newPercentValue);
	void draw(sf::RenderWindow & window, sf::Vector2i mousePos);
    void setPosition(float x, float y);
    void setName(std::string name);
};

#endif
