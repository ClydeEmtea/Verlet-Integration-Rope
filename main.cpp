#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <unistd.h>
#include "Particle.h"
#include "Stick.h"

using namespace sf;

namespace Constants
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    const int WINDOW_X = VideoMode::getDesktopMode().width / 2 - WIDTH / 2;
    const int WINDOW_Y = VideoMode::getDesktopMode().height / 2 - HEIGHT / 2;
    const int FPS = 60;

    const Color gray = Color(200, 200, 200);

    const int numParticles = 30;
    const float particleSize = 0.5f;
    const int spaceBetweenParticles = 15;
    const float thickness = 5.0f;

    const int gravity[] = {0, 20};
    const float dt = 0.2f;
}

void verletIntegration(std::vector<Particle>& particles, std::vector<Stick>& sticks, const sf::Vector2f& gravity, float dt) {
    for (Particle& particle : particles) {
        if (!particle.fixed) {
            sf::Vector2f tempPosition = particle.position;
            particle.position += (particle.position - particle.oldPosition) + gravity * dt * dt;
            particle.oldPosition = tempPosition;
        }
    }

    for (int iteration = 0; iteration < 20; ++iteration) {
        for (Stick& stick : sticks) {
            sf::Vector2f delta = stick.particle2->position - stick.particle1->position;
            float currentLength = std::hypot(delta.x, delta.y);
            float diff = (currentLength - stick.length) / currentLength;

            if (!stick.particle1->fixed) {
                stick.particle1->position += delta * 0.5f * diff;
            }

            if (!stick.particle2->fixed) {
                stick.particle2->position -= delta * 0.5f * diff;
            }
        }
    }
}

void drawAll(std::vector<Particle> particles, std::vector<Stick> sticks, RenderWindow &window)
{
    for (Particle particle : particles)
    {
        particle.draw(window, Constants::particleSize, Constants::gray);
    }

    for (Stick stick : sticks)
    {
        stick.draw(window, Constants::gray, Constants::thickness);
    }
}


int main()
{
    RenderWindow window(VideoMode(Constants::WIDTH, Constants::HEIGHT), "Verlet Integration");
    window.setPosition(Vector2i(Constants::WINDOW_X, Constants::WINDOW_Y));
    usleep(100000);
    window.setFramerateLimit(Constants::FPS);
    window.setVerticalSyncEnabled(true);
    window.setMouseCursorVisible(false);


    float mouseX = Mouse::getPosition(window).x;
    float mouseY = Mouse::getPosition(window).y;

    std::vector<Particle> particles;
    std::vector<Stick> sticks;

    for (int i = 0; i < Constants::numParticles; i++)
    {
        particles.push_back(Particle(Vector2f (mouseX, mouseY + i * Constants::spaceBetweenParticles), i == 0));
    }

    for (int i = 0; i < Constants::numParticles - 1; i++)
    {
        sticks.push_back(Stick(&particles[i], &particles[i + 1]));
    }


    while (window.isOpen())
    {
        Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        mouseX = Mouse::getPosition(window).x;
        mouseY = Mouse::getPosition(window).y;
        particles[0].position = Vector2f(mouseX, mouseY);
        verletIntegration(particles, sticks, Vector2f(Constants::gravity[0], Constants::gravity[1]), Constants::dt);
        drawAll(particles, sticks, window);

        window.display();
    }

    return 0;
}