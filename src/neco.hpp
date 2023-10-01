#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Neco {

private:
  float x, y;
  float sx, sy;
  sf::Texture texture;
  sf::Sprite sprite;
  sf::SoundBuffer sBuffer;
  sf::Sound sound;
  sf::Font font;
  sf::Text text;
  int edgeCount;
  bool isTextHidden;

  void initNeco();

public:
  Neco();

  void checkEdge(sf::Vector2f);
  void moveNeco();
  void setPosNeco();
  void burenyaa();
  void showText(sf::Vector2f);
  void setIsTextHidden(bool val);
  bool getIsTextHidden();

  sf::Sprite &draw();
  sf::Text &drawText();
};