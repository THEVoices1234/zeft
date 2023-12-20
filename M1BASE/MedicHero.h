//
// Created by Adam on 12/5/2023.
//

#ifndef UNTITLED_MEDICHERO_H
#define UNTITLED_MEDICHERO_H


#include "Hero.h"


class MedicHero : public Hero {
private:
    int healingAmount;
    bool isSpecial;
public:
    MedicHero(char t, int x, int y, int hp,int ha);

    int getHealingAmount();
    void useSpecial();
};




#endif //UNTITLED_MEDICHERO_H
