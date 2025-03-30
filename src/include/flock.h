

#ifndef FLOCK_H
#define FLOCK_H

#include <iostream>
#include <stdint.h>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "bird.h"

class Flock {

private:

    std::vector<Bird> birds;

public:
    Flock(uint8_t numBirds);
    ~Flock() = default;

    void draw(sf::RenderWindow& target);

};

#endif
