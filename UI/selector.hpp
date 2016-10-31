#ifndef SELECTOR_H
#define SELECTOR_H
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

extern sf::Font mainfont;

typedef struct color{
    short r,g,b;
};

typedef struct selectors_data{
    sf::RectangleShape square;
    int id;
    std::string name;
    sf::RenderWindow *parentwindow;
    sf::Text buttontext;
    std::string group;
    bool clicked = false;
};

class selector{
    std::vector <selectors_data> selectors;
    public:
    bool createnew(int width, int height, std::string name, int posx, int posy, sf::RenderWindow *parentwindow, color rgb = {255,0,255}, bool center = false, std::string text = "", std::string group="");
    void removeall();
    std::string getname(int id);
    void drawallinparentwindow(sf::RenderWindow &parentwindow);
    void procclick(int x, int y, bool oneclick = false);
    std::vector<int> getselectedids();
    int getsizeofvector(std::vector<selectors_data> selectors);
    void setinactive(int id);
    void unclick(int id);
};
#endif // SELECTOR_H
