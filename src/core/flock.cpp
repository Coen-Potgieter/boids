




#include "../include/flock.h"

Flock::Flock(uint8_t numBirds) {

    for (int i = 0; i < numBirds; i++) {
        birds.push_back(Bird());
    }

    std::cout << "Flock Created..." << std::endl;
}


void Flock::draw(sf::RenderWindow& target) {

    for (int i = 0; i < birds.size(); i++) {
         
        // Reset Closeness
        birds[i].closeness = { 0.f, 0.f };

        // Reset avgVelocity and number of neighbours
        birds[i].avgVelocity = { 0.f, 0.f };
        birds[i].numNeighbours = 0;

        // Reset avgPosition 
        birds[i].avgPos = { 0.f, 0.f };

        sf::Vector2f birdPos = birds[i].pos;
        // check distance with each boid
        for (int j = 0; j < birds.size(); j++) {
            if (j == i) continue;

            sf::Vector2f otherBirdPos = birds[j].pos;
            float distX = birdPos.x - otherBirdPos.x;
            float distY = birdPos.y - otherBirdPos.y;

            if (std::abs(distX) < VISUAL_AREA && std::abs(distY) < VISUAL_AREA) {
                if (std::abs(distX) < PROTECTED_AREA && std::abs(distY) < PROTECTED_AREA) {
                    birds[i].closeness += { birdPos.x - otherBirdPos.x, birdPos.y - otherBirdPos.y };
                } 

                birds[i].avgPos += otherBirdPos;

                birds[i].avgVelocity += birds[j].velocity;
                birds[i].numNeighbours += 1;
            }

        }

    }


    for (int i = 0; i < birds.size(); i++) {

        birds[i].move();
        birds[i].draw(target);
    }


}






