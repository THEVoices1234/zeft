//
// Created by Adam on 12/5/2023.
//

#ifndef UNTITLED_DEMOLITIONHERO_H
#define UNTITLED_DEMOLITIONHERO_H



#include "Hero.h"

class DemolitionHero : public Hero {
private :
    Gun* weapon2;
public:
    DemolitionHero(char t, int x, int y, int hp);
    Gun* getWeapon2();
    void setWeapon2(Gun* g);
    void useSpecial();

};




#endif //UNTITLED_DEMOLITIONHERO_H
