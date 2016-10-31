#include "dottedlines.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#define ammount 20

extern int speed;

void lines::initialise(sf::RenderWindow &window){
    std::vector<sf::RectangleShape> temp;
    temp.resize(ammount);
    siz = window.getSize().y/40;
    for(int i = 0; i < ammount; i++){
        temp[i].setSize(sf::Vector2f(6, siz));
        temp[i].setFillColor(sf::Color(255,255,255));
    }
    for(int i = 0; i < ammount; i++){
        temp[i].setPosition(0, siz*2*i);
    }
    line = temp;
}

void lines::drawintargetwindow(sf::RenderWindow &window){
    int temp;
    temp = window.getSize().x*0.4-3;
    for(int i = 0; i < ammount; i++){
        line[i].setPosition(temp, line[i].getPosition().y);
        window.draw(line[i]);
    }
    temp = window.getSize().x*0.6-3;
    for(int i = 0; i < ammount; i++){
        line[i].setPosition(temp, line[i].getPosition().y);
        window.draw(line[i]);
    }
}

void lines::move(){
    time=clock.restart();
    for(int i = 0; i < ammount; i++){
        line[i].move(sf::Vector2f(0, speed*time.asSeconds()));
        if(line[i].getPosition().y > siz*40)
            line[i].setPosition(0, 0);
    }
}

#undef ammount
