#include "neco.hpp"
#include <string>

Neco::Neco()
{
    initNeco();
}

auto Neco::initNeco() -> void
{
    x = rand() % 300;
    y = rand() % 300;

    sx = 2.f;
    sy = 2.f;

    isTextHidden = true;
    edgeCount = 0;

    if (!font.loadFromFile("res/raleway-m.ttf"))
    {
        std::cout << "Error loading font file :(\n";
    }
    text.setFont(font);
    text.setCharacterSize(15);
    text.setPosition(sf::Vector2f(10.f, 10.f));

    if (!texture.loadFromFile("res/neco-arc.png"))
    {
        std::cout << "Error loading texture from file :(\n";
    }
    texture.setSmooth(true);

    if (!sBuffer.loadFromFile("res/burenyaa.wav"))
    {
        std::cout << "Error loading audio file :( \n";
    }
    sound.setBuffer(sBuffer);
    sound.setVolume(10.f);

    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(x, y));
    sprite.setScale(sf::Vector2f(0.2f, 0.2f));
}

auto Neco::checkEdge(sf::Vector2f windowCoords) -> void
{
    if (x + (texture.getSize().x * 0.2) >= windowCoords.x)
    {
        sx = -sx;
        burenyaa();
        edgeCount++;
    }

    if (x <= 0)
    {
        sx = -sx;
        burenyaa();
        edgeCount++;
    }

    if (y + (texture.getSize().y * 0.2) >= windowCoords.y)
    {
        sy = -sy;
        burenyaa();
        edgeCount++;
    }

    if (y <= 0)
    { 
        sy = -sy;
        burenyaa();
        edgeCount++;
    }
}

auto Neco::moveNeco() -> void
{
    x += sx;
    y += sy;
}

auto Neco::setPosNeco() -> void
{
    sprite.setPosition(x, y);
}

void Neco::burenyaa()
{
    sound.play();
}

sf::Sprite& Neco::draw()
{
    return sprite;
}

auto Neco::showText(sf::Vector2f coords) -> void
{
    std::string wcoords = "Window coords = (" + std::to_string(int(coords.x)) + ", " + std::to_string(int(coords.y)) + ")\n";
    std::string xy = "(x, y) = (" + std::to_string(int(x)) + ", " + std::to_string(int(y)) + ")\n";
    std::string edgec = "Edge Count = " + std::to_string(edgeCount) + "\n";
    text.setString(wcoords+xy+edgec);

}

void Neco::setIsTextHidden(bool val)
{
    isTextHidden = val;
}

bool Neco::getIsTextHidden()
{
    return isTextHidden;
}

sf::Text& Neco::drawText()
{
    return text;
}