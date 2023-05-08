//
// Created by Kyle Lee on 4/24/23.
//

#ifndef FINAL_ANIMATEDSPRITE_H
#define FINAL_ANIMATEDSPRITE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>


class AnimatedSprite :  public sf::Sprite
{
private:
    unsigned int width, height;
    sf::IntRect intRect;
public:
    //for the animated character can change direction
    AnimatedSprite();
    AnimatedSprite(sf::Texture &texture, int rows, int cols);
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void setup(sf::Texture &texture, int rows, int cols);
    void setupIntRect(sf::Vector2u imgSize, int rows, int cols);

public:
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event);
};



#endif //FINAL_ANIMATEDSPRITE_H
