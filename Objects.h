/**
 * @file header.h
 * @ingroup MalAarCal 
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Header for game. Stores all important global information
 * @date 10-24-2022
 */
#ifndef OBJECTS_H
#define OBJECTS_H

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <ctime>
#include <string>
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace sf;

class Objects
{
    public:
    void makeFloor(int s);
    void moveFloor(int s);
    void makeBackground(int s);
    void moveBackground();
    void makePlayer(std::string t);
    void jump(int height, int falls, int rises, int plat, bool &nojump);
    void makeObs(int x, int y);
    void moveObs(int speed);
    void makeTopObs(int x, int y);
   
    int floor1, floor2, floor3;
    int backx, backx2;

   RectangleShape one, two, three;
   RectangleShape background, background2;
   RectangleShape obs, plat;
   CircleShape Player;
   Texture text1, text2, text3;
   Texture ptext;
   Texture ptext2;
   Texture back, obst;

     


    int playerY = -125; 
    int playerX = -40;
    int obsx, obsy;


};


#endif
