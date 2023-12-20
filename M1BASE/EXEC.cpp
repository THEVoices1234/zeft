//
// Created by Adam on 12/5/2023.
//

#include "Ammo.h"
#include "Character.h"
#include "DemolitionHero.h"
#include "string"
#include "GUN_SUB.h"
#include "MedicHero.h"
#include "Potion.h"
#include "Monster.h"
#include "TankMonster.h"
#include "GhostMonster.h"
#include "Game.h"
#include "Item.h"
#include <random>
#include<iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

//OBJECT METHODS
char Object::getType() const {
    return type;
}
Object::Object(char t): type(t) {}
void Object::setType(const char &&t) {
    type = t;
}
Object::~Object(){

}
//ITEM METHODS
Item:: Item(char t) : Object(t) {}

Item::~Item() {


}

//AMMO METHODS
Ammo:: Ammo(int b) : Item('A'), bullets(b) {}
int Ammo:: getBullets() const {
    return bullets;
}

Ammo::~Ammo() {

}

//POTION METHODS
Potion::Potion(int ha) : Item('P'), healingAmount(ha) {}
int Potion::getHealingAmount() const {
    return healingAmount;
}

Potion::~Potion() {

}

//GUN METHODS
Gun::Gun( string n, int b, int d, int r) : name(n), bullets(b), damage(d), range(r) {}

string Gun::getName() {
    return name;
}

int Gun:: getBullets()  {
    return bullets;
}

int Gun:: getDamage()  {
    return damage;
}

int Gun::getRange()  {
    return range;
}
void Gun ::setBullets(const int b) {
    bullets = b;
}
ostream& operator<<(std::ostream &out, const Gun &c){
    out<<"Name:"<< c.name<<endl
       <<"Bullets:"<<c.bullets<<endl
       <<"Damage:"<<c.damage<<endl
       <<"Range:"<<c.range;
    return out;
}
void Gun:: useSpecial(Hero& h1 , Object** map) {
    //PISTOL
    if (h1.getWeapon()->getName() == "Pistol") {
        int HX=h1.getPositionX();
        int Hy=h1.getPositionY();
        if( h1.getWeapon()->getBullets()<1){
            cout<<"Not enough enough bullets"<<endl;
            return;
        }

        for(int i=0;i<h1.getWeapon()->getRange();i++){
            if(map[HX+i][Hy].getType()=='T'||map[HX+i][Hy].getType()=='G'){
                Monster M= dynamic_cast<Monster&>( map[HX+i][Hy]);
                M.setHealthPoints(M.getHealthPoints()-h1.getWeapon()->getDamage());
                break;
            }
        }
        h1.getWeapon()->setBullets(getBullets()-1);
        if( h1.getWeapon()->getBullets()<1){
            cout<<"Not enough enough bullets"<<endl;
            return;
        }
        for(int i=0;i<h1.getWeapon()->getRange();i++){
            if(map[HX-i][Hy].getType()=='T'||map[HX+i][Hy].getType()=='G'){
                Monster M= dynamic_cast<Monster&>( map[HX+i][Hy]);
                M.setHealthPoints(M.getHealthPoints()-h1.getWeapon()->getDamage());
                break;
            }
        }
        h1.getWeapon()->setBullets(getBullets()-1);
        if( h1.getWeapon()->getBullets()<1){
            cout<<"Not enough enough bullets"<<endl;
            return;
        }
        for(int i=0;i<h1.getWeapon()->getRange();i++){
            if(map[HX][Hy+i].getType()=='T'||map[HX][Hy+i].getType()=='G'){
                Monster M= dynamic_cast<Monster&>( map[HX][Hy+i]);
                M.setHealthPoints(M.getHealthPoints()-h1.getWeapon()->getDamage());
                break;
            }
        }
        h1.getWeapon()->setBullets(getBullets()-1);
        if( h1.getWeapon()->getBullets()<1){
            cout<<"Not enough enough bullets"<<endl;
            return;
        }
        for(int i=0;i<h1.getWeapon()->getRange();i++){
            if(map[HX][Hy-i].getType()=='T'||map[HX][Hy-i].getType()=='G'){
                Monster M= dynamic_cast<Monster&>( map[HX][Hy-i]);
                M.setHealthPoints(M.getHealthPoints()-h1.getWeapon()->getDamage());
                break;
            }
        }
    }

        //BAZOOKA
    else if (h1.getWeapon()->getName() == "Bazooka") {
        int HX=h1.getPositionX();
        int Hy=h1.getPositionY();
        while(HX>-1&&HX<15&&Hy>-1&&Hy<15){
            if(map[HX+1][Hy+1].getType()=='T'||map[HX+1][Hy+1].getType()=='G'){
                Monster M= dynamic_cast<Monster&>( map[HX+1][Hy+1]);
                M.setHealthPoints(0);
            }
            HX++;
            Hy++;
        }
        HX=h1.getPositionX();
        Hy=h1.getPositionY();
        while(HX>-1&&HX<15&&Hy>-1&&Hy<15){
            if(map[HX-1][Hy-1].getType()=='T'||map[HX-1][Hy-1].getType()=='G'){
                Monster M= dynamic_cast<Monster&>( map[HX-1][Hy-1]);
                M.setHealthPoints(0);
            }
            HX--;
            Hy--;
        }

    }
        // RIFLE
    else {
        int HX=h1.getPositionX();
        int Hy=h1.getPositionY();
        if( h1.getWeapon()->getBullets()<1){
            cout<<"Not enough enough bullets"<<endl;
            return;
        }

        for(int i=0;i<h1.getWeapon()->getRange();i++){
            if(map[HX+i][Hy].getType()=='T'||map[HX+i][Hy].getType()=='G'){
                Monster M= dynamic_cast<Monster&>( map[HX+i][Hy]);
                M.setHealthPoints(M.getHealthPoints()-h1.getWeapon()->getDamage());
            }
        }
        h1.getWeapon()->setBullets(getBullets()-1);
        if( h1.getWeapon()->getBullets()<1){
            cout<<"Not enough enough bullets"<<endl;
            return;
        }
        for(int i=0;i<h1.getWeapon()->getRange();i++){
            if(map[HX-i][Hy].getType()=='T'||map[HX+i][Hy].getType()=='G'){
                Monster M= dynamic_cast<Monster&>( map[HX+i][Hy]);
                M.setHealthPoints(M.getHealthPoints()-h1.getWeapon()->getDamage());
            }
        }
        h1.getWeapon()->setBullets(getBullets()-1);
        if( h1.getWeapon()->getBullets()<1){
            cout<<"Not enough enough bullets"<<endl;
            return;
        }
        for(int i=0;i<h1.getWeapon()->getRange();i++){
            if(map[HX][Hy+i].getType()=='T'||map[HX][Hy+i].getType()=='G'){
                Monster M= dynamic_cast<Monster&>( map[HX][Hy+i]);
                M.setHealthPoints(M.getHealthPoints()-h1.getWeapon()->getDamage());
            }
        }



    }
}
//GUN SUBCLASSES METHODS
Pistol::Pistol() : Gun("Pistol", 16, 30, 2){}
Bazooka::Bazooka() : Gun("Bazooka", 4, 150, 8) {}
Rifle::Rifle() : Gun("Rifle", 30, 20, 4) {}

//CHARACTER METHODS
Character::Character(char t, int x, int y, int hp) : Object(t), positionX(x), positionY(y), healthPoints(hp) {}
int Character::getPositionX()  {
    return positionX;
}
int Character::getPositionY() {
    return positionY;
}

int Character::getHealthPoints() {
    return healthPoints;
}

void Character::setPosition(int x, int y) {
    positionX = x;
    positionY = y;
}

void Character::setHealthPoints(int hp) {
    healthPoints = hp;
}
Hero::Hero(char t, int x, int y, int hp) : Character(t, x, y, hp) {
}
Gun* Hero::getWeapon()  {
    return weapon;
}
void Hero::setWeapon(Gun* g){
    weapon = g;
}
Hero::~Hero(){
    delete weapon;
}
void Hero::operator+(Ammo a) {
    if(this->getType() =='D'){
        DemolitionHero* d = dynamic_cast<DemolitionHero*>(this);
        d -> getWeapon()->setBullets(d -> getWeapon()->getBullets()+a.getBullets());
        d -> getWeapon2()->setBullets(d -> getWeapon2()->getBullets()+a.getBullets());
    }else{
        MedicHero* m = dynamic_cast<MedicHero*>(this);
        m -> getWeapon()->setBullets(m -> getWeapon()->getBullets()+a.getBullets());
    }
}

void Hero::operator+(Potion p) {
    this->setHealthPoints(getHealthPoints()+p.getHealingAmount());
}
void Hero::operator-(Monster m) {
    this->setHealthPoints(getHealthPoints()-10);
    m.setHealthPoints(m.getHealthPoints()-20);
}
ostream& operator<< (ostream& out, Hero& hero) {
    out << "Hero type : " << hero.getType() << endl;
    out << "Position : ( " << hero.getPositionX() << "," << hero.getPositionY() << ')' << endl;
    out << "HP : " << hero.getHealthPoints() << endl;
    Gun *gun = hero.getWeapon();
    out << "Gun info : " << endl;
    out << *gun << endl;
    out << "Bullets : " << gun->getBullets() << endl;
    return out;
}


//DEMOLITION HERO METHODS
DemolitionHero::DemolitionHero(char t, int x, int y, int hp) : Hero(t, x, y, hp) {}
Gun* DemolitionHero::getWeapon2() {
    return weapon2;
}
void DemolitionHero::useSpecial() {
    Gun* tmp = getWeapon();
    weapon = weapon2;
    weapon2 = tmp;
}
void DemolitionHero::setWeapon2(Gun *g) {
    weapon2 =g;
}
//MEDIC HERO METHODS
MedicHero:: MedicHero(char t, int x, int y, int hp,int ha) : Hero(t, x, y, hp), healingAmount(ha) {
    isSpecial=false;
}
int MedicHero:: getHealingAmount()  {
    return healingAmount;
}

void MedicHero::useSpecial() {
    if(!isSpecial){
        setHealthPoints(getHealthPoints()+getHealingAmount());
        isSpecial = true;
    }else{
        cout<< "already used special power once in this game."<< endl;
        return;
    }
}


// MONSTER METHODS
Monster::Monster(char t, int x, int y, int hp) : Character(t, x, y, hp) {}

//TANK MONSTER METHODS
TankMonster::TankMonster(char t, int x, int y, int hp, int s) : Monster(t, x, y, hp), shield(s) {}
int TankMonster::getShield() const {
    return shield;
}

//GHOST MONSTER METHODS
GhostMonster:: GhostMonster(char t, int x, int y, int hp) : Monster(t, x, y, hp), isVisible(true) {}
bool GhostMonster::isVisibleOnMap() const {
    return isVisible;
}
void GhostMonster::setVisible(const bool &&v) {
    isVisible = v;
}
//GAME METHODS
int generateRand(int begin, int end){
    random_device generate;
    mt19937 generator(generate());
    uniform_int_distribution<int>dist(begin,end);
    int res = dist(generator);
    return res;
}

Game:: Game() {
    hero = NULL;
    // Initialize grid with empty objects
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = new Object('.');
        }
    }
    isOver = false;
    round =0;
}


Game::~Game() {
    // Deallocate memory for grid objects
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            delete grid[i][j];
        }
    }
    // Deallocate memory for hero object
    delete hero;
}

void Game::generateMap(Hero& h) {

    // HERO
    hero = &h;
    grid[14][0] = hero;

    // HEALTH POTIONS
    for (int i = 0; i < 5; i++) {
        int x, y;
        do {
            x = generateRand(0,14);
            y = generateRand(0,14);
        } while (x < 0 || y < 0 || x>rows-1 || y>cols-1 || grid[x][y]->getType() != '.');
        int healPow = rand() % 40 + 10;
        Object* P = new Potion(healPow);
        delete grid [x][y];
        grid[x][y] = P;
    }
    cout << "Health Potions" << endl;

    // AMMO
    for (int i = 0; i < 10; i++) {
        int x, y;
        do {
            x = generateRand(0,14);
            y = generateRand(0,14);
        } while (x < 0 || y < 0 || x>rows-1 || y>cols-1 || grid[x][y]->getType() != '.');
        int ammo = rand() % 15 + 5;
        Object* A = new Ammo(ammo);
        delete grid[x][y];
        grid[x][y] = A;
    }
    cout << "Ammo"<<endl;
    // TANK MONSTERS
    for (int i = 0; i < 5; i++) {
        int x, y;
        do {
            x = generateRand(0,14);
            y = generateRand(0,14);
        } while (x == 0 && y == 0 && grid[x][y]-> getType() != '.');
        int hp = rand() % 10 * 10 + 60;
        Object* TM = new TankMonster('T', x, y, hp, hp);
        delete grid[x][y];
        grid[x][y] = TM;
    }

    cout << "Tank Monsters"<< endl;

    // GHOST MONSTERS
    for (int i = 0; i < 5; i++) {
        int x, y;
        do {
            x = generateRand(0,14);
            y = generateRand(0,14);
        } while (x == 0 && y == 0 && grid[x][y]->getType() != '.');
        int hp = rand() % 10 * 10 + 60;
        Object* GM = new GhostMonster('G',x,y,hp);
        delete grid[x][y];
        grid[x][y] = GM;
    }
    cout << "Ghost Monsters"<<endl;
}

void Game::showMap()  {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j]->getType() << " ";
        }
        cout << endl;
    }
}

void Game::startGame() {
    //GET HERO AND GUN
    char h,gun;
    cout << "To select a hero, type 'd' for demolition hero or 'm' for medic"<< endl;
    cin >> h;
    if(h == 'D' || h == 'd'){
        char gunsecond;
        cout << "Choose your First Gun. For Rifle, type 'R'. For Bazooka, type 'B'. For Pistol type 'P'."<< endl;
        cin >> gun;
        cout << "Choose your Second Gun. For Rifle, type 'R'. For Bazooka, type 'B'. For Pistol type 'P'. If you don't want a second gun type 'X'."<< endl;
        cin>> gunsecond;
        DemolitionHero* start = new DemolitionHero('D',0,0,150);
        switch(gun){
            case 'R': case 'r': start ->setWeapon(new Rifle());break;
            case 'B' : case 'b': start ->setWeapon(new Bazooka());break;
            case 'P' : case 'p': start ->setWeapon(new Pistol());break;
            default: cout<<"That was not a Valid Entry, please try again";
        }
        switch(gunsecond){
            case 'R': case 'r': start ->setWeapon2(new Rifle());break;
            case 'B' : case 'b': start ->setWeapon2(new Bazooka());break;
            case 'P' : case 'p': start ->setWeapon2(new Pistol());break;
            case 'X' : case 'x': start -> setWeapon(nullptr);
            default: cout<<"That was not a Valid Entry, please try again";
        }
        hero = dynamic_cast<Hero*>(start);
    }
    else{
        cout << "Choose your Gun. For Rifle, type r. For Bazooka, type b. For Pistol type p"<< endl;
        cin >> gun;
        hero = new MedicHero('M',0,0,150,50);
        switch(gun){
            case 'R': case 'r': hero ->setWeapon(new Rifle());break;
            case 'B' : case 'b': hero ->setWeapon(new Bazooka());break;
            case 'P' : case 'p': hero ->setWeapon(new Pistol());break;
            default: cout<<"That was not a Valid Entry, please try again";
        }
    }
    // GENERATE MAP
    generateMap(*hero);

    //DISPLAY MAP
    showMap();
}
void Game:: move(Hero& h,char direction){
    cout<< "move called";
    int currX = h.getPositionX();
    int currY = h.getPositionY();
    switch(direction){
        case 'd':
            if(currY+1>14)
            {cout << "Cannot Move Outise Borders, please choose another direction"<< endl;
                cin >> direction;
                move(h,direction);}
            if((grid[currX][currY+1])->getType() == 'G' ||(grid[currX][currY+1])->getType() == 'T' )
            {cout<<"Cannot move there"<<endl;
                h - *dynamic_cast<Monster*>(grid[currX][currY+1]);}
            else
            {delete grid[currX][currY];
                grid[currX][currY] = new Object('.');
                h.setPosition(currX, currY+1);
                delete grid[currX][currY+1];
                grid[currX][currY+1] = &h;
                cout<<"move happened";} break;
        case 'a':
            if(currY-1<0)
            {cout << "Cannot Move Outise Borders, please choose another direction"<< endl;
                cin >> direction;
                move(h,direction);}
            if((grid[currX][currY-1])->getType() == 'G' ||(grid[currX][currY-1])->getType() == 'T' )
            {cout<<"Cannot move there"<<endl;
                h - *dynamic_cast<Monster*>(grid[h.getPositionX()][h.getPositionY()-1]);}
            else
            {delete grid[currX][currY];
                grid[currX][currY] = new Object('.');
                h.setPosition(currX, currY-1);
                delete grid[currX][currY-1];
                grid[currX][currY-1] = &h;
                cout<<"move happened";} break;
        case 's' :
            if(currX-1<0)
            {cout << "Cannot Move Outise Borders, please choose another direction"<< endl;
                cin >> direction;
                move(h,direction);}
            if((grid[currX-1][currY])->getType() == 'G' ||(grid[currX-1][currY])->getType() == 'T' )
            {cout<<"Cannot move there"<<endl;
                h - *dynamic_cast<Monster*>(grid[h.getPositionX()-1][h.getPositionY()]);}
            else
            {delete grid[currX][currY];
                grid[currX][currY] = new Object('.');
                h.setPosition(currX-1, currY);
                delete grid[currX-1][currY];
                grid[currX-1][currY] = &h;
                cout<<"move happened";
            } break;

        case 'w' :
            if(currY+1>14)
            {cout << "Cannot Move Outise Borders, please choose another direction"<< endl;
                cin >> direction;
                move(h,direction);}
            if((grid[currX+1][currY])->getType() == 'G' ||(grid[currX+1][currY])->getType() == 'T' )
            {cout<<"Cannot move there"<<endl;
                h - *dynamic_cast<Monster*>(grid[h.getPositionX()+1][h.getPositionY()]);}
            else
            {delete grid[currX][currY];
                grid[currX][currY] = new Object('.');
                h.setPosition(currX+1, currY);
                delete grid[currX+1][currY];
                grid[currX+1][currY] = &h;
                cout<<"move happened";
            } break;


            if(grid[h.getPositionX()][h.getPositionY()] -> getType() =='A'){
                h + *dynamic_cast<Ammo*>(grid[h.getPositionX()][h.getPositionY()]);
            }
            if(grid[h.getPositionX()][h.getPositionY()] -> getType() =='P'){
                h + *dynamic_cast<Potion *>(grid[h.getPositionX()][h.getPositionY()]);
                delete grid[h.getPositionX()][h.getPositionY()];
                grid[h.getPositionX()][h.getPositionY()] = &h;
            }

            for(int i =0; i<15; i++){
                for(int j =0; j<15; j++){
                    cout << grid[i][j]->getType()<< " ";
                }
                cout<< endl;
            }


    }}
void Game:: fireGun(char direction){
    Gun g = *(hero->getWeapon());
    int HX=hero->getPositionX();
    int Hy=hero->getPositionY();
    if(g.getBullets() <1){
        cout << "Cannot Fire, you don't have enough Bullets";
        return;
    }

    if(direction=='D') {
        for (int i = 0; i < hero->getWeapon()->getRange(); i++) {
            if (grid[HX + i][Hy]->getType() == 'T' || grid[HX + i][Hy]->getType() == 'G') {
                Monster M = dynamic_cast<Monster &>(*(grid[HX+i][Hy]));
                M.setHealthPoints(M.getHealthPoints() - hero->getWeapon()->getDamage());
                break;
            }
        }
    }

    if(direction=='W') {
        for (int i = 0; i < hero->getWeapon()->getRange(); i++) {
            if (grid[HX][Hy+i]->getType() == 'T' || grid[HX][Hy + i]->getType() == 'G') {
                Monster M = dynamic_cast<Monster &>(*(grid[HX][Hy + i]));
                M.setHealthPoints(M.getHealthPoints() - hero->getWeapon()->getDamage());
                break;
            }
        }
    }

    if(direction=='S') {
        for (int i = 0; i < hero->getWeapon()->getRange(); i++) {
            if (grid[HX][Hy-i]->getType() == 'T' || grid[HX][Hy-i]->getType() == 'G') {
                Monster M = dynamic_cast<Monster &>(*(grid[HX][Hy -i]));
                M.setHealthPoints(M.getHealthPoints() - hero->getWeapon()->getDamage());
                break;
            }
        }
    }

    if(direction=='A') {
        for (int i = 0; i < hero->getWeapon()->getRange(); i++) {
            if (grid[HX - i][Hy]->getType() == 'T' || grid[HX - i][Hy]->getType() == 'G') {
                Monster M = dynamic_cast<Monster &>(*(grid[HX-i][Hy]));
                M.setHealthPoints(M.getHealthPoints() - hero->getWeapon()->getDamage());
                break;
            }
        }
    }

    g.setBullets(g.getBullets() -1);
}

int Game::checkGameOver() {
    if(hero->getHealthPoints() == 0)
        return 0;
    int count =0;
    for(int i = 0; i< rows; i++){
        for(int j =0; j<cols; j++){
            if(grid[i][j]->getType() =='T'||grid[i][j]->getType() =='G')
                count++;
        }
    }
    if(count ==0)
        return 1;
    return -1;
}

void Game::updateMap() {
    srand(time(0));
    //delete dead monsters
    for(int i = 0; i<rows; i++){

        for(int j = 0; j< cols; j++){

            if(grid[i][j]->getType() =='T'||grid[i][j]->getType()=='G'){
                if(dynamic_cast<Monster*>(grid[i][j])->getHealthPoints()<=0){
                    delete grid[i][j];
                    grid[i][j]  = new Object('.');
                }
            }}}

            if(round%20 ==0)
            { int x, y;

                do {
                    x = generateRand(0,14);
                    y = generateRand(0,14);
                    cout<< x << " " << y;


                } while (x < 0 || y < 0 || x>rows-1 || y>cols-1 || grid[x][y]->getType() != '.');
                int hp = (rand() % 10 + 1) * 60;
                Object * temp = grid[x][y];
                TankMonster* t = new TankMonster('T',x,y,hp,hp);
                grid[x][y]= t;
                delete temp;

                    int x2,y2;
                do{
                    x2 = generateRand(0,14);
                    y2 = generateRand(0,14);
                    cout<< "the" << " " << "apple";

                }
                while( x2 < 0 || y2 < 0 || x2>rows-1 || y2>cols-1 || grid[x2][y2]->getType() != '.');
                hp = (rand() % 10 + 1) * 60;
                Object * temp2 = grid[x2][y2];
                GhostMonster* t2 = new GhostMonster('G',x2,y2,hp);
                grid[x2][y2]= t2;
                delete temp2;
            }


            for(int i =0; i<rows; i++){
                for(int j=0; j< cols; j++){

                    if(round%3 ==0){
                        if(grid[i][j]->getType() =='G'){
                            if(dynamic_cast<GhostMonster *>(grid[i][j])->isVisibleOnMap())
                            {
                                dynamic_cast<GhostMonster*>(grid[i][j])->setVisible(false);
                            }else{
                                dynamic_cast<GhostMonster*>(grid[i][j])->setVisible(true);
                            }
                        }
                }
            }

            }



    system("CLS");
    showMap();}


void Game::useGunSpecial() {
    Gun* g = hero->getWeapon();
    if(std::equal(g->getName().begin(), g->getName().end(),"Pistol")){
        if(g->getBullets()<4)
            cout << "Special Ability cannot be unlocked for this gun right now, you need at least 4 bullets"<<endl;
        return;
    }
    if(std::equal(g->getName().begin(), g->getName().end(),"Rifle")){
        if(g->getBullets()<3)
            cout << "Special Ability cannot be unlocked for this gun right now, you need at least 3 bullets"<<endl;
        return;
    }
    if(std::equal(g->getName().begin(), g->getName().end(),"Bazooka")){
        if(hero->getPositionX() != hero->getPositionY()){
            cout << "Must be standing in a diagonal position to use this Special Ability" <<endl;
            return;
        }
    }

    hero->getWeapon()->useSpecial(*hero,*grid);
}
void Game::play(Game g) {
    while(g.checkGameOver() ==-1) {
        cout << " to use hero special press w" << endl
             << " to Move press s" << endl
             << "to fire gun press A" << endl
             << "to use gun special press D" << endl;
        char move;
        cin >> move;


        switch (move) {
            case 'w':
                g.hero->useSpecial();
                g.updateMap();
                break;
            case 's':
                cout<<"enter a direction"<<endl;
                char D;
                cin>>D;
                g.move(*hero, D);
                g.updateMap();
                break;
            case 'a':
                cout<<"enter a bullet direction"<<endl;
                char F;
                cin>>F;
                g.fireGun(F);
                g.updateMap();
                break;
            case 'd':
                g.hero->getWeapon()->useSpecial(reinterpret_cast<Hero &>(g.hero), reinterpret_cast<Object **>(g.grid));
                g.updateMap();
                break;
        }
        cout<<"still running"<<endl;

    }
}



int main(){
    Game g;
    g.startGame();
    g.play(g);
    return 0;
}