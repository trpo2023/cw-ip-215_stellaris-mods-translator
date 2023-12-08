#ifndef H_INTERFACE
#define H_ITNERFACE

#include "parser.hpp"
#include "localisator.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720

sf::Font font;

class Title
{
    sf::RectangleShape title;
    sf::Texture texture;
    sf::Text titleText;

public:
    Title(sf::Vector2f position, sf::Vector2f size);

    void draw(sf::RenderWindow &window);
};

class ModDisplay
{
    sf::RectangleShape bg;
    sf::Texture bgTexture;
    sf::Texture imageTexture;
    sf::Sprite image;
    sf::Text name;
    sf::Text locType;

public:
    ModDisplay(sf::Vector2f position, sf::Vector2f size);
    void setName(std::string name);
    void setImage(std::string image);
    void setLocType(std::string locType);

    void draw(sf::RenderWindow &window);
};

class Button
{
    sf::RectangleShape button;
    sf::Texture texture;
    sf::Texture textureSelected;
    sf::Text buttonText;

public:
    Button(sf::Vector2f position, sf::Vector2f size, std::string str);

    void handleEventInput(sf::Event event, sf::RenderWindow &window, std::string &path);
    void handleEventLocalise(sf::Event event, sf::RenderWindow &window, Localisator localisator, Mod mod, int &code);
    void draw(sf::RenderWindow &window);
};

class Interact
{
    sf::RectangleShape interact;
    sf::Texture texture;

public:
    Button input;
    Button localise;
    Button translate;

    Interact(sf::Vector2f position, sf::Vector2f size);
    void draw(sf::RenderWindow &window);
};

class Interface
{
    sf::RenderWindow window;
    sf::Texture bg;
    sf::Sprite sprite;

    Title title;
    ModDisplay modDisplay;
    Interact interact;

public:
    Interface();
    
    static std::string inputMod();
    void mainLoop();
};

#endif