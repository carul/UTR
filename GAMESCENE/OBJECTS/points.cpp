#include "points.hpp"
#include "../spritetools.hpp"
#include "../player.hpp"
#include <string>
#include <sstream>
extern int speed;
extern int score;
extern sf::Font mainfont;
void points::init(){
    ptxt = findtextures("POINTS");
    sct.setFont(mainfont);
}

void points::moveAndRegen(){
    sf::Time temp = spawnclock.getElapsedTime();
    if(temp.asMilliseconds()- (rand()%2000) > 1000){
        sf::RectangleShape temp;
        temp.setTexture( &ptxt[(rand()&ptxt.size()-1)] );
        temp.setSize(sf::Vector2f(parentwindow->getSize().x*0.1, parentwindow->getSize().x*0.1));
        temp.setPosition(rand()%(int)(parentwindow->getSize().x*0.6-temp.getSize().x)+parentwindow->getSize().x*0.2,0);
        point.push_back(temp);
        spawnclock.restart();
    }
    temp = moveclock.restart();
    for(int i= 0; i < point.size(); i++){
        point[i].move(0, temp.asSeconds()*speed);
        parentwindow->draw(point[i]);
    }
    std::string cnt;
    std::ostringstream ss;
    ss << score;
    cnt ="Score: ";
    cnt += ss.str();
    sct.setString(cnt);
    sct.setPosition(parentwindow->getSize().x*0.95-sct.getGlobalBounds().width, 10);
    parentwindow->draw(sct);

    bool nodeletes = false;
    for(int j= 0; j< point.size(); j++){
        for(int i =0; i < point.size(); i++){
            if(point[i].getPosition().y > parentwindow->getSize().y){
                point.erase(point.begin()+i);
                break;
            }
        }
    }
}

void points::checkcollison(player player){
    sf::Rect<int> play(player.shape.getPosition().x, player.shape.getPosition().y, player.shape.getGlobalBounds().width, player.shape.getGlobalBounds().height);
    for(int j= 0; j< point.size(); j++){
        for(int i =0; i < point.size(); i++){
            sf::Rect<int> pnt(point[i].getPosition().x, point[i].getPosition().y, point[i].getSize().x, point[i].getSize().y);
            if(play.intersects(pnt)){
                score++;
                point.erase(point.begin()+i);
                break;
            }
        }
    }
}

points::points(sf::RenderWindow *window){
    parentwindow = window;
}

void points::eraseall(){
    point.erase(point.begin(), point.end());
}
