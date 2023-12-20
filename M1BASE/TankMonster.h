//
// Created by Adam on 12/5/2023.
//

#ifndef UNTITLED_TANKMONSTER_H
#define UNTITLED_TANKMONSTER_H


#include "Monster.h"

class TankMonster : public Monster {
private:
    int shield;
public:
    TankMonster(char t, int x, int y, int hp, int s) ;
    int getShield() const;

};


#endif //UNTITLED_TANKMONSTER_H
