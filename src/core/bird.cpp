


#include "../include/bird.h"

Bird::Bird() {

    // Create Shape
    body = sf::CircleShape(BIRD_SIZE, 3);

    // Colours
    body.setFillColor(BIRD_COL);

    // Set Initial Position
    pos = { static_cast<float>(std::rand() % WINDOW_WIDTH), static_cast<float>(std::rand() % WINDOW_HEIGHT)};
    body.setPosition(pos);

    // Set initial rotation
    body.setRotation(sf::Angle(sf::degrees(std::rand() % 360)));

    // Set Closeness
    closeness = { 0.f, 0.f };

    // Set Velocity
    velocity = { 1.f, 1.f };

    std::cout << "Bird Created..." << std::endl;
}


void Bird::avoidEdges() {

    if (pos.x > WINDOW_WIDTH - MARGIN) {
        velocity.x -= TURN_FACTOR;

    } else if (pos.x < MARGIN) {
        velocity.x += TURN_FACTOR;
    } 
    if (pos.y > WINDOW_HEIGHT - MARGIN) {
        velocity.y -= TURN_FACTOR;
    } else if (pos.y < MARGIN) {
        velocity.y += TURN_FACTOR;
    }

}
void Bird::move() {


    // Closeness
    velocity.x += closeness.x * AVOID_FACTOR;
    velocity.y += closeness.y * AVOID_FACTOR;

    // Avg Velocity Addition And Average Position
    if (numNeighbours > 0) {
        // Avg Velocity
        avgVelocity.x /= numNeighbours;
        avgVelocity.y /= numNeighbours;

        velocity.x += (avgVelocity.x - velocity.x)*MATCHING_FACTOR;
        velocity.y += (avgVelocity.y - velocity.y)*MATCHING_FACTOR;

        // Avg Position
        avgPos.x /= numNeighbours;
        avgPos.y /= numNeighbours;

        velocity.x += (avgPos.x - pos.x)*CENTERING_FACTOR;
        velocity.y += (avgPos.y - pos.y)*CENTERING_FACTOR;
    }

    avoidEdges();

    // Max and min speeds
    float speed = std::sqrt(velocity.x*velocity.x + velocity.y*velocity.y);
    if (speed > MAX_SPEED) {
        velocity.x = (velocity.x/speed)*MAX_SPEED;
        velocity.y = (velocity.y/speed)*MAX_SPEED;
    } else if (speed < MIN_SPEED) {
        velocity.x = (velocity.x/speed)*MIN_SPEED;
        velocity.y = (velocity.y/speed)*MIN_SPEED;
    } 

    pos.x += velocity.x;
    pos.y += velocity.y;
    body.setPosition(pos);

    // Update Rotation
    float angle = std::tanh(std::abs(velocity.y) / std::abs(velocity.x));
    if (velocity.x > 0 && velocity.y < 0) {
        // Quad 1
        body.setRotation(sf::Angle(sf::radians(PI - angle)));
    } else if (velocity.x < 0 && velocity.y < 0) {
        // Quad 2
        body.setRotation(sf::Angle(sf::radians(1.5*PI + angle)));
    } else if (velocity.x < 0 && velocity.y > 0) {
        // Quad 3
        body.setRotation(sf::Angle(sf::radians(1.5*PI - angle)));
    } else {
        // Quad 4
        body.setRotation(sf::Angle(sf::radians(0.5*PI + angle)));
    }
}

void Bird::draw(sf::RenderWindow& target) const {

    target.draw(body);
}



