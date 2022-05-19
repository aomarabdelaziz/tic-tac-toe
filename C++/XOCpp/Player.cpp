#include "Player.h"



Player::Player(const std::string& name, const char op)
{
    this->Name = name;
    this->Op = op;

}

const std::string& Player::getName() const {
    return this->Name;
}

void Player::setName(const std::string& name) {
    this->Name = name;
}

char Player::getOp() const {
    return this->Op;
}

void Player::setOp(char op) {
    this->Op = op;
}



