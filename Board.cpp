#include "Board.h"

#include "Util/Random.h"
#include "Display.h"

Board::Board()
{
    rows = Display::HEIGHT / Display::CELL_HEIGHT;
    columns = Display::WIDTH / Display::CELL_WIDTH;
    Random::init();
    for(int y = 0; y < rows; y++)
    {
        for(int x = 0; x < columns; x++)
        {
            if(Random::floatInRange(0.0, 1.0) > 0.8)
            {
                board.push_back(true);
                boardUpdate.push_back(true);
            }
            else
            {
                board.push_back(false);
                boardUpdate.push_back(false);
            }
        }
    }
}

void Board::update()
{
    for(int y = 0; y < rows; y++)
    {
        for(int x = 0; x < columns; x++)
        {
            if(board[getIndex(x, y)])
            {
                int num = numberOfLiveNeighbours(x, y);
                if(num < 2)
                {
                    boardUpdate[getIndex(x, y)] = false;
                }
                else if(num > 1 && num < 4)
                {
                    boardUpdate[getIndex(x, y)] = true;
                }
                else
                {
                    boardUpdate[getIndex(x, y)] = false;
                }
            }
            else
            {
                if(numberOfLiveNeighbours(x, y) == 3)
                {
                    boardUpdate[getIndex(x, y)] = true;
                }
                else
                {
                    boardUpdate[getIndex(x, y)] = false;
                }
            }
        }
    }
    board = boardUpdate;
}

bool Board::getState(int x, int y)
{
    return board[getIndex(x, y)];
}


int Board::getIndex(int x, int y)
{
    return x + (y * columns);
}

int Board::numberOfLiveNeighbours(int x, int y)
{
    int total = 0;
    int cx = x;
    int cy = y - 1;
    //Check Bellow
    if(cy > 0)
    {
        if(board[getIndex(cx, cy)])
        {
            total++;
        }
        //Check Bottom Right
        cx = x + 1;
        if(cx < columns)
        {
            if(board[getIndex(cx, cy)])
            {
                total++;
            }
        }
        //Check Bottom Left
        cx = x - 1;
        if(cx > 0)
        {
            if(board[getIndex(cx, cy)])
            {
                total++;
            }
        }
    }
    //Check Right
    cx = x + 1;
    cy = y;
    if(cx < columns)
    {
        if(board[getIndex(cx, cy)])
        {
            total++;
        }
    }
    //Check Left
    cx = x - 1;
    if(cx > 0)
    {
        if(board[getIndex(cx, cy)])
        {
            total++;
        }
    }
    //Check Above
    cx = x;
    cy = y + 1;
    if(cy < rows)
    {
        if(board[getIndex(cx, cy)])
        {
            total++;
        }
        //Check Above Right
        cx = x + 1;
        if(cx < columns)
        {
            if(board[getIndex(cx, cy)])
            {
                total++;
            }
        }
        //Check Above Left
        cx = x - 1;
        if(cx > 0)
        {
            if(board[getIndex(cx, cy)])
            {
                total++;
            }
        }
    }
    return total;
}
