#pragma once
#include "Player.h"
#include <iostream>
class Board
{
private:
    char arr[3][3] = {
            {'1', '2','3'},
            {'4','5','6'},
            {'7','8','9'},
    };
public:

    Board() {}

    int getRow(int index);

    int getColumn(int index);

    bool isEmpty(int index);

    bool isFull();

    bool replaceChar(int index, Player* player);

    void draw();

    bool isPlayerWin(Player* player);


};

