#ifndef POINTS_H
#define POINTS_H
#include "../player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
extern int speed;
class points{
    public:
    std::vector<sf::RectangleShape>point;
    std::vector<sf::Texture>ptxt;
    sf::Clock moveclock, spawnclock;
    sf::RenderWindow *parentwindow;
    void moveAndRegen();
    void init();
    points(sf::RenderWindow *window);
    void checkcollison(player player);
    sf::Text sct;
    void eraseall();
};
#endif // POINTS_H
