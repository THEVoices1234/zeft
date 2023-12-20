//
// Created by Adam on 12/5/2023.
//

#ifndef UNTITLED_GUN_H
#define UNTITLED_GUN_H
#include <string>

class Hero;
using namespace std;
class Gun {
private:
    string name;
    int bullets;
    int damage;
    int range;

public:
    Gun( string n, int b, int d, int r);

    string getName();

    int getBullets();

    int getDamage();

    int getRange();
    void setBullets(const int b);
    friend ostream& operator <<(std::ostream &out, const Gun &c);
    void useSpecial(Hero& h1 , Object** map);

};
#endif //UNTITLED_GUN_H
