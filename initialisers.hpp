#ifndef INITIALISERS_H
#define INITIALISERS_H
#include "GAMESCENE/dottedlines.hpp"
#include "GAMESCENE/player.hpp"
#include "UI/selector.hpp"
#include "GAMESCENE/OBJECTS/obstacles.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>
#include <SFML/System.hpp>
void drawgameelements(sf::RenderWindow &window, lines lines, sf::Sprite player);
int prerunoptions(short &resx, short &resy);
bool initmenubuttons(sf::RenderWindow &window, selector &selector);
void drawalluielements(sf::RenderWindow &window, selector *selectors);
void UIactifclicked(sf::RenderWindow &window, sf::Event event, selector *selectors, bool oneclick=false);
void initdrawableelements(lines &lines, sf::RenderWindow &window);
void movegameelements(lines &lines);
void resetvars(player &player, obstacles &obstacles, sf::RenderWindow &window);
void resetimages(sf::RectangleShape &defs, sf::RectangleShape &defs2, lines &line, sf::RenderWindow &mainwindow);
#endif // INITIALISERS_H

