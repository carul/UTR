#ifndef DOTTEDLINES_H
#define DOTTEDLINES_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
class lines{
    sf::Clock clock;
    sf::Time time;
    float siz;
    std::vector<sf::RectangleShape> line;
    public:
    void initialise(sf::RenderWindow &window);
    void drawintargetwindow(sf::RenderWindow &window);
    void move();
};
#endif // DOTTEDLINES_H
