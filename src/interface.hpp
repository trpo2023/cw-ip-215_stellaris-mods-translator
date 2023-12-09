#ifndef H_INTERFACE
#define H_ITNERFACE

#include "parser.hpp"
#include "localisator.hpp"
#include "translator.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720

sf::Font font;

class Title
{
    sf::RectangleShape title;
    sf::Texture texture;
    sf::Text text;

public:
    Title(sf::Vector2f position, sf::Vector2f size);

    void draw(sf::RenderWindow &window);
};

class ModDisplay
{
    sf::RectangleShape bg;
    sf::Texture bgTexture;
    sf::Sprite image;
    sf::Texture imageTexture;
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
    sf::Text text;

public:
    Button(sf::Vector2f position, sf::Vector2f size, std::string str);

    void handleEventInput(sf::Event event, sf::RenderWindow &window, bool &inputPath);
    void handleEventLocalise(sf::Event event, sf::RenderWindow &window, Localisator localisator, Mod mod, int &code);
    void handleEventTranslate(sf::Event event, sf::RenderWindow &window, bool &inputApi);
    void draw(sf::RenderWindow &window);
};

class TextField
{
    sf::RectangleShape field;
    sf::Texture texture;
    sf::Clock clock;
    sf::Text cursor;
    sf::Text text;

public:
    TextField(sf::Vector2f position, sf::Vector2f size);

    void handleEvent(sf::Event event, std::string &path, bool &enter, bool &input);
    void draw(sf::RenderWindow &window);
};

class Interact
{
    sf::RectangleShape interact;
    sf::Texture texture;

public:
    Button inputButton;
    Button localiseButton;
    Button translateButton;
    TextField textField;

    Interact(sf::Vector2f position, sf::Vector2f size);
    void draw(sf::RenderWindow &window, bool input, bool inputKey);
};

class Interface
{
    sf::RenderWindow window;
    sf::Sprite sprite;
    sf::Texture bg;

    Title title;
    ModDisplay modDisplay;
    Interact interact;

public:
    Interface();

    void mainLoop();
};

#endif