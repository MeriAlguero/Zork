#pragma once
#ifndef GAME_H
#define GAME_H

#include "Room.h"
#include "Player.h"

class Game {
private:
    Room* livingRoom, * kitchen, * bedroom, * secretRoom, * bathroom;
    Player player;

public:
    Game();
    ~Game();
    void start();
};

#endif
