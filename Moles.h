//
// Created by Kyle Lee on 4/24/23.
//

#ifndef FINAL_Mole_H
#define FINAL_Mole_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include "AnimatedSprite.h"
#include "Score.h"
enum class State
{
    SPAWNING,
    DIZZY,
    DISAPPEARING,
    IDLE,
    HIDING
};

class Moles : public sf::Sprite
{
private:
    sf::Clock clock;
    sf::Clock stateClock;
    int animationTimeIncrement = 250; // in milliseconds
    sf::IntRect intRect;
    State currentState = State::SPAWNING;
    int maxMoles = 8;
    Score* pScore; // I'm using a pointer here because references have to be initialized

public:
    int getMaxMoles() const;
    void setMaxMoles(int maxMoles);
public:
    State getCurrentState();
    void setCurrentState(State state);
    void setCurrentState(State state, int startingFrame);

private:
    unsigned int width, height;
    bool moving = true;
public:
    int getTime() const;

    void setTime(int time);

private:
    //set up the squares
    void setup(sf::Texture &texture, int rows, int cols);
    void setupIntRect(sf::Vector2u imgSize, int rows, int cols);
public:
    //for the animated character can change direction
    Moles();
    Moles(sf::Texture &texture, int rows, int cols, Score* scoreRef);
public:
    void eventHandler(sf::RenderWindow &window, sf::Event event) /*override*/;
    //animate the whole thing
    void animate();
    void update();

private:
    sf::SoundBuffer buffer;
    sf::Sound sound;

public:
    sf::SoundBuffer& getBuffer()
    {
        return buffer;
    }

    sf::Sound& getSound()
    {
        return sound;
    }

    void playBoom();

private:
    int stateTimer = 5; //in seconds

public:
    void setStateTimer(int stateTimer);
    int getStateTimer() const;
};



#endif //FINAL_Mole_H
