// playing with window and time to learn sfml
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// main program

int main()
{ // create window
    float i=1,j=1;
    sf::RenderWindow window;
    window.create(sf::VideoMode({800, 800}), "my window", sf::Style::Default);
   sf::Texture texture("download.png"); // Throws sf::Exception if an error occurs
  texture.setSmooth(true);
   sf::Sprite sprite(texture);
   
   sprite.setScale({0.5f, 0.5f});
   sprite.setPosition({500, 500});

    while (window.isOpen())
    {

        while (const auto event = window.pollEvent()) // const std::optional event or const auto event
        {


            window.clear(sf::Color::White);
            // sf::CircleShape shape(50.f);
            // shape.setFillColor(sf::Color::Red);
            // shape.setPointCount(100);
            // shape.setPosition(sf::Vector2f(100.f, 150.f));  // ✅ This is correct
// inside the main loop, between window.clear() and window.display()
window.draw(sprite);
            // window.draw(shape);
            window.display();

            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto *keypressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keypressed->scancode == sf::Keyboard::Scancode::D)
                {
                    sprite.move({i++,0});

                }
                
                if (keypressed->scancode == sf::Keyboard::Scancode::S)
                {
                    sprite.move({0,j++});

                }
            }
        }
    }

    return 0;
}
