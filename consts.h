#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

double AU = 149.6e9;

namespace mc {
    inline sf::Color mercury_color = sf::Color(133, 130, 125);
    inline sf::Color venus_color = sf::Color(209, 156, 109);
    inline sf::Color earth_color = sf::Color(57, 54, 201);
    inline sf::Color mars_color = sf::Color(212, 49, 49);
    inline sf::Color jupiter_color = sf::Color(210, 180, 140);
    inline sf::Color saturn_color = sf::Color(255, 240, 207);
    inline sf::Color uranus_color = sf::Color(175, 238, 238);
    inline sf::Color neptune_color = sf::Color(51, 70, 163);
    inline sf::Color sun_color = sf::Color(253, 184, 19);

    inline double mercury_radius = 2;
    inline double venus_radius = 6;
    inline double earth_radius = 7;
    inline double mars_radius = 5;
    inline double jupiter_radius = 20;
    inline double saturn_radius = 15;
    inline double uranus_radius = 6;
    inline double neptune_radius = 4; 
    inline double sun_radius = 12;

    inline double mercury_mass = 3.3010e23;
    inline double venus_mass =  4.8673e24;
    inline double earth_mass =  5.9722e24;
    inline double mars_mass =  6.4169e23;
    inline double jupiter_mass = 1.8981e27;
    inline double saturn_mass =  5.6832e26;
    inline double uranus_mass =  8.6810e25;
    inline double neptune_mass = 1.0241e26;
    inline double sun_mass = 1.988e30;
    
    inline double mercury_dts = 0.39 * AU;
    inline double venus_dts =  0.72 * AU;
    inline double earth_dts =  AU;
    inline double mars_dts =  1.52 * AU;
    inline double jupiter_dts = 5.2 * AU;
    inline double saturn_dts =  9.54 * AU;
    inline double uranus_dts =  19.2 * AU;
    inline double neptune_dts = 30.06 * AU;

    /*
    inline double mercury_ov = 4.7362e4;
    inline double venus_ov = 3.5020e4;
    inline double earth_ov = 2.9783e4;
    inline double mars_ov = 2.4077e4;
    inline double jupiter_ov = 1.3056e4;
    inline double saturn_ov = 9.6391e3;
    inline double uranus_ov = 6.7991e3;
    inline double neptune_ov = 5.4349e3;

    inline double mercury_r = 2.4397e3;
    inline double venus_r =  6.0518e3;
    inline double earth_r =  6.3710e3;
    inline double mars_r =  3.3895e3;
    inline double jupiter_r = 6.9911e4;
    inline double saturn_r =  5.8232e4;
    inline double uranus_r =  2.5362e4;
    inline double neptune_r = 2.4622e4;
    inline double sun_r = 695.7e3;
    
    #85827d
    #060606
    #3936c9
    #d43131
    #d2b48c
    #fff0cf
    #afeeee
    #3346a3
    */
};