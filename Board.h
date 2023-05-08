//
// Created by Kyle Lee on 4/24/23.
//

#ifndef FINAL_BOARD_H
#define FINAL_BOARD_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "ColorSquare.h"
#include "AnimatedSprite.h"
#include "Moles.h"
#include <time.h>
#include <cmath>
#include "Score.h"

#define MIN_MOLES 10

class Board : public sf::Drawable
{
private:
    sf::Texture texture;
    std::vector<Moles> moles;
    void position(sf::RenderWindow& window);
    void reposition(sf::RenderWindow& window);
    Score score;

public:
    //default parameter
    Board();
    Board(sf::Vector2f size, sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void animate();
    void populateMoles();

private:
    sf::Font font;
    sf::Text scoreText;
    void setupScore(sf::RenderWindow& window);
};
#endif //FINAL_BOARD_H
