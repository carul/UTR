#include "selector.hpp"
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/System.hpp>

bool selector::createnew(int width, int height, std::string name, int posx, int posy, sf::RenderWindow * parentwindow, color rgb, bool center, std::string text, std::string group){
    sf::Text temp;
    temp.setFont(mainfont);
    temp.setString(text);
    temp.setCharacterSize(parentwindow->getSize().y/21);
    temp.setStyle(sf::Text::Bold);
    temp.setColor(sf::Color(255,255,255));
    float wdh = temp.getLocalBounds().width;
    float hgh = temp.getLocalBounds().height;
    if(!center)
        temp.setPosition(sf::Vector2f(posx+width/2-wdh/2,posy+height/2-hgh/2));
    else
        temp.setPosition(sf::Vector2f(parentwindow->getSize().x/2 - temp.getLocalBounds().width/2, posy+height/2-hgh/2-10));
    selectors.push_back({sf::RectangleShape(), selectors.size(), name, parentwindow, temp, group});
    int a = selectors.size();
    a--;
    selectors[a].square.setSize(sf::Vector2f(width, height));
    selectors[a].square.setPosition(sf::Vector2f(posx, posy));
    selectors[a].square.setFillColor(sf::Color(rgb.r, rgb.g, rgb.b));
    if(center){
            selectors[a].square.setPosition(sf::Vector2f(parentwindow->getSize().x/2-width/2, posy));
    }
    return true;
}

void selector::removeall(){
    selectors.clear();
}

std::string selector::getname(int id){
    for (int i = 0; i < selectors.size(); i ++)
        if(selectors[i].id == id)
            return selectors[i].name;
}

void selector::drawallinparentwindow(sf::RenderWindow &parentwindow){
    for(int i=0; i < selectors.size(); i++){
        if(selectors[i].parentwindow = &parentwindow){
            parentwindow.draw(selectors[i].square);
            parentwindow.draw(selectors[i].buttontext);
        }
    }
}

void selector::procclick(int x, int y, bool oneclick){
    for(int i=0; i < selectors.size(); i++){
        if (selectors[i].square.getPosition().x <= x && selectors[i].square.getPosition().y <= y
            && selectors[i].square.getPosition().x + selectors[i].square.getSize().x >= x
            && selectors[i].square.getPosition().y + selectors[i].square.getSize().y >= y){
                if(selectors[i].name!="Start" || !getselectedids().empty()){
                    if(!oneclick){
                            if(selectors[i].clicked){
                                selectors[i].square.setFillColor(sf::Color(0,0,255));
                                selectors[i].clicked = false;
                            }
                            else{
                                selectors[i].square.setFillColor(sf::Color(0,255,0));
                                selectors[i].clicked = true;
                            }
                            std::string tempgroup = selectors[i].group;
                            if(tempgroup != ""){
                                for(int j = 0; j < selectors.size(); j++){
                                    if (selectors[j].group == tempgroup && i != j){
                                        selectors[j].clicked = false;
                                        selectors[j].square.setFillColor(sf::Color(0,0,255));
                                    }
                                }
                            }
                    }
                    else{
                        selectors[i].clicked = true;
                    }
                }
            }
    }
}

void selector::unclick(int id){
    selectors[id].clicked = false;
    selectors[id].square.setFillColor(sf::Color(0,0,255));
}

void selector::setinactive(int id){
    selectors[id].clicked = false;
}
std::vector<int> selector::getselectedids(){
    std::vector <int> temp;
    for(int i = 0; i < selectors.size(); i++)
        if(selectors[i].clicked == true)
            temp.push_back(selectors[i].id);
    return temp;
}
