//
// Created by Adam on 12/5/2023.
//

#ifndef UNTITLED_GHOSTMONSTER_H
#define UNTITLED_GHOSTMONSTER_H


#include "Monster.h"

class GhostMonster : public Monster {
private:
    bool isVisible;
public:
    GhostMonster(char t, int x, int y, int hp);

    bool isVisibleOnMap() const;
    void setVisible(const bool&& v);

};

#endif //UNTITLED_GHOSTMONSTER_H
