#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <random>

class object
{
public:
    double x, y;
    double x_vel, y_vel;
    double mass, radius, dts;
    double G = 6.67e-11;
    double g = 9.82;
    double AU = 149.6e9;
    double scale = 45 / AU;
    double dt = 24 * 60 * 60;
    bool isSun;
    sf::Color color;
    std::vector<std::pair<double, double>> orbit;

public:
    object(double x, double y, double r, double m, sf::Color c, bool issun = false, double y_vel = 0, double x_vel = 0);
    std::pair<double, double> attract(object &other);
    void update_pos(std::vector<object *> &Objects);
    void draw(sf::RenderWindow &window);
};

class Star
{
public:
    double x, y, brightness;
    float radius;
    sf::Color color;

    double AU = 149.6e9;
    double scale = 45 / AU;

public:
    Star(double x, double y);
    bool check_boundaries(sf::CircleShape star, sf::CircleShape obj);
    void draw(sf::RenderWindow &window);
    void update_brightness();
};