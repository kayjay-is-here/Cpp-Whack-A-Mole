//
// Created by Kyle Lee on 4/24/23.
//

//TODO Put most of these functions in Moles class and inherit from AnimatedSprite
//TODO Prevent moles from spawning within each other

#include "Moles.h"

Moles::Moles()
{
}
Moles::Moles(sf::Texture &texture, int rows, int cols, Score* refScore)
{
    setup(texture, rows, cols);
    getBuffer().loadFromFile("Audio/vine_boom.wav");
    this->pScore = refScore;
}

void Moles::setup(sf::Texture &texture, int rows, int cols)
{
    width = texture.getSize().x;
    height = texture.getSize().y;
    setTexture(texture);
    setupIntRect(texture.getSize(), rows, cols);
}

void Moles::setCurrentState(State state)
{
    this->currentState = state;
}
void Moles::setCurrentState(State state, int startingFrame)
{
    this->currentState = state;
    intRect.left = startingFrame * intRect.width;
}

void Moles::animate()
{
    update();




    int animationRow;

    switch(currentState)
    {
        case State::SPAWNING:
        case State::IDLE:
            animationRow = 0;
            break;
        case State::DIZZY:
            animationRow = 1;
            break;
        case State::DISAPPEARING:
        case State::HIDING:
            animationRow = 3;
            break;
        default:
            animationRow = 4;
    }
    intRect.top = animationRow * intRect.height;


    if(clock.getElapsedTime().asMilliseconds() > animationTimeIncrement)
    {
        if(true /*currentState == State::SPAWNING || currentState == State::DISAPPEARING || currentState == State::DIZZY*/)
        {
            if (intRect.left + intRect.width >= width)
            {
                if (currentState == State::SPAWNING)
                {
                    currentState = State::IDLE;
                    setStateTimer((rand() % 5)+ 0.5f);
                }

                if (currentState == State::DIZZY) {
                    currentState = State::DISAPPEARING;
                    intRect.left = 0;
                }

                if (currentState == State::DISAPPEARING) {
                    currentState = State::HIDING;
                    setStateTimer((rand() % 5)+ 5);
                }

            }
            else
                intRect.left += intRect.width;
        }
        clock.restart();
        setTextureRect(intRect);
    }
}


void Moles::setupIntRect(sf::Vector2u imgSize, int rows, int cols)
{

    intRect.width = std::round(width / static_cast<float>(cols));
    intRect.height = std::round(height / static_cast<float>(rows));
    intRect.left = 0;
    intRect.top = 0;
    setTextureRect(intRect);
}

int Moles::getTime() const
{
    return animationTimeIncrement;
}

void Moles::setTime(int time)
{
    Moles::animationTimeIncrement = time;
}

void Moles::update()
{

    if(currentState == State::IDLE)
    {
        if(stateClock.getElapsedTime().asSeconds() > stateTimer)
        {
            stateClock.restart();
            currentState = State::DISAPPEARING;
            intRect.left = 0;
        }
    }
    else if(currentState == State::HIDING)
    {
        if(stateClock.getElapsedTime().asSeconds() > stateTimer)
        {
            stateClock.restart();
            currentState = State::SPAWNING;
            intRect.left = 0;
        }
    }

}

void Moles::eventHandler(sf::RenderWindow& window, sf::Event event)
{

    update();
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2f mpos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
        if (getGlobalBounds().contains(mpos))
        {
            if (!(currentState == State::HIDING || currentState == State::DISAPPEARING || currentState == State::DIZZY))
            {
                // TODO: Implement score adding.
                setCurrentState(State::DIZZY, 0);
                playBoom();

                pScore->addToCurrentScore(10);

            }
        }
    }
}


int Moles::getMaxMoles() const
{
    return maxMoles;
}

void Moles::setMaxMoles(int maxMoles)
{
    this->maxMoles = maxMoles;
}

State Moles::getCurrentState()
{
    return currentState;
}

void Moles::playBoom()
{
    sound.setBuffer(buffer);
    sound.play();
}

void Moles::setStateTimer(int stateTimer)
{
    this->stateTimer = stateTimer;
}

int Moles::getStateTimer() const
{
    return stateTimer;
}