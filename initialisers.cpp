#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "initialisers.hpp"
#include "UI/selector.hpp"

bool prerunoptions(){
    sf::RenderWindow setup(sf::VideoMode(600, 600), "Ultra Typrovith Runaway Setup");
    selector presetupselectors;
    presetupselectors.createnew(200, 100, "Start", 100, 100, &setup);
    while(setup.isOpen()){
        setup.clear();
        presetupselectors.drawallinparentwindow(setup);
        setup.display();
    }
}

void drawalluielements(sf::RenderWindow &window){

}
