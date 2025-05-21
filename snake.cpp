#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <windows.h>

#include <random> // for std::mt19937 (random no. generator)
#include <chrono>
 sf::RenderWindow window;
std::mt19937 mt{static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())};

std::uniform_int_distribution<int> Xapple{0, 799};
std::uniform_int_distribution<int> Yapple{0, 599};

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
Direction direction;
class snake
{
public:
    float x;
    float y;
    std::vector<std::pair<float, float>> body;
    snake() : x(30), y(30) {}
    void initialize()
    {
        body.push_back({x, y});
        body.push_back({x - 30, y});
        body.push_back({x - 60, y});
    }

    void move(int dir)
    {

        for (int k = body.size(); k > 1; k--)
        {
            body[k - 1] = body[k - 2];
        }
        switch (dir)
        {
        case RIGHT:
        {
            body[0].first += 30;
            break;
        }
        case LEFT:
        {
            body[0].first -= 30;
            break;
        }
        case UP:
        {
            body[0].second -= 30;
            break;
        }
        case DOWN:
        {
            body[0].second += 30;
            break;
        }
        }
    }
};

class food
{
public:
    std::vector<std::pair<int, int>> vector;

    void spawn()
    {
        int X = Xapple(mt);
        int Y = Yapple(mt);

        int remainderX = X % 30;
        X = X - remainderX;

        int remainderY = Y % 30;
        Y = Y - remainderY;

        vector.push_back({X, Y});
    }

    void respawn(snake &s)
    {
        int X = vector[0].first;
        int Y = vector[0].second;
         
        vector.pop_back();
    
        spawn();

        s.body.push_back({X, Y});
    }
};

int main()
{
    snake s;
    food f;
    direction = RIGHT;
   
    window.create(sf::VideoMode({800, 600}), "SNAKE GAME");

    sf::CircleShape circle(15.f);
    circle.setPointCount(30);
    circle.setFillColor(sf::Color::Green);

    s.initialize();

    sf::Texture texture("download.png"); // Throws sf::Exception if an error occurs
    texture.setSmooth(true);
    sf::Sprite sprite(texture);
    sf::Vector2u textureSize = texture.getSize(); // e.g., 100x100

    float scaleX = 30.0f / textureSize.x;
    float scaleY = 30.0f / textureSize.y;
    sprite.setScale({scaleX, scaleY});

    f.spawn();

    sprite.setPosition({float(f.vector[0].first), float(f.vector[0].second)});

    while (window.isOpen())
    {
        sprite.setPosition({float(f.vector[0].first), float(f.vector[0].second)});
        while (const auto event = window.pollEvent())
        {

            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto *keypressed = event->getIf<sf::Event::KeyPressed>())
            {

                if (keypressed->scancode == sf::Keyboard::Scancode::D)
                {
                    s.move(RIGHT);
                    direction = RIGHT;
                }

                if (keypressed->scancode == sf::Keyboard::Scancode::W)
                {
                    s.move(UP);
                    direction = UP;
                }
                if (keypressed->scancode == sf::Keyboard::Scancode::A)
                {
                    s.move(LEFT);
                    direction = LEFT;
                }

                if (keypressed->scancode == sf::Keyboard::Scancode::S)
                {
                    s.move(DOWN);
                    direction = DOWN;
                }
            }
        }
       
        switch (direction)
        {
        case RIGHT:
        {
            s.move(RIGHT);
            break;
        }
        case LEFT:
        {
            s.move(LEFT);
            break;
        }
        case UP:
        {
            s.move(UP);
            break;
        }
        case DOWN:
        {
            s.move(DOWN);
            break;
        }
        }

        window.clear(sf::Color::White);
         window.draw(sprite);
        for (auto element : s.body)
        {
            circle.setPosition({element.first, element.second});
            window.draw(circle);
        }
        

        if (s.body[0].first == f.vector[0].first && s.body[0].second == f.vector[0].second || s.body[1].first == f.vector[0].first && s.body[1].second == f.vector[0].second)
        {
            std::cout << s.body[0].first << f.vector[0].first;
            f.respawn(s);
        }

        window.display();
        Sleep(300);
    }
    return 0;
}
