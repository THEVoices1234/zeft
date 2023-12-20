//
// Created by Adam on 12/5/2023.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H
using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Object.h"
#include "Hero.h"
#include "Potion.h"
#include "Ammo.h"
#include "TankMonster.h"
#include "GhostMonster.h"
#include "GUN_SUB.h"
#include "DemolitionHero.h"
#include "MedicHero.h"

class Game {
private:
    static const int rows = 15;
    static const int cols = 15;
     int round;
    Object* grid[rows][cols];
    Hero* hero;
    bool isOver;

public:
    Game() ;

    ~Game();

    void generateMap(Hero& h);

    void showMap();

    void startGame();

    void move (Hero& h,char direction);

    void fireGun(char direction);

    int checkGameOver();

    void updateMap();

    void  useGunSpecial();
    void play(Game g);

};


#endif //UNTITLED_GAME_H
