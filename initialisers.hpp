#ifndef INITIALISERS_H
#define INITIALISERS_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "initialisers.hpp"
#include "UI/selector.hpp"
bool prerunoptions();
void drawalluielements(sf::RenderWindow &window, selector *selectors);
void UIactifclicked(sf::RenderWindow &window, sf::Event event, selector *selectors);
#endif // INITIALISERS_H

