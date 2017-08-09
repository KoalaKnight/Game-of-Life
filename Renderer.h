#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include "Board.h"

class Renderer
{
public:
    void draw(Board* board);
private:
    int height;
};

#endif // RENDERER_H_INCLUDED
