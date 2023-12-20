//
// Created by Adam on 12/5/2023.
//

#ifndef UNTITLED_CHARACTER_H
#define UNTITLED_CHARACTER_H
#include "Object.h"

class Character : public Object {
protected:
    int positionX;
    int positionY;
    int healthPoints;
public:
    Character(char t, int x, int y, int hp);

    int getPositionX();

    int getPositionY();

    int getHealthPoints();

    void setPosition(int x, int y);

    void setHealthPoints(int hp);



};


#endif //UNTITLED_CHARACTER_H
