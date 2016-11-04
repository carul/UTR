#include "GAMESCENE/dottedlines.hpp"
#include "GAMESCENE/spritetools.hpp"
#include "GAMESCENE/OBJECTS/policemans.hpp"
#include "GAMESCENE/OBJECTS/surroundings.hpp"
#include "GAMESCENE/OBJECTS/obstacles.hpp"
#include "GAMESCENE/OBJECTS/points.hpp"
#include "GAMESCENE/player.hpp"
#include "initialisers.hpp"
#include "maineventhandler.hpp"
#include "UI/selector.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <SFML/System.hpp>
#include <iostream>
#include <math.h>

sf::Font mainfont;
int speed;
sf::Clock mainclock;
sf::Time maintime;
int score;

enum{
    FINISH_WINDOW,
    GAME_WINDOW,
    MAINMENU,
    PAUSE
};

player player;
int main(){
    srand ( time ( NULL ) );

    int activewindow = MAINMENU;

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

    points points(&mainwindow);

    bool gamestarted = false;
    bool firstinit = true;
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

    bool paused;

    sf::Event event;

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
    while(mainwindow.isOpen()){
        if(activewindow == MAINMENU){
            score = 0;
            switch(handlemenuevents(mainwindow, mainwindowselectors)){
            case 1:
                activewindow = GAME_WINDOW;
                obstacles.clock.restart();
                break;
            }
            mainwindow.clear();
            mainwindow.draw(menubg);
            drawalluielements(mainwindow, &mainwindowselectors);
            mainwindow.display();
        }
        else if(activewindow == GAME_WINDOW){
            if(firstinit){
                points.init();
                initdrawableelements(line, mainwindow);
                resetvars(player, obstacles, mainwindow);
                firstinit = false;
                defs.setTexture(&def);
                defs2.setTexture(&def);
                defs.setSize(sf::Vector2f(mainwindow.getSize().x*0.2 ,mainwindow.getSize().y));
                defs2.setSize(sf::Vector2f(mainwindow.getSize().x*0.2 ,mainwindow.getSize().y));
                defs.setOrigin(mainwindow.getSize().x*0.2 ,mainwindow.getSize().y);
                defs.rotate(180);
                defs.setPosition(0,0);
                defs2.setPosition(mainwindow.getSize().x-defs2.getSize().x, 0);
            }
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
                    if(sf::Keyboard::isKeyPressed((sf::Keyboard::P))){
                        activewindow = PAUSE;
                        paused = false;
                    }
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
            points.moveAndRegen();
            points.checkcollison(player);
            if(obstacles.collide(player)){
                gamestarted = false;
                resetvars(player, obstacles, mainwindow);
                resetimages(defs, defs2, line, mainwindow);
                mainwindow.clear();
                activewindow = FINISH_WINDOW;
                firstinit = true;
                points.eraseall();
            }
            mainwindow.display();
        }
        else if(activewindow == FINISH_WINDOW){
            mainwindow.clear();
            while(mainwindow.pollEvent(event)){
                switch(event.type){
                case sf::Event::Closed:
                    mainwindow.close();
                    break;
                case sf::Event::KeyPressed:
                    activewindow = MAINMENU;
                    break;
                }
            }
            sf::Text tmp;
            tmp.setString("GAME OVER");
            tmp.setFont(mainfont);
            tmp.setCharacterSize(300);
            tmp.setScale(mainwindow.getSize().x*0.8/tmp.getLocalBounds().width, mainwindow.getSize().y*0.2/tmp.getLocalBounds().height);
            tmp.setPosition(mainwindow.getSize().x/2-tmp.getGlobalBounds().width/2, mainwindow.getSize().y*0.1);
            mainwindow.draw(tmp);
            std::string cnt;
            std::ostringstream ss;
            ss << score;
            cnt ="SCORE: ";
            cnt += ss.str();
            tmp.setString(cnt);
            tmp.setScale(mainwindow.getSize().x*0.6/tmp.getLocalBounds().width, mainwindow.getSize().y*0.2/tmp.getLocalBounds().height);
            tmp.setPosition(mainwindow.getSize().x/2-tmp.getGlobalBounds().width/2, mainwindow.getSize().y*0.5);
            mainwindow.draw(tmp);
            mainwindow.display();
        }
        else if(activewindow == PAUSE){
            if(!paused){
                sf::RectangleShape trect;
                trect.setSize(sf::Vector2f(mainwindow.getSize().x, mainwindow.getSize().y));
                trect.setPosition(0,0);
                trect.setFillColor(sf::Color(255,255,255, 150));
                sf::Text tmp;
                tmp.setString("PAUSE");
                tmp.setFont(mainfont);
                tmp.setCharacterSize(300);
                tmp.setColor(sf::Color(0,0,255));
                tmp.setScale(mainwindow.getSize().x*0.8/tmp.getLocalBounds().width, mainwindow.getSize().y*0.2/tmp.getLocalBounds().height);
                tmp.setPosition(mainwindow.getSize().x/2-tmp.getGlobalBounds().width/2, mainwindow.getSize().y*0.1);
                mainwindow.draw(trect);
                mainwindow.draw(tmp);
                mainwindow.display();
                paused = true;
            }
                while(mainwindow.pollEvent(event)){
                    switch(event.type){
                    case sf::Event::Closed:
                        mainwindow.close();
                        break;
                    case sf::Event::KeyPressed:
                        activewindow = GAME_WINDOW;
                        paused = false;
                        break;
                    }
                }
        }
    };
    return 0;
}
