//
// Created by Kyle Lee on 4/24/23.
//

#include "Board.h"


Board::Board()
{
    srand(time(nullptr));
}
Board::Board(sf::Vector2f size, sf::RenderWindow& window)
{
    //mole square
    texture.loadFromFile("Sprites/mole.png");
    populateMoles();
    position(window);
    setupScore(window);



}

void Board::setupScore(sf::RenderWindow& window)
{
    score = Score(window);

    // Could not get the text to load when stored in Score.cpp; it segfaults when i load the font
    font.loadFromFile("Fonts/arial.ttf");
    scoreText.setFont(font);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setOutlineColor(sf::Color::Black);
    scoreText.setOutlineThickness(3);
    scoreText.setCharacterSize(50);
    scoreText.setPosition(window.getSize().x - 300, 20); // Adjust the position to fit your needs

}
void Board::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for(int i = 0; i < moles.size(); i++)
    {
        window.draw(moles[i]);
    }

    //window.draw(score.getScoreText());
    window.draw(scoreText);
}
void Board::position(sf::RenderWindow& window)
{

//    sf::FloatRect b = {position().x, position().y, moles.at(0).getSize().x, moles.at(0).getSize().y};
    sf::FloatRect b = moles[0].getGlobalBounds();
    int lastLocation = (rand() % 700) % (window.getSize().x - 300);

    for (size_t i = 0; i < moles.size(); i++)
    {
        int row = rand() % 3;
        int newLocation = (rand() % 700) % (window.getSize().x - 100);
//        float size = moles[i].getTexture()->getSize().x * moles[i].getScale().x;
//        if (abs(newLocation - lastLocation) < size)
//        {
//            newLocation += 300;
//            newLocation = newLocation % (window.getSize().x - 100);
//        }

        switch (row)
        {
            case 0:
                moles[i].setScale({0.3, 0.3});
                moles[i].setPosition(newLocation, b.top + 150);
                break;
            case 1:
                moles[i].setScale({0.4, 0.4});
                moles[i].setPosition(newLocation, b.top + 250);
                break;
            case 2:
                moles[i].setPosition(newLocation, b.top + 350);
        }

        //lastLocation = newLocation;
    }
}

void Board::eventHandler(sf::RenderWindow& window, sf::Event event)
{
    populateMoles();

    for(int i = 0; i < moles.size(); i++)
    {
        moles[i].eventHandler(window, event);
    }

    //score.eventHandler(window, event);
    scoreText.setString("Score: " + std::to_string(score.getCurrentScore()));

}

void Board::populateMoles()
{
    int i = 0;
    while(moles.size() < MIN_MOLES)
    {
        //animates the sprites
        moles.push_back(Moles(texture, 4, 4, &score));
        (moles.begin() + i)->setTexture(texture); // This is just moles[i], i just wanted to see if i could do this and i can
        //multiply x and y
        (moles.begin() + i)->setScale(.5, .5);
        i++;
    }


}
void Board::animate()
{
    //animate the moles
    for(int i = 0; i < moles.size(); i++)
    {
        //moles.at(i).animate();
        moles[i].animate();
    }
}
