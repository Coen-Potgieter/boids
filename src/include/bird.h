

#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include <stdint.h>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "tunableparams.h"
#include <cmath>


class Bird {

private:



public:
    sf::CircleShape body;
    sf::Vector2f pos;
    sf::Vector2f velocity;
    sf::Vector2f closeness; // Measures how close other birds are to it
    sf::Vector2f avgVelocity; 
    sf::Vector2f avgPos; 
    sf::Vector2f predatorCloseness;
    uint8_t numNeighbours; 

    Bird();
    ~Bird() = default;


    void avoidEdges();
    void move();
    void draw(sf::RenderWindow& target) const;

};

#endif
