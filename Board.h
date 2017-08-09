#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>

class Board
{
public:
    Board();

    void update();
    bool getState(int x, int y);

    int rows, columns;
private:
    int getIndex(int x, int y);
    int numberOfLiveNeighbours(int x, int y);

    std::vector<bool> board;
    std::vector<bool> boardUpdate;
};

#endif // BOARD_H_INCLUDED
