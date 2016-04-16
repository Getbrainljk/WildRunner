//
// Created by Augustin Saint Olive on 16/04/2016.
//

#ifndef GAME_MAP_HPP
#define GAME_MAP_HPP


#include "Character.hpp"

class Map {
public:
    char *vertical;
    char *prev;

    Map() {
        vertical = new char[YSCREEN];
        for (unsigned int cpt = 0; cpt < YSCREEN; cpt++) {
            vertical[cpt] = 0;
        }
    }

    ~Map() { delete vertical; }
};


#endif //GAME_MAP_HPP
