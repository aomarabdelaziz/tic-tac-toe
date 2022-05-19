#include "Board.h"

int Board::getRow(int index)
{
    return (index - 1) / 3;
}
int Board::getColumn(int index)
{
    return (index - 1) % 3;
}
bool Board::isEmpty(int index)
{
    if (index < 1 || index > 9) return false;
    int row = getRow(index);
    int column = getColumn(index);

    if (this->arr[row][column] == 'x' || this->arr[row][column] == 'o') {
        return false;
    }
    return true;
}
bool Board::isFull()
{
    bool full = true;
    for (int i = 1; i <= 9; ++i) {
        if (isEmpty(i))
        {
            full = false;
            break;
        }
    }
    return full;


}
bool Board::replaceChar(int index, Player* player) {
    if (index < 1 || index > 9) return false;

    if (isEmpty(index))
    {
        int row = getRow(index);
        int column = getColumn(index);
        this->arr[row][column] = player->getOp();
        return true;
    }
    return false;

}
void Board::draw() {
    for (int i = 0; i < 3; ++i) {
        std::cout << "-----------------" << std::endl;
        for (int j = 0; j < 3; ++j) {
            std::cout << "| " << arr[i][j] << "  ";
        }
        std::cout << " |" << std::endl;
    }
    std::cout << "-----------------" << std::endl;
}

bool Board::isPlayerWin(Player* player) {
    if (this->arr[0][0] == player->getOp() && this->arr[0][1] == player->getOp() && this->arr[0][2] == player->getOp())
        return true;
    if (this->arr[1][0] == player->getOp() && this->arr[1][1] == player->getOp() && this->arr[1][2] == player->getOp())
        return true;
    if (this->arr[2][0] == player->getOp() && this->arr[2][1] == player->getOp() && this->arr[2][2] == player->getOp())
        return true;
    if (this->arr[0][0] == player->getOp() && this->arr[1][0] == player->getOp() && this->arr[2][0] == player->getOp())
        return true;
    if (this->arr[0][1] == player->getOp() && this->arr[1][1] == player->getOp() && this->arr[2][1] == player->getOp())
        return true;
    if (this->arr[0][2] == player->getOp() && this->arr[1][2] == player->getOp() && this->arr[2][2] == player->getOp())
        return true;
    if (this->arr[0][0] == player->getOp() && this->arr[1][1] == player->getOp() && this->arr[2][2] == player->getOp())
        return true;
    if (this->arr[0][2] == player->getOp() && this->arr[1][1] == player->getOp() && this->arr[2][0] == player->getOp())
        return true;
    return false;
}
