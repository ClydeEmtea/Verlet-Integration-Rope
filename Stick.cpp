//
// Created by milan on 18.8.23.
//

#include "Stick.h"
#include "Particle.h"
#include <cmath>


Stick::Stick(Particle *particle1, Particle *particle2) {
    this->particle1 = particle1;
    this->particle2 = particle2;
    this->length = std::hypot(particle1->position.x - particle2->position.x, particle1->position.y - particle2->position.y);

}

void Stick::draw(sf::RenderWindow &window, sf::Color color, float thickness) {
    sf::Vector2f delta = particle2->position - particle1->position;
    float angle = atan2(delta.y, delta.x) * 180.0f / 3.14159265f;
    float length_ = std::hypot(delta.x, delta.y);

    sf::RectangleShape line(sf::Vector2f(length_, thickness));
    line.setPosition(particle1->position);
    line.setRotation(angle);
    line.setFillColor(color);

    window.draw(line);
}

