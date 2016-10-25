#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "initialisers.hpp"
#include "UI/selector.hpp"

bool prerunoptions(){
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
    presetupselectors->createnew(150, 50, "res9", 450, 250, setup, {0, 0, 255}, false, "1280x800", "selectres");
    presetupselectors->createnew(400, 50, "res9", 0, 350, setup, {0, 0, 255}, true, "Enable fullscreen?", "");
    sf::Event event;
    while(setup->isOpen()){
        setup->clear();
        drawalluielements(*setup, presetupselectors);
        setup->display();
    }
    delete presetupselectors;
    delete setup;
}

void drawalluielements(sf::RenderWindow &window, selector *selectors){
    selectors->drawallinparentwindow(window);
}
