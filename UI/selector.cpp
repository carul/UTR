#include "selector.hpp"
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

bool selector::createnew(int width, int height, std::string name, int posx, int posy, sf::RenderWindow * parentwindow, color rgb){
    selectors.push_back({sf::RectangleShape(), selectors.size(), name, parentwindow});
    int a = selectors.size();
    a--;
    selectors[a].square.setSize(sf::Vector2f(width, height));
    selectors[a].square.setPosition(sf::Vector2f(posx, posy));
    selectors[a].square.setFillColor(sf::Color(rgb.r, rgb.g, rgb.b));
    return true;
}

void selector::removeall(){
    selectors.clear();
}

int selector::getid(std::string name){
    for(int i = 0; i < selectors.size(); i++){
        if(selectors[i].name == name){
            return selectors[i].id;
        }
    }
}

void selector::drawallinparentwindow(sf::RenderWindow &parentwindow){
    for(int i=0; i < selectors.size(); i++){
        if(selectors[i].parentwindow = &parentwindow)
            parentwindow.draw(selectors[i].square);
    }
}
