#include "interface.hpp"

Title::Title(sf::Vector2f position, sf::Vector2f size)
{
    texture.loadFromFile("resources\\title-bg.png");
    title.setTexture(&texture);
    title.setPosition(position);
    title.setSize(size);

    text.setString("STELLARIS MOD TRANSLATOR");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setLetterSpacing(3);
    text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f,
                   text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
    text.setPosition(sf::Vector2f(position.x + size.x / 2.0f, position.y + size.y / 2.0f));
}

void Title::draw(sf::RenderWindow &window)
{
    window.draw(title);
    window.draw(text);
}

ModDisplay::ModDisplay(sf::Vector2f position, sf::Vector2f size)
{
    bgTexture.loadFromFile("resources\\mod-bg.png");
    bg.setTexture(&bgTexture);
    bg.setPosition(position);
    bg.setSize(size);

    name.setPosition(sf::Vector2f(bg.getPosition().x + bg.getSize().x / 2.0f,
                                  bg.getPosition().y + 40));

    image.setPosition(sf::Vector2f(bg.getPosition().x + 10,
                                   bg.getPosition().y + 70));
                                   
    locType.setPosition(sf::Vector2f(bg.getPosition().x + bg.getSize().x / 2.0f + 115,
                                     bg.getPosition().y + 185));
}

void ModDisplay::setName(std::string name)
{
    this->name.setString(name);
    this->name.setFont(font);
    this->name.setCharacterSize(30);
    this->name.setOrigin(this->name.getLocalBounds().left + this->name.getLocalBounds().width / 2.0f,
                         this->name.getLocalBounds().top + this->name.getLocalBounds().height / 2.0f);
}

void ModDisplay::setImage(std::string image)
{
    imageTexture.loadFromFile(image);
    this->image.setTexture(imageTexture);
    this->image.setTextureRect(sf::IntRect(0, 0, imageTexture.getSize().x, imageTexture.getSize().y));
    this->image.setScale(210.0f / this->image.getLocalBounds().width,
                         210.0f / this->image.getLocalBounds().height);
}

void ModDisplay::setLocType(std::string locType)
{
    this->locType.setString(locType);
    this->locType.setFont(font);
    this->locType.setCharacterSize(30);
    this->locType.setOrigin(this->locType.getLocalBounds().left + this->locType.getLocalBounds().width / 2.0f,
                            this->locType.getLocalBounds().top + this->locType.getLocalBounds().height / 2.0f);
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
    button.setTexture(&texture);
    button.setPosition(position);
    button.setSize(size);

    text.setString(str);
    text.setFont(font);
    text.setCharacterSize(40);
    text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f,
                   text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
    text.setPosition(sf::Vector2f(position.x + size.x / 2.0f, position.y + size.y / 2.0f));
}

void Button::setDefault()
{
    button.setTexture(&texture);
}

void Button::setSelected()
{
    button.setTexture(&textureSelected);
}

sf::FloatRect Button::getButtonGlobalBounds()
{
    return button.getGlobalBounds();
}

void InputButton::handleEvent(sf::Event event, sf::RenderWindow &window, bool &inputPath)
{
    if (getButtonGlobalBounds().contains(sf::Mouse::getPosition(window).x,
                                          sf::Mouse::getPosition(window).y))
    {
        setSelected();
        if (event.type == sf::Event::MouseButtonPressed)
            inputPath = 1;
    }

    else
        setDefault();
}

void LocaliseButton::handleEvent(sf::Event event, sf::RenderWindow &window, bool &localise)
{
    if (getButtonGlobalBounds().contains(sf::Mouse::getPosition(window).x,
                                          sf::Mouse::getPosition(window).y))
    {
        setSelected();
        if (event.type == sf::Event::MouseButtonPressed)
            localise = 1;
    }

    else
        setDefault();
}

void TranslateButton::handleEvent(sf::Event event, sf::RenderWindow &window, bool &inputKey)
{
    if (getButtonGlobalBounds().contains(sf::Mouse::getPosition(window).x,
                                          sf::Mouse::getPosition(window).y))
    {
        setSelected();
        if (event.type == sf::Event::MouseButtonPressed)
            inputKey = 1;
    }

    else
        setDefault();
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(button);
    window.draw(text);
}

TextField::TextField(sf::Vector2f position, sf::Vector2f size)
    : text("", font, 25), cursor("|", font, 25)
{
    texture.loadFromFile("resources\\input.png");
    field.setTexture(&texture);
    field.setPosition(position);
    field.setSize(size);
    text.setPosition(position + sf::Vector2f(10, 10));
    cursor.setPosition(position);
}

void TextField::handleEvent(sf::Event event, std::string &text, bool &input)
{
    cursor.setPosition(this->text.getGlobalBounds().width + this->text.getPosition().x,
                       this->text.getPosition().y);
    if (event.type == sf::Event::TextEntered)
    {
        sf::String str;
        switch (event.text.unicode)
        {
        case 8:
            if (this->text.getString().getSize() > 0)
            {
                str = this->text.getString();
                str.erase(str.getSize() - 1);
                this->text.setString(str);
            }
            break;

        case 13:
            input = 0;
            text = this->text.getString();
            this->text.setString("");
            break;

        case 22:
            str = this->text.getString();
            str += sf::Clipboard::getString();
            this->text.setString(str);
            break;

        case 26:
            this->text.setString("");
            break;

        default:
            str = this->text.getString();
            str += event.text.unicode;
            this->text.setString(str);
        }
    }

    if (event.key.code == sf::Keyboard::Escape)
    {
        input = 0;
        this->text.setString("");
    }
}

void TextField::draw(sf::RenderWindow &window)
{
    window.draw(field);
    window.draw(text);

    if (clock.getElapsedTime().asSeconds() > 0.5f)
    {
        window.draw(cursor);

        if (clock.getElapsedTime().asSeconds() > 1.0f)
            clock.restart();
    }
}

Bottom::Bottom(sf::Vector2f position, sf::Vector2f size)
{
    texture.loadFromFile("resources\\interact-bg.png");
    interact.setTexture(&texture);
    interact.setPosition(position);
    interact.setSize(size);
}

void Bottom::draw(sf::RenderWindow &window)
{
    window.draw(interact);
}

Interface::Interface()
    : window(sf::VideoMode(1280, 720), "Stellaris Mod Translator"),
      title(sf::Vector2f(40, 20), sf::Vector2f(1200, 200)),
      modDisplay(sf::Vector2f(40, 240), sf::Vector2f(1200, 295)),
      bottom(sf::Vector2f(40, 555), sf::Vector2f(1200, 145)),
      inputButton(sf::Vector2f(70, 575), sf::Vector2f(280, 105), "input"),
      localiseButton(sf::Vector2f(1200 / 2 - 140 + 40, 575), sf::Vector2f(280, 105), "localise"),
      translateButton(sf::Vector2f(1200 + -310 + 40, 575), sf::Vector2f(280, 105), "translate"),
      textField(sf::Vector2f(70, 605), sf::Vector2f(1140, 50))
{
    bg.loadFromFile("resources\\bg.png");
    sprite.setTexture(bg);
}

void Interface::mainLoop()
{
    std::string path;
    std::string key;

    Parser parser;
    Mod mod;
    Localisator localisator;
    Translator translator;

    int code = -1;
    bool inputPath = 0;
    bool inputKey = 0;
    bool localise = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (inputPath)
                textField.handleEvent(event, path, inputPath);

            else if (inputKey)
                textField.handleEvent(event, key, inputKey);

            else if(localise)
            {
                code = localisator.localise(mod);
                localise = 0;
            }

            else
            {
                inputButton.handleEvent(event, window, inputPath);
                if (mod.getLocType() > 1)
                {
                    localiseButton.handleEvent(event, window, localise);
                    translateButton.handleEvent(event, window, inputKey);
                }
            }

            if (!key.empty())
            {
                key.clear();

                translator.connect();
                translator.setKey(key);
                code = translator.localise(mod);
            }

            if (!path.empty())
            {
                mod = parser.parse(path);
                path.clear();

                if (mod.getLocType() > -1)
                {
                    modDisplay.setName(mod.getName());
                    modDisplay.setImage(mod.getImage());
                    modDisplay.setLocType(mod.convertLocType());
                }

                else
                {
                    modDisplay.setName("incorrect input");
                    modDisplay.setImage("resources\\error.jpg");
                    modDisplay.setLocType("incorrect input");
                }
            }

            if (code > -1)
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
        bottom.draw(window);

        if (inputPath || inputKey)
            textField.draw(window);

        else
        {
            inputButton.draw(window);
            localiseButton.draw(window);
            translateButton.draw(window);
        }

        window.display();
    }
}

int main()
{
    font.loadFromFile("resources\\Orbitron-Regular.ttf");
    Interface ui;
    ui.mainLoop();
}