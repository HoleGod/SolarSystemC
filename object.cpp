#include "object.h"

std::random_device rd;
std::mt19937 gen(rd());
float min_val = 0.5f;
float max_val = 1.5f;
std::uniform_real_distribution<float> dis(min_val, max_val);

object::object(double x, double y, double r, double m, sf::Color c, bool issun, double y_vel, double x_vel) 
    : x(x), y(y), radius(r), mass(m), color(c), isSun(issun), y_vel(y_vel), x_vel(x_vel)
{
}

std::pair<double, double> object::attract(object &other) {
    double dx = other.x - x;
    double dy = other.y - y;
    double d = sqrtf(pow(dx, 2.0) + pow(dy, 2.0));

    if (other.isSun == true)
        this->dts = d;

    double F = G * mass * other.mass / pow(d, 2.0);
    double theta = atan2(dy, dx);

    return std::make_pair(F * cos(theta), F * sin(theta));
}

void object::update_pos(std::vector<object*> &Objects) {
    double tfx = 0, tfy = 0;

    for (auto &other : Objects)
    {
        if (this == other)
            continue;

        auto [fx, fy] = attract(*other);

        tfx += fx;
        tfy += fy;
    }

    x_vel += (tfx / mass) * dt;
    y_vel += (tfy / mass) * dt;

    x += x_vel * dt;
    y += y_vel * dt;

    orbit.emplace_back(x, y);
}

void object::draw(sf::RenderWindow &window) {
    sf::CircleShape shape(radius);
    shape.setFillColor(color);
    shape.setOrigin({static_cast<float>(radius), static_cast<float>(radius)});
    shape.setPosition({static_cast<float>(x * scale + window.getSize().x / 2), static_cast<float>(y * scale + window.getSize().y / 2)});
    window.draw(shape);

    if (orbit.size() > 1)
    {
        sf::VertexArray lines(sf::PrimitiveType::LineStrip, orbit.size());
        for (int i = 0; i < orbit.size(); i++)
        {
            lines[i].position = sf::Vector2f(orbit[i].first * scale + window.getSize().x / 2, orbit[i].second * scale + window.getSize().y / 2);
            lines[i].color = color;
        }
        window.draw(lines);
    }
}

Star::Star(double x, double y)
    : x(x), y(y)
{
    radius = 2.0;
    brightness = 200 + rand()%56;
}

bool Star::check_boundaries(sf::CircleShape star, sf::CircleShape obj) {
    float star_radius = star.getRadius();
    float obj_radius = obj.getRadius();

    sf::Vector2f star_center = star.getPosition() + sf::Vector2f(star_radius, star_radius);
    sf::Vector2f obj_center = obj.getPosition() + sf::Vector2f(obj_radius, obj_radius);

    float dx = star_center.x - obj_center.x;
    float dy = star_center.y - obj_center.y;

    float d = sqrtf(dx*dx + dy*dy);
    return d < (star_radius + obj_radius);
}

void Star::draw(sf::RenderWindow &window) {
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color(brightness, brightness, brightness, 255));
    shape.setOrigin({static_cast<float>(radius), static_cast<float>(radius)});
    shape.setPosition({static_cast<float>(x), static_cast<float>(y)});
    window.draw(shape);
}

void Star::update_brightness() {
    if (rand() % 100 < 2)
        brightness = 100 + rand()%156;
}