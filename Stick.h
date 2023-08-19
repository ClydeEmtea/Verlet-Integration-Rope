//
// Created by milan on 18.8.23.
//

#ifndef VERLETROPE_STICK_H
#define VERLETROPE_STICK_H


#include "Particle.h"

class Stick {
public:
    Particle* particle1;
    Particle* particle2;
    float length;

    Stick(Particle* particle1, Particle* particle2);
    void draw(sf::RenderWindow& window, sf::Color color, float thickness = 1.0f);
};


#endif //VERLETROPE_STICK_H
