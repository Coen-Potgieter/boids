

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <stdint.h>
#include <SFML/Graphics.hpp>

// Window Config
constexpr uint16_t WINDOW_WIDTH = 1300;
constexpr uint16_t WINDOW_HEIGHT = 800;
constexpr float PI = 3.141592653589793;

constexpr uint16_t LEFT_MARGIN = 20;
constexpr uint16_t RIGHT_MARGIN = 350;
constexpr uint16_t VERTICAL_MARGIN = 20;

constexpr uint16_t MAIN_START_X = LEFT_MARGIN;
constexpr uint16_t MAIN_END_X = WINDOW_WIDTH - RIGHT_MARGIN;

constexpr uint16_t MAIN_START_Y = VERTICAL_MARGIN;
constexpr uint16_t MAIN_END_Y = WINDOW_HEIGHT - VERTICAL_MARGIN;

// UI
constexpr sf::Color BG = sf::Color(237, 241, 214);
constexpr sf::Color SLIDER_AXIS_COL = sf::Color(157, 192, 139);
constexpr sf::Color TEXT_COL = sf::Color(64, 81, 59);





// Algo Config
constexpr uint16_t BORDER_MARGIN = 50; 

// Bird Config
/* constexpr sf::Color BIRD_COL = sf::Color(96, 153, 102); */
/* constexpr sf::Color BIRD_COL = sf::Color(16, 135, 14); */
constexpr sf::Color BIRD_COL = sf::Color(7, 128, 5);
/* const sf::Color BIRD_COL = sf::Color::Blue; */
constexpr float BIRD_SIZE = 10;
constexpr float TURN_FACTOR = 0.5;
constexpr float PROTECTED_AREA = 10;
constexpr float VISUAL_AREA = 75;
constexpr float PREDATOR_RANGE = 200;


#endif
