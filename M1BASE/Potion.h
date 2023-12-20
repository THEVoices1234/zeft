//
// Created by Adam on 12/5/2023.
//

#ifndef UNTITLED_POTION_H
#define UNTITLED_POTION_H


#include "Item.h"

class Potion : public Item {
private:
    int healingAmount;
public:
    Potion(int ha) ;

    int getHealingAmount() const;
    ~Potion();
};

#endif //UNTITLED_POTION_H
