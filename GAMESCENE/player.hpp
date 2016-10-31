#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
struct player{
    public:
    double posx, posy;
    bool ismoving = false;
    sf::RectangleShape shape;
    bool MovDirRight;
    sf::Clock passed, vertpassed;
    double actualmove;
    int speed = 300;
    bool ismovingvert = false, MoveDirUp;
};
void moveplayer(player &player, int ammount);
void resetmovement(player &player, bool isright);
void moveplayervert(player &player);
#endif // PLAYER_H
