#include "policemans.hpp"
#include "../spritetools.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

void initpolicemans(policeman &policeman, int which, sf::Vector2u size){
    std::string temp = "POLICE/P";
    temp+=std::to_string(which);
    policeman.texture= findtextures(temp);
    if(policeman.texture.size() > 0){
        policeman.shape.setTexture(policeman.texture[0]);
        policeman.activetxt = 0;
    }
    policeman.shape.setScale(size.x*0.1/policeman.shape.getLocalBounds().width, size.x*0.1/policeman.shape.getLocalBounds().width);
    if(which == 2)
        policeman.shape.setScale(size.x*0.14/policeman.shape.getLocalBounds().width, size.x*0.14/policeman.shape.getLocalBounds().width);
    switch(which){
    case 1:
        policeman.shape.setPosition(size.x*0.1+size.x*0.2-policeman.shape.getGlobalBounds().width/2, size.y-policeman.shape.getGlobalBounds().width);
        break;
    case 2:
        policeman.shape.setPosition(size.x*0.1+size.x*0.4-policeman.shape.getGlobalBounds().width/2, size.y-policeman.shape.getGlobalBounds().width);
        break;
    case 3:
        policeman.shape.setPosition(size.x*0.1+size.x*0.6-policeman.shape.getGlobalBounds().width/2, size.y-policeman.shape.getGlobalBounds().width);
        break;

    }
}
