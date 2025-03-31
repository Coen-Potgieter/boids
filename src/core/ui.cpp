


#include "../include/ui.h"

UI::UI() {

    // Background
    top = sf::RectangleShape({ static_cast<float>(WINDOW_WIDTH), static_cast<float>(VERTICAL_MARGIN)});
    bottom = sf::RectangleShape({ static_cast<float>(WINDOW_WIDTH), static_cast<float>(VERTICAL_MARGIN)});
    left = sf::RectangleShape({ static_cast<float>(LEFT_MARGIN), static_cast<float>(WINDOW_HEIGHT)});
    right = sf::RectangleShape({ static_cast<float>(RIGHT_MARGIN), static_cast<float>(WINDOW_HEIGHT)});

    top.setPosition({ 0.f, 0.f });
    top.setFillColor(BG);

    bottom.setPosition({ 0.f, static_cast<float>(MAIN_END_Y)});
    bottom.setFillColor(BG);
    
    left.setPosition({ 0.f, 0.f});
    left.setFillColor(BG);

    right.setPosition({ static_cast<float>(MAIN_END_X), 0.f });
    right.setFillColor(BG);

    // Sliders
    matchingFactorSlider.setPosition(MAIN_END_X + RIGHT_MARGIN/4.0, 100.f);
    matchingFactorSlider.setName("Matching Factor");
    matchingFactorSlider.create(0, 0.1);
    matchingFactorSlider.setSliderValue(MATCHING_FACTOR);

    centeringFactorSlider.setPosition(MAIN_END_X + RIGHT_MARGIN/4.0, 250.f);
    centeringFactorSlider.setName("Centering Factor");
    centeringFactorSlider.create(0, 0.01);
    centeringFactorSlider.setSliderValue(CENTERING_FACTOR);

    avoidFactorSlider.setPosition(MAIN_END_X + RIGHT_MARGIN/4.0, 400.f);
    avoidFactorSlider.setName("Avoid Factor");
    avoidFactorSlider.create(0, 0.1);
    avoidFactorSlider.setSliderValue(AVOID_FACTOR);

    maxSpeedSlider.setPosition(MAIN_END_X + RIGHT_MARGIN/4.0, 550.f);
    maxSpeedSlider.setName("Max Speed");
    maxSpeedSlider.create(5, 20);
    maxSpeedSlider.setSliderValue(MAX_SPEED);

    minSpeedSlider.setPosition(MAIN_END_X + RIGHT_MARGIN/4.0, 700.f);
    minSpeedSlider.setName("Min Speed");
    minSpeedSlider.create(5, 20);
    minSpeedSlider.setSliderValue(MIN_SPEED);
}


void UI::draw(sf::RenderWindow& target, sf::Vector2i mousePos) {
    target.draw(top);
    target.draw(bottom);
    target.draw(left);
    target.draw(right);

    matchingFactorSlider.draw(target, mousePos);
    centeringFactorSlider.draw(target, mousePos);
    avoidFactorSlider.draw(target, mousePos);
    maxSpeedSlider.draw(target, mousePos);
    minSpeedSlider.draw(target, mousePos);
}



