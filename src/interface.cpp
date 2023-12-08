#include "interface.hpp"

Title::Title(sf::Vector2f position, sf::Vector2f size)
{
    texture.loadFromFile("resources\\title-bg.png");
    title.setTexture(&texture);
    title.setPosition(position);
    title.setSize(size);

    titleText.setString("STELLARIS MOD TRANSLATOR");
    titleText.setFont(font);
    titleText.setCharacterSize(50);
    titleText.setLetterSpacing(3);
    titleText.setOrigin(titleText.getLocalBounds().left + titleText.getLocalBounds().width / 2.0f,
                        titleText.getLocalBounds().top + titleText.getLocalBounds().height / 2.0f);
    titleText.setPosition(sf::Vector2f(position.x + size.x / 2.0f, position.y + size.y / 2.0f));
}

void Title::draw(sf::RenderWindow &window)
{
    window.draw(title);
    window.draw(titleText);
}

ModDisplay::ModDisplay(sf::Vector2f position, sf::Vector2f size)
{
    bgTexture.loadFromFile("resources\\mod-bg.png");
    bg.setTexture(&bgTexture);
    bg.setPosition(position);
    bg.setSize(size);
}

void ModDisplay::setName(std::string name)
{
    this->name.setString(name);
    this->name.setFont(font);
    this->name.setCharacterSize(30);
    this->name.setOrigin(this->name.getLocalBounds().left + this->name.getLocalBounds().width / 2.0f,
                         this->name.getLocalBounds().top + this->name.getLocalBounds().height / 2.0f);
    this->name.setPosition(sf::Vector2f(bg.getPosition().x + bg.getSize().x / 2.0f, bg.getPosition().y + 40));
}

void ModDisplay::setImage(std::string image)
{
    imageTexture.loadFromFile(image);
    this->image.setTexture(imageTexture);
    this->image.setTexture(imageTexture);
    this->image.setScale(210 / this->image.getLocalBounds().width,
                         210 / this->image.getLocalBounds().height);
    this->image.setPosition(sf::Vector2f(bg.getPosition().x + 10, bg.getPosition().y + 70));
}

void ModDisplay::setLocType(std::string locType)
{
    this->locType.setString(locType);
    this->locType.setFont(font);
    this->locType.setCharacterSize(30);
    this->locType.setOrigin(this->locType.getLocalBounds().left + this->locType.getLocalBounds().width / 2.0f,
                            this->locType.getLocalBounds().top + this->locType.getLocalBounds().height / 2.0f);
    this->locType.setPosition(sf::Vector2f(bg.getPosition().x + bg.getSize().x / 2.0f + 115, bg.getPosition().y + 185));
}

void ModDisplay::draw(sf::RenderWindow &window)
{
    window.draw(bg);
    window.draw(image);
    window.draw(name);
    window.draw(locType);
}

Button::Button(sf::Vector2f position, sf::Vector2f size, std::string str)
{
    texture.loadFromFile("resources\\main-button.png");
    textureSelected.loadFromFile("resources\\main-button-selected.png");
    button.setPosition(position);
    button.setSize(size);
    button.setTexture(&texture);

    buttonText.setString(str);
    buttonText.setFont(font);
    buttonText.setCharacterSize(40);
    buttonText.setOrigin(buttonText.getLocalBounds().left + buttonText.getLocalBounds().width / 2.0f,
                         buttonText.getLocalBounds().top + buttonText.getLocalBounds().height / 2.0f);
    buttonText.setPosition(sf::Vector2f(position.x + size.x / 2.0f, position.y + size.y / 2.0f));
}

void Button::handleEventInput(sf::Event event, sf::RenderWindow &window, std::string &path)
{
    if (button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,
                                          sf::Mouse::getPosition(window).y))
    {
        button.setTexture(&textureSelected);
        if (event.type == sf::Event::MouseButtonPressed)
            path = Interface::inputMod();
    }

    else
        button.setTexture(&texture);
}

void Button::handleEventLocalise(sf::Event event, sf::RenderWindow &window, Localisator localisator, Mod mod, int &code)
{
    if (button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,
                                          sf::Mouse::getPosition(window).y))
    {
        button.setTexture(&textureSelected);
        if (event.type == sf::Event::MouseButtonPressed)
            code = localisator.localise(mod);
    }

    else
        button.setTexture(&texture);
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(button);
    window.draw(buttonText);
}

std::string Interface::inputMod()
{
    std::cout << "Input mod path: ";
    std::string path;
    std::cin >> path;
    return path;
}

Interact::Interact(sf::Vector2f position, sf::Vector2f size)
    : input(sf::Vector2f(position.x + 30, position.y + 20), sf::Vector2f(280, 105), "input"),
      localise(sf::Vector2f(size.x / 2 - 140 + 40, position.y + 20), sf::Vector2f(280, 105), "localise"),
      translate(sf::Vector2f(size.x + -310 + 40, position.y + 20), sf::Vector2f(280, 105), "translate")
{
    texture.loadFromFile("resources\\interact-bg.png");
    interact.setTexture(&texture);
    interact.setPosition(position);
    interact.setSize(size);
}

void Interact::draw(sf::RenderWindow &window)
{
    window.draw(interact);
    input.draw(window);
    localise.draw(window);
    translate.draw(window);
}

Interface::Interface()
    : window(sf::VideoMode(WIDTH, HEIGHT), "Stellaris Mod Translator"),
      title(sf::Vector2f(40, 20), sf::Vector2f(1200, 200)),
      modDisplay(sf::Vector2f(40, 240), sf::Vector2f(1200, 295)),
      interact(sf::Vector2f(40, 555), sf::Vector2f(1200, 145))
{
    bg.loadFromFile("resources\\bg.png");
    sprite.setTexture(bg);
}

void Interface::mainLoop()
{
    std::string path;
    Parser parser;
    Mod mod;
    Localisator localisator;
    int code = -1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            interact.input.handleEventInput(event, window, path);
            interact.localise.handleEventLocalise(event, window, localisator, mod, code);

            if (!path.empty())
            {
                mod = parser.parse(path);
                path.clear();
                modDisplay.setName(mod.getName());
                modDisplay.setImage(mod.getImage());
                modDisplay.setLocType(mod.convertLocType());
            }

            if(code > -1)
            {
                mod.setLocType(code);
                modDisplay.setLocType(mod.convertLocType());
                code = -1;
            }
        }

        window.clear();
        window.draw(sprite);
        title.draw(window);
        modDisplay.draw(window);
        interact.draw(window);
        window.display();
    }
}

int main()
{
    font.loadFromFile("resources\\Orbitron-Regular.ttf");
    Interface interface;
    interface.mainLoop();
}