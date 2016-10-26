#ifndef INITIALISERS_H
#define INITIALISERS_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>
#include <SFML/System.hpp>
#include "UI/selector.hpp"
bool prerunoptions(short &resx, short &resy);
bool initmenubuttons(sf::RenderWindow &window, selector &selector);
void drawalluielements(sf::RenderWindow &window, selector *selectors);
void UIactifclicked(sf::RenderWindow &window, sf::Event event, selector *selectors, bool oneclick=false);
#endif // INITIALISERS_H

