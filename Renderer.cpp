#include "Renderer.h"

#include "Display.h"

void Renderer::draw(Board* board)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(Display::CELL_WIDTH, Display::CELL_HEIGHT));
    rectangle.setFillColor(sf::Color(255, 255, 255, 255));
    for(int y = 0; y < board->columns; y++)
    {
        for(int x = 0; x < board->rows; x++)
        {
            if(board->getState(x, y))
            {
                rectangle.setPosition(x * Display::CELL_WIDTH, Display::HEIGHT - (y * Display::CELL_HEIGHT));
                Display::draw(rectangle);
            }
        }
    }
}
