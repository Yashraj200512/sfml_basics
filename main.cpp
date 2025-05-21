// playing with window and time and learning basic commands
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// main program

int main()
{ // create window
    sf::Window window;
    window.create(sf::VideoMode({800, 800}), "my window", sf::Style::Default);
    // window.setPosition({50,50});
    // window.setSize({1000,1000});
    // sf::Vector2u size = window.getSize();
    // auto [width, height] = size;
    while (window.isOpen())
    {

        while (const auto event = window.pollEvent()) // const std::optional event or const auto event
        {
            if (const auto* textEntered = event->getIf<sf::Event::TextEntered>())
{
    if (textEntered->unicode < 128)
        std::cout << "ASCII character typed: " << static_cast<char>(textEntered->unicode) << std::endl;
}

            
            if (const auto *resized = event->getIf<sf::Event::Resized>())
            {
                std::cout << "new width: " << resized->size.x << std::endl;
                std::cout << "new height: " << resized->size.y << std::endl;
            }

            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto *keypressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keypressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window.close();
                }
            }
        }
    }

    return 0;
}
