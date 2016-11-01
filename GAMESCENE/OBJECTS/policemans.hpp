#ifndef POLICEMANS_H
#define POLICEMANS_H
#include <SFML/Graphics.hpp>
#include <vector>
struct policeman{
    sf::Sprite shape;
    std::vector<sf::Texture> texture;
    int activetxt;
    sf::Clock animationp;
};
std::vector<sf::Texture> loadpolicemanstextures();
void initpolicemans(policeman &policeman, int which, sf::Vector2u size);
#endif // POLICEMANS_H
