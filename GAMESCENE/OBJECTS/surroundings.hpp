#ifndef SURROUNDINGS_H
#define SURROUNDINGS_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class surrounding{
    public:
    std::vector<sf::Texture> textures;
    sf::Clock clock;
    int pos[4];
    sf::Sprite surr[4];
    public:
    void init(sf::Vector2u size);
    void drawinwindow(sf::RenderWindow &window);
};
#endif // SURROUNDINGS_H
