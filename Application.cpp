#include "Application.h"

#include <SFML/System/Clock.hpp>

#include "Display.h"
#include "Renderer.h"
#include "Board.h"

Application::Application()
{
    Display::init();
}

void Application::runMainLoop()
{
    sf::Clock clock;
    Renderer renderer;
    Board board;
    float time = 0.0;
    while(Display::isOpen())
    {
        time += clock.restart().asSeconds();
        Display::checkWindowEvents();

        Display::clear();

        if(time > 0.05)
        {
            board.update();
            time = 0.0;
        }

        renderer.draw(&board);

        Display::display();
    }
}
