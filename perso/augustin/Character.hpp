//
// Created by Augustin Saint Olive on 16/04/2016.
//

#ifndef GAME_CHARACTER_HPP
#define GAME_CHARACTER_HPP


#include "map.hpp"

#define XINIT 0
#define YINIT 0

#define XSCREEN 21
#define YSCREEN 18


typedef struct type_s {
    unsigned int xSize;
    unsigned int ySize;
    unsigned int speed;
    unsigned int jump;
} type;


class Chara {
    enum Forme : int {
        HUMAN,
        SPEED,
        JUMPER,
        GROUND
    };
    typedef struct pos_s {
        unsigned int X;
        unsigned int Y;
    } Pos;

    bool life;
    Forme actual;
    bool jump;
    Pos pos;
    type forme[4];
    Map *map;
public:
    Chara();

    virtual ~Chara() { delete map; };

    void toHuman() { actual = HUMAN; }

    void toSpeed() { actual = SPEED; }

    void toJumper() { actual = JUMPER; }

    void toGround() { actual = GROUND; }

    void goJump() {
        jump = true; // while space pressed
        pos.Y = forme[actual].jump;
    }

    void goDown() {
        jump = false;
        pos.Y = 0;// no obstacle
    }

    void die() { life = false; }

    void move() { pos.X = pos.X + (XSCREEN / forme[actual].speed); }
};


#endif //GAME_CHARACTER_HPP
