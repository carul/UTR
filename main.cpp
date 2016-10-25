#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "initialisers.h"
#include <ctime>
#include <cmath>

sf::Font mainfont;

int main(){
    srand ( time ( NULL ) );
    if(!mainfont.loadFromFile("Overdose Sunrise.otf")){
        std::cout << "Failed to load font file, please check this!" << std::endl;
    }
    prerunoptions();
    return 0;
}
