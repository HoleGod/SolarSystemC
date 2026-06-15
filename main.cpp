#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "object.h"
#include "consts.h"
#include <optional>
#include <iostream>

int main()
{
    unsigned height = 900;
    unsigned width = 900;
    int fps = 30;

    sf::RenderWindow window(sf::VideoMode({width, height}), "Solar system");
    window.setFramerateLimit(60);    

    object sun(0, 0, mc::sun_radius, mc::sun_mass, mc::sun_color, true);
    object mercury(mc::mercury_dts, 0, mc::mercury_radius, mc::mercury_mass, mc::mercury_color, false, -47.4e3);
    object venus(mc::venus_dts, 0, mc::venus_radius, mc::venus_mass, mc::venus_color, false, -35.02e3);
    object earth(mc::earth_dts, 0, mc::earth_radius, mc::earth_mass, mc::earth_color, false, 29.783e3);
    object mars(mc::mars_dts, 0, mc::mars_radius, mc::mars_mass, mc::mars_color, false, 24.077e3);
    object jupiter(mc::jupiter_dts, 0, mc::jupiter_radius, mc::jupiter_mass, mc::jupiter_color, false, 13.07e3);
    object saturn(mc::saturn_dts, 0, mc::saturn_radius, mc::saturn_mass, mc::saturn_color, false, 9.69e3);
    object uranus(mc::uranus_dts, 0, mc::uranus_radius, mc::uranus_mass, mc::uranus_color, false, 6.81e3);
    object neptune(mc::neptune_dts, 0, mc::neptune_radius, mc::neptune_mass, mc::neptune_color, false, 5.43e3);

    std::vector<object*> Objects = {&sun, &mercury, &venus, &earth, &mars, &jupiter, &saturn, &uranus, &neptune};
    std::vector<Star> Stars = {};

    for (int i = 0;i < 200; i++) {
        double x = rand()%900, y = rand()%900;
        Star star(x, y);
        Stars.push_back(star);
    }

    for (int i = 0;i < 10;i++) {
        std::cout << "Star " << i+1 << std::endl;
        std::cout << "Star x:" << Stars[i].x << std::endl;
        std::cout << "Star y:" << Stars[i].y << std::endl;
        std::cout << "Star b:" << Stars[i].brightness << std::endl;
        std::cout << "Star r:" << Stars[i].radius << std::endl;
    }

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        for (auto& star: Stars) {
            star.update_brightness();
            star.draw(window);
        }

        for (auto& obj: Objects) {
            obj->update_pos(Objects);
            obj->draw(window);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) 
            for (auto& obj: Objects)
                obj->scale *= 1.08f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) 
            for (auto& obj: Objects)
                obj->scale /= 1.08f;
        
        window.display();
    }

    return 0;
}