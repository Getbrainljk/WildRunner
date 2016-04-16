//
// Created by Augustin Saint Olive on 16/04/2016.
//

#include "Character.hpp"

Chara::Chara() {
    life = true;
    actual = HUMAN;
    jump = false;
    pos.X = XINIT;
    pos.Y = YINIT;

//init forms
    forme[Forme::HUMAN].speed = 3;
    forme[Forme::SPEED].speed = 2;
    forme[Forme::JUMPER].speed = 6;
    forme[Forme::GROUND].speed = 4;

    forme[Forme::HUMAN].xSize = 30;
    forme[Forme::SPEED].xSize = 60;
    forme[Forme::JUMPER].xSize = 30;
    forme[Forme::GROUND].xSize = 10;

    forme[Forme::HUMAN].ySize = 150;
    forme[Forme::SPEED].ySize = 15;
    forme[Forme::JUMPER].ySize = 60;
    forme[Forme::GROUND].ySize = 20;

    forme[Forme::HUMAN].jump = 15;
    forme[Forme::SPEED].jump = 10;
    forme[Forme::JUMPER].jump = 40;
    forme[Forme::GROUND].jump = 20;

    map = new Map[XSCREEN];

}




