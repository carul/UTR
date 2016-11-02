#include "obstacles.hpp"
#include <iostream>

extern int speed;

int obstacles::sizeinit(){
    return lastsize;
}
void obstacles::init(){
    if(firstinit){
        obs.resize(10);
        for(int i = 0; i < obs.size(); i++){
            int temp = rand() % 2;
            if(temp){
                obs[i].shape.setSize(sf::Vector2f(winsizx*0.36, winsizy*0.1));
                obs[i].shape.setPosition(((rand()%2)+1)*winsizx*0.2+winsizx*0.2-obs[i].shape.getSize().x/2,0);
                obs[i].shape.setFillColor({255,0,255});
                obs[i].type= WIDE;
            }
            else{
                obs[i].shape.setSize(sf::Vector2f(winsizx*0.18, winsizy*0.13));
                obs[i].shape.setPosition(((rand()%3)+1)*winsizx*0.2+winsizx*0.1-obs[i].shape.getSize().x/2,0);
                obs[i].shape.setFillColor({255,0,255});
                obs[i].type= SMALL;
            }
            obs[i].shape.setPosition(obs[i].shape.getPosition().x, -i*2*winsizy*0.15);
        }
        firstinit = false;
    }
 }

obstacles::obstacles(sf::Vector2u size){
    winsizx = size.x;
    winsizy = size.y;
}

void obstacles::moveall(){
    sf::Time temp = clock.restart();
    for(int i = 0; i < obs.size(); i++){
            obs[i].shape.move(0, speed*temp.asSeconds());
            if(obs[i].shape.getPosition().y >= winsizy){
                int temp = rand() % 2;
                if(temp){
                    obs[i].shape.setSize(sf::Vector2f(winsizx*0.36, winsizy*0.1));
                    obs[i].shape.setPosition(((rand()%2)+1)*winsizx*0.2+winsizx*0.2-obs[i].shape.getSize().x/2,0);
                    obs[i].shape.setFillColor({rand()%255,
                                              rand()%255,rand()%255});
                    obs[i].type= WIDE;
                }
                else{
                    obs[i].shape.setSize(sf::Vector2f(winsizx*0.18, winsizy*0.13));
                    obs[i].shape.setPosition(((rand()%3)+1)*winsizx*0.2+winsizx*0.1-obs[i].shape.getSize().x/2,0);
                    obs[i].shape.setFillColor({rand()%255,
                                              rand()%255,rand()%255});
                    obs[i].type= SMALL;
                }
                obs[i].shape.setPosition(obs[i].shape.getPosition().x, -9*2*winsizy*0.15+winsizy);
            }
    }
}

void obstacles::drawall(sf::RenderWindow &window){
    for(int i = 0; i < obs.size(); i++){
            window.draw(obs[i].shape);
    }
}

bool obstacles::collide(player player){
    if(!player.isjumping){
        sf::Rect<int> play(player.shape.getPosition().x, player.shape.getPosition().y, player.shape.getGlobalBounds().width, player.shape.getGlobalBounds().height);
        for(int i = 0; i < obs.size(); i++){
          sf::Rect<int> obja(obs[i].shape.getPosition().x+5, obs[i].shape.getPosition().y+5, obs[i].shape.getSize().x-5, obs[i].shape.getSize().y-5);
            if(obja.intersects(play))
                return true;
        }
    }
}
