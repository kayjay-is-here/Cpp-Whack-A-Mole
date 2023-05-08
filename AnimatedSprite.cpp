//
// Created by Kyle Lee on 4/24/23.
//

//TODO Put most of these functions in Moles class and inherit from AnimatedSprite
//TODO create timer for how long a mole stays in idle state and how long in hidden state
//TODO Implement perspective by creating 4 possible rows, and then linking a certain y position and scale for each of those
#include "AnimatedSprite.h"
AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::AnimatedSprite(sf::Texture &texture, int rows, int cols)
{
    setup(texture, rows, cols);
}

void AnimatedSprite::setup(sf::Texture &texture, int rows, int cols)
{
    width = texture.getSize().x;
    height = texture.getSize().y;
    setTexture(texture);
    setupIntRect(texture.getSize(), rows, cols);
}

void AnimatedSprite::setupIntRect(sf::Vector2u imgSize, int rows, int cols)
{

    intRect.width = std::round(width / static_cast<float>(cols));
    intRect.height = std::round(height / static_cast<float>(rows));
    intRect.left = 0;
    intRect.top = 0;
    setTextureRect(intRect);
}



void AnimatedSprite::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Sprite s = (*this);
    target.draw(s);
}

