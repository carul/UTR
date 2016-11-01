#include "surroundings.hpp"
#include "../spritetools.hpp"
#include <iostream>

extern int speed;

void surrounding::init(sf::Vector2u size){
    clock.restart();
    int temp = size.y;
    temp *= -1;
    std::cout << temp << std::endl;
    textures = findtextures("SURROUNDINGS");
    if(textures.size() > 0){
        for(int i = 0; i < 4; i++){
            if(textures.size() > 1)
                surr[i].setTexture(textures[(rand() % (textures.size())+1)-1]);
            else
                surr[i].setTexture(textures[0]);
            surr[i].setScale(size.x*0.2/surr[i].getGlobalBounds().width, size.y/surr[i].getGlobalBounds().height);
            switch(i){
            case 0:
                surr[i].setOrigin(surr[i].getLocalBounds().width, surr[i].getLocalBounds().height);
                surr[i].rotate(180);
                surr[i].setPosition(0, 0);
                break;
            case 1:
                surr[i].setPosition(size.x-surr[i].getGlobalBounds().width, 0);
                break;
            case 2:
                surr[i].setOrigin(surr[i].getLocalBounds().width, surr[i].getLocalBounds().height);
                surr[i].rotate(180);
                surr[i].setPosition(0, temp);
                break;
            case 3:
                surr[i].setPosition(size.x-surr[i].getGlobalBounds().width, temp);
                break;
            }
        }
    }
}

void surrounding::drawinwindow(sf::RenderWindow &window){
    sf::Time time= clock.restart();
    int temp = window.getSize().y;
    temp *= -1;
    for(int i = 0; i < 4; i++){
        surr[i].move(0, speed*time.asSeconds());
        if(surr[i].getPosition().y>= window.getSize().y){
            surr[i].setPosition(surr[i].getPosition().x, temp);
            if(textures.size() > 1)
                surr[i].setTexture(textures[(rand() % (textures.size())+1)-1]);
            else
                surr[i].setTexture(textures[0]);
        }
    }
    for(int i = 0; i < 4; i++){
        window.draw(surr[i]);
    }
}
