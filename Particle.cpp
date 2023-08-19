//
// Created by milan on 18.8.23.
//

#include "Particle.h"

Particle::Particle(sf::Vector2f position, bool fixed) {

    this->position = position;
    this->oldPosition = position;
    this->fixed = fixed;
}

void Particle::draw(sf::RenderWindow &window, float radius, sf::Color color) {
    sf::CircleShape circle(radius);
    circle.setFillColor(color);
    circle.setPosition(position.x - radius, position.y - radius);
    window.draw(circle);

}
