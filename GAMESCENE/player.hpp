#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <SFML/System.hpp>
#include <vector>
struct player{
    public:
    double posx, posy;
    bool ismoving = false;
    sf::Sprite shape;
    bool MovDirRight;
    sf::Clock passed, vertpassed, animationp;
    double actualmove;
    double speed = 0.7;
    bool ismovingvert = false, MoveDirUp;
    std::vector<sf::Texture> texture;
    int activetxt = -1;
};
void moveplayer(player &player, int ammount);
void resetmovement(player &player, bool isright);
void moveplayervert(player &player);
void initplayertxt(player &player, sf::Vector2u size);
void managemovement(player &player, sf::Vector2u size);
#endif // PLAYER_H
