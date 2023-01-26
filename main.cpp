#include <iostream>
#include <vector>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 535

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Bouncing Baloon!!!");
    window.setFramerateLimit(60);
    int dx = 5, dy = 5;
    sf::Texture t1, t2;
    t1.loadFromFile("images/ball.jpg");
    t2.loadFromFile("images/sky.png");
    sf::Sprite background(t2), ball(t1);
    float ballWidth = ball.getLocalBounds().width;
    float ballHeight = ball.getLocalBounds().height;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (ball.getPosition().x > (SCREEN_WIDTH - ballWidth))
        {
            dx = -5;
        }
        else if (ball.getPosition().x < 0)
        {
            dx = 5;
        }

        if (ball.getPosition().y > (SCREEN_HEIGHT - ballHeight))
        {
            dy = -5;
        }
        else if (ball.getPosition().y < 0)
        {
            dy = 5;
        }

        ball.move(dx, dy);
        window.clear();
        window.draw(background);
        window.draw(ball);
        window.display();
    }

    return 0;
}
