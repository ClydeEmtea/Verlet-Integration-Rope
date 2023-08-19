//
// Created by milan on 18.8.23.
//

#ifndef VERLETROPE_PARTICLE_H
#define VERLETROPE_PARTICLE_H
#include <SFML/Graphics.hpp>


class Particle {
public:
    sf::Vector2f position;
    sf::Vector2f oldPosition;
    bool fixed;

    Particle(sf::Vector2f position, bool fixed= false);
    void draw(sf::RenderWindow& window, float radius, sf::Color color);

};


#endif //VERLETROPE_PARTICLE_H
