//
// Created by Kyle Lee on 4/24/23.
//

#include "Application.h"
#include <iostream>
#include "AnimatedSprite.h"

void Application::run()
{

    //sf is like std but it is for sfml
    sf::RenderWindow window({950, 500, 32}, "Whack-a-mole!");
    window.setFramerateLimit(60);
//    const int squareSize = 100, boardPositionX = 50, boardPositionY = 50;

    //b is our board
    Board b({359, 359}, window);
    sf::Cursor cursor;
    sf::Image cursorImage;

    if(!cursorImage.loadFromFile("Sprites/hammer.png"))
    {
        throw std::runtime_error("Cannot load hammer.");
    }

    sf::Texture field;
    field.loadFromFile("Sprites/backgroud.png");
    AnimatedSprite background(field, 1, 1);
    while(window.isOpen())
    {
        if(cursor.loadFromPixels(cursorImage.getPixelsPtr(), {32, 32}, {0,0}))
        {
            window.setMouseCursor(cursor);
        }
        //event listener (waiting for an event to occur) input
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            b.eventHandler(window, event);
        }

        b.animate();
        window.clear();
        window.draw(background);
        window.draw(b);
        window.display();
    }
}