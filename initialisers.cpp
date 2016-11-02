#include "initialisers.hpp"
#include "GAMESCENE/dottedlines.hpp"
#include "GAMESCENE/player.hpp"
#include "UI/selector.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

extern player player;

int prerunoptions(short &resx, short &resy){
    sf::RenderWindow *setup = new sf::RenderWindow(sf::VideoMode(650, 600), "Ultra Typrovith Runaway Setup");
    selector *presetupselectors = new selector;
    presetupselectors->createnew(200, 100, "Start", 0, 450, setup, {0, 0, 255}, true, "START");
    presetupselectors->createnew(150, 50, "res1", 50, 50, setup, {0, 0, 255}, false, "800x600", "selectres");
    presetupselectors->createnew(150, 50, "res2", 250, 50, setup, {0, 0, 255}, false, "1280x720", "selectres");
    presetupselectors->createnew(150, 50, "res3", 450, 50, setup, {0, 0, 255}, false, "1366x768", "selectres");
    presetupselectors->createnew(150, 50, "res4", 50, 150, setup, {0, 0, 255}, false, "1280x800", "selectres");
    presetupselectors->createnew(150, 50, "res5", 250, 150, setup, {0, 0, 255}, false, "1024x768", "selectres");
    presetupselectors->createnew(150, 50, "res6", 450, 150, setup, {0, 0, 255}, false, "1920x1080", "selectres");
    presetupselectors->createnew(150, 50, "res7", 50, 250, setup, {0, 0, 255}, false, "1440x900", "selectres");
    presetupselectors->createnew(150, 50, "res8", 250, 250, setup, {0, 0, 255}, false, "1600x900", "selectres");
    presetupselectors->createnew(150, 50, "res9", 450, 250, setup, {0, 0, 255}, false, "1280x900", "selectres");
    presetupselectors->createnew(400, 50, "flscr", 0, 350, setup, {0, 0, 255}, true, "Enable fullscreen?", "");
    presetupselectors->createnew(100, 50, "sound", 50, 450, setup, {0, 0, 255}, false, "Sound", "");
    sf::Event event;
    std::vector <int> clicked;
    while(setup->isOpen()){
        clicked = presetupselectors->getselectedids();
        while(setup->pollEvent(event)){
            switch(event.type){
            case sf::Event::Closed:
                setup->close();
                break;
            case sf::Event::MouseButtonPressed:
                UIactifclicked(*setup, event, presetupselectors);
                break;
            }
        }
        setup->clear();
        drawalluielements(*setup, presetupselectors);
        setup->display();
        int tempa = 0;
        for(int i = 0; i < clicked.size(); i++){
            if (clicked[i] == 11 || clicked[i]== 10){
                tempa++;
            }
        }
        for(int i = 0; i < clicked.size(); i++){
            if (clicked[i] == 0 && clicked.size() > tempa+1){
                setup->close();
                break;
            }
            else if(clicked[i]==0){
                presetupselectors->unclick(0);
            }
        }
    }
    int iffull = false;
    for(int i = 0; i < clicked.size(); i++){
        if(clicked[i] != 10 && clicked[i] != 0)
            switch(clicked[i]){
            case 1:
                resx = 800;
                resy = 600;
                break;
            case 2:
                resx = 1280;
                resy = 720;
                break;
            case 3:
                resx = 1366;
                resy = 768;
                break;
            case 4:
                resx = 1280;
                resy = 800;
                break;
            case 5:
                resx = 1024;
                resy = 768;
                break;
            case 6:
                resx = 1920;
                resy = 1080;
                break;
            case 7:
                resx = 1440;
                resy = 900;
                break;
            case 8:
                resx = 1600;
                resy = 900;
                break;
            case 9:
                resx= 1280;
                resy= 900;
            }
        else if(clicked[i] == 10)
            iffull = true;
    }
    if(clicked[clicked.size()-1] == 11)
        iffull+=2;
    delete presetupselectors;
    delete setup;
    return iffull;
}

bool initmenubuttons(sf::RenderWindow &window, selector &selector){
    selector.createnew(window.getSize().x/5, window.getSize().y/10, "START", window.getSize().x, window.getSize().y*0.2, &window, {0, 0, 255}, true, "START", "" );
    selector.createnew(window.getSize().x/5, window.getSize().y/10, "EXIT", window.getSize().x, window.getSize().y*0.4, &window, {0, 0, 255}, true, "EXIT", "");
}

void drawalluielements(sf::RenderWindow &window, selector *selectors){
    selectors->drawallinparentwindow(window);
}

void UIactifclicked(sf::RenderWindow &window, sf::Event event, selector *selectors, bool oneclick){
    selectors->procclick(event.mouseButton.x, event.mouseButton.y, oneclick);
}

void initdrawableelements(lines &lines, sf::RenderWindow &window){
    lines.initialise(window);
}

void drawgameelements(sf::RenderWindow &window, lines lines, sf::Sprite shape){
    lines.drawintargetwindow(window);
    //window.draw(shape);
}

void movegameelements(lines &lines){
    lines.move();
}
