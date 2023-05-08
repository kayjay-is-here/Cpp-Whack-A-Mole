//
// Created by Kyle Lee on 4/29/23.
//

#include "Score.h"

Score::Score()
{

}

Score::Score(sf::RenderWindow& window)
{
    setCurrentScore(0);

//    // Set up the font
//    font.loadFromFile("Fonts/arial.ttf");
//    scoreText.setFont(font);
//    scoreText.setFillColor(sf::Color::White);
//    scoreText.setOutlineColor(sf::Color::Black);
//    scoreText.setCharacterSize(50);
//    scoreText.setPosition(window.getSize().x - 100, 20); // Adjust the position to fit your needs
}

void Score::setCurrentScore(int score)
{
    this->currentScore = score;
}

int Score::getCurrentScore() const
{
    return this->currentScore;
}

void Score::addToCurrentScore(int amount)
{
    this->currentScore += amount;
}

//sf::Text Score::getScoreText() const {
//    return scoreText;
//}

//void Score::eventHandler(sf::RenderWindow &window, sf::Event event)
//{
//    scoreText.setString(std::to_string(currentScore));
//}
//
//void Score::draw(sf::RenderTarget& window, sf::RenderStates states) const
//{
//    window.draw(scoreText);
//}