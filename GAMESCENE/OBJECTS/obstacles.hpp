#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "../player.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
extern int speed;

enum{
    WIDE = 1,
    SMALL = 0
};

struct object{
    int type;
    bool active = false;
    sf::RectangleShape shape;
};

class obstacles{
    public:
    sf::Clock clock, activatetimer;
    int activtime;
    bool firstinit = true;
    int winsizx, winsizy;
    int nowappear = 0;
    int lastsize;
    sf::Vector2u windowsize;
    std::vector<sf::Texture> smalltxt;
    std::vector<sf::Texture> bigtxt;
    std::vector<object> obs;
    obstacles(sf::Vector2u size);
    void init(); //105
    int sizeinit();
    void moveall();
    void drawall(sf::RenderWindow &window);
    bool collide(player player);
};
#endif // OBSTACLES_H
