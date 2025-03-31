#include "../include/slider.h"


SliderSFML::SliderSFML() {
    axisHeight = 10;
    axisWidth = 200;
    sliderWidth = 20;
    sliderHeight = 30;


    if (!font.openFromFile("../src/assets/fonts/neon.ttf")) {
        std::cout << "Error loading font\n";
    } else {
        text.emplace(font);
        text->setFillColor(sf::Color::White);
    }

    axis.setOrigin({ 0.f, axisHeight/2.f });
    axis.setSize(sf::Vector2f(axisWidth, axisHeight));
    axis.setFillColor(SLIDER_AXIS_COL);
    slider.setOrigin({ sliderWidth / 2.f, sliderHeight / 2.f});
    slider.setSize(sf::Vector2f(sliderWidth, sliderHeight));
    slider.setFillColor(TEXT_COL);
}

void SliderSFML::setPosition(float x, float y) {
    axis.setPosition({ x, y });
    slider.setPosition({ x, y });
    xCord = x;
    yCord = y;
}

void SliderSFML::setName(std::string name) {
    sliderName = name;
}

sf::Text SliderSFML::returnText(float x, float y, std::string z, int fontSize, sf::Text::Style textStyle)
{
    text->setCharacterSize(fontSize);
    text->setPosition({ x, y });
    text->setFillColor(TEXT_COL);
    text->setString(z);
    text->setStyle(textStyle);
    return *text;
}

void SliderSFML::create(float min, float max)
{
    sliderValue = min;
    minValue = min;
    maxValue = max;
}

void SliderSFML::logic(sf::RenderWindow &window, sf::Vector2f mousePos)
{
    if (slider.getGlobalBounds().contains({ mousePos.x , mousePos.y })
        && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if (mousePos.x >= xCord && mousePos.x <= xCord + axisWidth)
        {
            slider.setPosition({mousePos.x, yCord});
            sliderValue = (minValue + ((slider.getPosition().x - xCord) / axisWidth * (maxValue - minValue)));

            if (sliderName == "Matching Factor") {
                MATCHING_FACTOR = sliderValue;
                /* std::cout << "NEW MATCHING FACTOR: " << MATCHING_FACTOR << std::endl; */
            } else if (sliderName == "Centering Factor") {
                CENTERING_FACTOR = sliderValue;
                /* std::cout << "NEW CENTERING FACTOR: " << CENTERING_FACTOR << std::endl; */
            } else if (sliderName == "Avoid Factor") {
                AVOID_FACTOR = sliderValue;
                /* std::cout << "NEW AVOID FACTOR: " << AVOID_FACTOR << std::endl; */
            } else if (sliderName == "Max Speed") {
                MAX_SPEED = sliderValue;
                /* std::cout << "NEW MAX SPEED: " << MAX_SPEED << std::endl; */
            } else if (sliderName == "Min Speed") {
                MIN_SPEED = sliderValue;
                /* std::cout << "NEW MIN SPEED: " << MIN_SPEED << std::endl; */
            }
        }
    }
}

float SliderSFML::getSliderValue()
{
    return sliderValue;
}

void SliderSFML::setSliderValue(float newValue)
{
    if (newValue >= minValue && newValue <= maxValue)
    {
        sliderValue = newValue;
        float diff = maxValue - minValue;
        float diff2 = newValue - minValue;
        float zzz = axisWidth / diff;
        float posX = zzz*diff2;
        posX += xCord;
        slider.setPosition({posX, yCord});
    }
}

void SliderSFML::setSliderPercentValue(float newPercentValue)
{
    if (newPercentValue >= 0 && newPercentValue <= 100)
    {
        sliderValue = newPercentValue / 100 * maxValue;
        slider.setPosition({xCord + (axisWidth*newPercentValue / 100), yCord});
    }
}

void SliderSFML::draw(sf::RenderWindow &window, sf::Vector2i mousePos)
{

    std::stringstream minValueString;
    minValueString << std::fixed << std::setprecision(2) << minValue;
    std::stringstream maxValueString;
    maxValueString << std::fixed << std::setprecision(2) << maxValue;
    std::stringstream sliderValueString;
    sliderValueString << std::fixed << std::setprecision(3) << sliderValue;

    sf::Vector2f mousePosf = static_cast<sf::Vector2f>(mousePos);
    logic(window, mousePosf);
    window.draw(returnText(xCord - 10, yCord + 5, minValueString.str(), 17, sf::Text::Style(sf::Text::Regular)));
    window.draw(axis);
    window.draw(returnText(xCord + axisWidth - 10, yCord + 5, maxValueString.str(), 17, sf::Text::Style(sf::Text::Regular)));
    window.draw(slider);
    window.draw(returnText(slider.getPosition().x - sliderWidth, slider.getPosition().y - sliderHeight,
                           sliderValueString.str(), 15, sf::Text::Style(sf::Text::Regular)));

    float xOffset = 50;
    if (sliderName == "Avoid Factor") {
        xOffset = 40;
    } else if (sliderName == "Centering Factor") {
        xOffset = 20;
    } else if (sliderName == "Matching Factor") {
        xOffset = 20;
    } 

    window.draw(returnText(xCord + xOffset, yCord - 60, sliderName, 20, sf::Text::Style(sf::Text::Bold)));

}

