#include "spritetools.hpp"
#include "player.hpp"
#include <dirent.h>
#include <string.h>
#include <iostream>
std::vector <sf::Texture> findtextures(std::string folder){
    std::vector<sf::Texture> out;
    std::vector<std::string> names;
    DIR *dir;
    std::string temp="IMG/";
    temp+= folder;
    temp+="/";
    sf::Texture temptxt;
    struct dirent *ent;
    if ((dir = opendir (temp.c_str())) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if(strcmp(ent->d_name, ".") && strcmp(ent->d_name, "..")){
                names.push_back(ent->d_name);
            }
        }
        closedir (dir);
    }
    std::sort(names.begin(), names.end());
    for(int i = 0; i < names.size(); i++){
        temptxt.loadFromFile(temp+names[i]);
        out.push_back(temptxt);
    }
    return out;
}

void animatetexture(std::vector<sf::Texture> &txt, sf::Sprite &sprite, int &active){
    if(active >= 0){
        if( active <  txt.size()){
            sprite.setTexture(txt[active+1]);
            active+=1;
        }
        if( active == txt.size()){
            sprite.setTexture(txt[0]);
            active = 0;
        }
    }
}

void drawpolice(sf::RenderWindow &window, policeman &man1, policeman &man2, policeman &man3){
    if(man1.animationp.getElapsedTime().asMilliseconds() > 100){
        animatetexture(man1.texture, man1.shape, man1.activetxt);
        man1.animationp.restart();
    }
    if(man2.animationp.getElapsedTime().asMilliseconds() > 100){
        animatetexture(man2.texture, man2.shape, man2.activetxt);
        man2.animationp.restart();
    }
    if(man3.animationp.getElapsedTime().asMilliseconds() > 100){
        animatetexture(man3.texture, man3.shape, man3.activetxt);
        man3.animationp.restart();
    }
    window.draw(man1.shape);
    window.draw(man2.shape);
    window.draw(man3.shape);
}
