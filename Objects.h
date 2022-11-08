#ifndef OBJECT_H
#define OBJECT_H

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <ctime>
#include <SFML/Graphics.hpp>

using namespace sf;

class Objects
{
    public:
        void makeFloor(int s);
        void moveFloor(int s);
        
        int floor1, floor2, floor3;

        RectangleShape one, two, three;
};

#endif