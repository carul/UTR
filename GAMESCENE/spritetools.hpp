#ifndef SPRITETOOLS_H
#define SPRITETOOLS_H
#include "player.hpp"
#include "OBJECTS/policemans.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
std::vector<sf::Texture> findtextures(std::string folder);
void animatetexture(std::vector<sf::Texture> &txt, sf::Sprite &sprite, int &active);
void drawpolice(sf::RenderWindow &window, policeman &man1, policeman &man2, policeman &man3);
#endif // SPRITETOOLS_H
