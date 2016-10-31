#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
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
    if(player.MoveDirUp){
        player.posy-= time.asSeconds()*player.speed;
    }
    else{
        player.posy+= time.asSeconds()*player.speed;
    }
}
