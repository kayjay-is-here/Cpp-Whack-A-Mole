//
// Created by Kyle Lee on 4/29/23.
//

#ifndef FINAL_SCORE_H
#define FINAL_SCORE_H
#include <SFML/Graphics.hpp>

class Score {
private:
    int currentScore = 0;
public:
    Score();
    Score(sf::RenderWindow& window);
    int getCurrentScore() const;
    void setCurrentScore(int score);
    void addToCurrentScore(int score);

//private:
//    sf::Font font;
//    sf::Text scoreText;
//
//public:
//    sf::Text getScoreText() const;
//
//public:
//    virtual void eventHandler(sf::RenderWindow& window, sf::Event event);
//    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //FINAL_SCORE_H
