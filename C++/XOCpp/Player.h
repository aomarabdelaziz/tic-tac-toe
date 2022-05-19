#pragma once

#include <string>
class Player
{
private:
    std::string Name;
    char Op;
public:

    Player() {};

    Player(const std::string& name, char op);

    const std::string& getName() const;

    void setName(const std::string& name);

    char getOp() const;

    void setOp(char op);

};

