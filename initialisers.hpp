#ifndef INITIALISERS_H
#define INITIALISERS_H
#include "GAMESCENE/dottedlines.hpp"
#include "UI/selector.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>
#include <SFML/System.hpp>
bool prerunoptions(short &resx, short &resy);
bool initmenubuttons(sf::RenderWindow &window, selector &selector);
void drawalluielements(sf::RenderWindow &window, selector *selectors);
void UIactifclicked(sf::RenderWindow &window, sf::Event event, selector *selectors, bool oneclick=false);
void initdrawableelements(lines &lines, sf::RenderWindow &window);
void drawgameelements(sf::RenderWindow &window, lines lines);
void movegameelements(lines &lines);
#endif // INITIALISERS_H

