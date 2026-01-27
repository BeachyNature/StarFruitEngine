#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class Player {
    public:
        Player() = default;
        Player(const std::string& name, int hp = 100)
            : name(name), hp(hp) {}
        void print() const;

    private:
        std::string name;
        int hp;
};

#endif
