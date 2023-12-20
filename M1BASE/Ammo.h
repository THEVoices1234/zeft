//
// Created by Adam on 12/5/2023.
//

#ifndef UNTITLED_AMMO_H
#define UNTITLED_AMMO_H


#include "Item.h"

class Ammo : public Item {
private:
    int bullets;
public:
    Ammo(int b);

    int getBullets() const;
    ~Ammo();


};



#endif //UNTITLED_AMMO_H
