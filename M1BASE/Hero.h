//
// Created by Adam on 12/5/2023.
//



#ifndef UNTITLED_HERO_H
#define UNTITLED_HERO_H
#include "Object.h"
#include "GUN.h"
#include "Character.h"
#include "Potion.h"
#include"Monster.h"

class Hero:public Character {
    public:
        Gun* weapon;

    public:
        Hero(char t, int x, int y, int hp) ;

        Gun* getWeapon();
        void setWeapon(Gun* g);
        void operator + (Ammo a);
        void operator + (Potion p);
        void operator - (Monster m);
        friend ostream& operator << (ostream& out, Hero& hero);
        virtual void useSpecial() = 0;
~Hero();

};



#endif //UNTITLED_HERO_H
