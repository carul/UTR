#include "maineventhandler.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>
#include <SFML/System.hpp>
#include "initialisers.hpp"
#include "UI/selector.hpp"

int handlemenuevents(sf::RenderWindow &window, selector &selector){
    sf::Event event;
    while(window.pollEvent(event)){
        switch(event.type){
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            UIactifclicked(window, event, &selector, true);
            break;
        }
    }
    std::vector<int>clicked = selector.getselectedids();
    std::string temp;
    for(int i = 0; i < clicked.size(); i++){
        temp = selector.getname(clicked[i]);
        selector.unclick(clicked[i]);
        if(temp == "EXIT")
            window.close();
        if(temp == "START")
            return 1;
    }
    return 0;
}
