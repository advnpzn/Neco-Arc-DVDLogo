#include "neco.hpp"
#include <time.h>

int main()
{
    Neco neco;
    bool s;

    sf::RenderWindow window(sf::VideoMode(800.f, 500.f), "mitochondria", sf::Style::Close);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        s = neco.getIsTextHidden();
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::S)
                {
                    if (neco.getIsTextHidden() == true)
                    {
                        neco.setIsTextHidden(false);
                    }
                    else
                    {
                        neco.setIsTextHidden(true);
                    }
                }

            default:
                break;
            }
        }

        neco.moveNeco();
        sf::Vector2f coords = sf::Vector2f(window.getSize().x, window.getSize().y);
        neco.checkEdge(coords);
        neco.setPosNeco();
        neco.showText(coords);
        window.clear();
        window.draw(neco.draw());
        if (neco.getIsTextHidden() == false)
        {
            window.draw(neco.drawText());
        }
        window.display();
    }

    return 0;
}