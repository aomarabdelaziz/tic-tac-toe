#pragma once

#include "Player.h"
#include "Board.h"
#include <iostream>
#include <string>

class Game {
private:
    Board board;
    Player player1;
    Player player2;
    int count = 0;
public:
    void readPlayerData();

    void startGame();



};