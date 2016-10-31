#include "GAMESCENE/dottedlines.hpp"
#include "initialisers.hpp"
#include "maineventhandler.hpp"
#include "UI/selector.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <ctime>
#include <math.h>
#include <bitset>

sf::Font mainfont;
int speed;
sf::Clock mainclock;
sf::Time maintime;

int main(){
    srand ( time ( NULL ) );
    if(!mainfont.loadFromFile("Overdose Sunrise.otf"))
        std::cout << "Failed to load font file, please check this!" << std::endl;


    sf::RenderWindow mainwindow;
    short resx=800, resy=600;
    if(!prerunoptions(resx, resy))
        mainwindow.create(sf::VideoMode(resx, resy), "Ultra Typrovith Runaway", sf::Style::Titlebar | sf::Style::Close);
    else
        mainwindow.create(sf::VideoMode(resx, resy), "Ultra Typrovith Runaway", sf::Style::Titlebar | sf::Style::Fullscreen | sf::Style::Close);
    if(!mainfont.loadFromFile("3Dventure.ttf"))
        std::cout << "Failed to load font file, please check this!" << std::endl;


    bool gamestarted = false;
    selector mainwindowselectors;
    initmenubuttons(mainwindow, mainwindowselectors);
    sf::Texture menutxt;
    menutxt.loadFromFile("IMG/mainmenu.png");
    sf::Sprite menubg;
    menubg.setTexture(menutxt);
    menubg.setPosition({0,0});
    menubg.setScale(resx/menubg.getLocalBounds().width, resy/menubg.getLocalBounds().height);

    sf::Music mainmusic;
    mainmusic.openFromFile("adventure_meme.ogg");
    mainmusic.play();
    mainmusic.setLoop(true);

    lines line;
    initdrawableelements(line, mainwindow);
    while(mainwindow.isOpen()){
        if(!gamestarted){
            switch(handlemenuevents(mainwindow, mainwindowselectors)){
            case 1:
                gamestarted = true;
                break;
            }
            mainwindow.clear();
            mainwindow.draw(menubg);
            drawalluielements(mainwindow, &mainwindowselectors);
            mainwindow.display();
        }
        else{
            movegameelements(line);
            speed = log(mainclock.getElapsedTime().asMilliseconds());
            speed+= 100;
            mainwindow.clear(sf::Color(0,0,0));
            drawgameelements(mainwindow, line);
            mainwindow.display();
        }
    };
    return 0;
}
