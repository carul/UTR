#include "player.hpp"
#include "spritetools.hpp"
#include <SFML/Graphics.hpp>
#include <dirent.h>
#include <string>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>
#include <SFML/System.hpp>
#include <iostream>

void moveplayer(player &player, int ammount){
    sf::Time time = player.passed.restart();
    player.actualmove += time.asSeconds()*player.speed;
    if(player.actualmove < ammount)
        if(player.MovDirRight)
            player.shape.move(time.asSeconds()*player.speed, 0);
        else
            player.shape.move(-1*time.asSeconds()*player.speed, 0);
    else
        player.ismoving = false;
}

void resetmovement(player &player, bool isright){
    player.passed.restart();
    player.ismoving = true;
    player.actualmove = 0;
    if(isright){
        player.MovDirRight = true;
        player.posx++;
    }
    else{
        player.MovDirRight = false;
        player.posx--;
    }
}

void moveplayervert(player &player){
    sf::Time time = player.vertpassed.restart();
    if(player.MoveDirUp && player.posy > 2){
        player.posy-= time.asSeconds()*player.speed;
    }
    else{
        player.posy+= time.asSeconds()*player.speed;
    }
}

void initplayertxt(player &player, sf::Vector2u size){
    player.speed *= size.x*size.y/2/1000;
    player.texture = findtextures("player");
    if(player.texture.size() > 0){
        player.shape.setTexture(player.texture[0]);
        player.activetxt = 0;
    }
    player.shape.setScale(size.x*0.11/player.shape.getLocalBounds().width, size.y*0.11/player.shape.getGlobalBounds().height);
}

void managemovement(player &player, sf::Vector2u size){
    if(player.ismoving){
        moveplayer(player, size.x*0.2);
        player.shape.setPosition(player.shape.getPosition().x, player.posy);
    }
    else
       player.shape.setPosition(player.posx*size.x*0.2+0.5*size.x*0.2-player.shape.getGlobalBounds().width/2, player.posy);
    if(player.ismovingvert)
       moveplayervert(player);
    if(player.animationp.getElapsedTime().asMilliseconds() > 100){
        animatetexture(player.texture, player.shape, player.activetxt);
        player.animationp.restart();
    }
}
