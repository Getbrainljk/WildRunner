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
        prev = new char[YSCREEN];
    }

    ~Map() {
        delete vertical;
        delete prev;
    }

    char *getMap(){
        //Ton Code qui genere une bande coerente avec prev

        prev = vertical;
        return vertical;
    }
};


#endif //GAME_MAP_HPP
