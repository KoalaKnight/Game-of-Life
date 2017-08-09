#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace Display
{
    void init();

    void clear();
    void display();
    void checkWindowEvents();
    void draw(sf::Drawable& drawable);
    bool isOpen();

    constexpr int HEIGHT = 1000;
    constexpr int WIDTH = 1000;
    constexpr int CELL_HEIGHT = 3;
    constexpr int CELL_WIDTH = 3;
}

#endif // DISPLAY_H_INCLUDED
