

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <stdint.h>
#include <SFML/Graphics.hpp>

// Window Config
constexpr int WINDOW_WIDTH = 1000;
constexpr int WINDOW_HEIGHT = 800;
constexpr float PI = 3.141592653589793;

// Algo Config
constexpr int MARGIN = 100; 
constexpr float MATCHING_FACTOR = 0.05;
constexpr float CENTERING_FACTOR = 0.0005;
constexpr float AVOID_FACTOR = 0.05;


// Bird Config
const sf::Color BIRD_COL = sf::Color::Blue;
constexpr float BIRD_SIZE = 10;
constexpr float TURN_FACTOR = 0.2;
constexpr float MAX_SPEED = 10.f;
constexpr float MIN_SPEED = 4;
constexpr float PROTECTED_AREA = 10;
constexpr float VISUAL_AREA = 75;


#endif
