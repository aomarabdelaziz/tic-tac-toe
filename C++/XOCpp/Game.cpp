#include "Game.h"


void Game::readPlayerData() {
    std::string name;
    char op;
    std::cout << "Please Player 1 Name:";
    std::cin >> name;
    std::cout << "Please Player 1 Operator 'x' | 'o' :";
    std::cin >> op;
    this->player1.setName(name);
    this->player1.setOp(op);

    std::cout << "Please Player 2 Name:";
    std::cin >> name;
    this->player2.setName(name);
    this->player2.setOp((op == 'x' ? 'o' : 'x'));
}

void Game::startGame() {

    this->readPlayerData();
    this->board.draw();
    while (!this->board.isFull())
    {

        Player currentPlayer = player1;
        if (count % 2 == 1) currentPlayer = player2;

        while (true) {
            std::cout << currentPlayer.getName() << " : Please Enter number range from 1 to 9" << std::endl;
            int index;
            std::cin >> index;
            if (this->board.replaceChar(index, &currentPlayer))
            {
                break;
            }


        }

        this->board.draw();
        if (this->board.isPlayerWin(&currentPlayer)) {

            std::cout << currentPlayer.getName() << " " << "is the winner" << std::endl;
            break;
        }
        count++;


        if (this->board.isFull()) {
            std::cout << "Game Draw";
        }
    }

}