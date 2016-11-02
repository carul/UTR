#include "GAMESCENE/dottedlines.hpp"
#include "GAMESCENE/spritetools.hpp"
#include "GAMESCENE/OBJECTS/policemans.hpp"
#include "GAMESCENE/OBJECTS/surroundings.hpp"
#include "GAMESCENE/OBJECTS/obstacles.hpp"
#include "GAMESCENE/player.hpp"
#include "initialisers.hpp"
#include "maineventhandler.hpp"
#include "UI/selector.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <math.h>

sf::Font mainfont;
int speed;
sf::Clock mainclock;
sf::Time maintime;

player player;
int main(){
    srand ( time ( NULL ) );
    if(!mainfont.loadFromFile("Overdose Sunrise.otf"))
        std::cout << "Failed to load font file, please check this!" << std::endl;


    sf::RenderWindow mainwindow;
    short resx=800, resy=600;
    int *temp = new int(prerunoptions(resx, resy));
    if(!(*temp == 1 || *temp == 3))
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
    if(*temp >=2){
        mainmusic.openFromFile("adventure_meme.ogg");
        mainmusic.play();
        mainmusic.setLoop(true);
    }
    delete temp;
    lines line;
    initdrawableelements(line, mainwindow);

    sf::Event event;

    player.posx = 2;
    player.posy = resy/2-player.shape.getLocalBounds().height/2;
    player.shape.setPosition(mainwindow.getSize().x/2-player.shape.getLocalBounds().width/2, player.posy);
    initplayertxt(player, mainwindow.getSize());
    policeman man1, man2, man3;
    initpolicemans(man1, 1, mainwindow.getSize());
    initpolicemans(man2, 2, mainwindow.getSize());
    initpolicemans(man3, 3, mainwindow.getSize());
    surrounding surroundings;
    surroundings.init(mainwindow.getSize());
    obstacles obstacles(mainwindow.getSize());
    sf::Texture def;
    sf::RectangleShape defs, defs2;
    def.loadFromFile("IMG/defaulttxt.png");
    defs.setTexture(&def);
    defs2.setTexture(&def);
    defs.setSize(sf::Vector2f(mainwindow.getSize().x*0.2 ,mainwindow.getSize().y));
    defs2.setSize(sf::Vector2f(mainwindow.getSize().x*0.2 ,mainwindow.getSize().y));
    defs.setOrigin(mainwindow.getSize().x*0.2 ,mainwindow.getSize().y);
    defs.rotate(180);
    defs.setPosition(0,0);
    defs2.setPosition(mainwindow.getSize().x-defs2.getSize().x, 0);
    while(mainwindow.isOpen()){
        if(!gamestarted){
            switch(handlemenuevents(mainwindow, mainwindowselectors)){
            case 1:
                gamestarted = true;
                obstacles.clock.restart();
                break;
            }
            mainwindow.clear();
            mainwindow.draw(menubg);
            drawalluielements(mainwindow, &mainwindowselectors);
            mainwindow.display();
        }
        else{
            obstacles.init();
            obstacles.moveall();
            movegameelements(line);
            while(mainwindow.pollEvent(event)){
                switch(event.type){
                case sf::Event::Closed:
                    mainwindow.close();
                    break;
                case sf::Event::KeyPressed:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                        if(player.posx != 1 && !player.ismoving)
                            resetmovement(player, false);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                        if(player.posx!=3 && !player.ismoving)
                            resetmovement(player, true);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                        player.ismovingvert = true;
                        player.vertpassed.restart();
                        player.MoveDirUp = true;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                        player.ismovingvert = true;
                        player.vertpassed.restart();
                        player.MoveDirUp = false;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                        mainwindow.close();
                    if(player.isinair == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                        player.isinair = true;
                        player.jumpc.restart();
                    }
                    break;

                case sf::Event::KeyReleased:
                    if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
                        player.ismovingvert = false;
                     break;
                }
            }
            managemovement(player, mainwindow.getSize());
            if(player.posy > mainwindow.getSize().y - man2.shape.getGlobalBounds().height*1.2)
                player.posy = mainwindow.getSize().y - man2.shape.getGlobalBounds().height*1.2;
            speed = log(mainclock.getElapsedTime().asMilliseconds());
            speed += 100;
            mainwindow.clear(sf::Color(0,0,0));
            drawgameelements(mainwindow, line, player.shape);
            obstacles.drawall(mainwindow);
            mainwindow.draw(defs);
            mainwindow.draw(defs2);
            mainwindow.draw(player.shape);
            drawpolice(mainwindow, man1, man2, man3);
            surroundings.drawinwindow(mainwindow);
            if(obstacles.collide(player))
                mainwindow.close();
            mainwindow.display();
        }
    };
    return 0;
}
