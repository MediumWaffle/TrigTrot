/**
 * @file header.h
 * @ingroup MalAarCal 
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Header for game. Stores all important global information
 * @date 10-24-2022
 */
#ifndef HEADER_H
#define HEADER_H

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <ctime>
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class Objects
{
    public:
   void makeFloor(int s);
   void moveFloor(int s);
   
   int floor1, floor2, floor3;

   RectangleShape one, two, three;
   CircleShape player;

    void makePlayer();
   void jump(int height, int falls, int rises); 


    int playerY = -130; 
    int playerX = -40;


};

/* Ideas for classes(delete me)
    class display{}
    class gameData{}
    class playerInfo{}
    class enemyInfo{} / cpuInfo{}
*/



void events(RenderWindow &window, Event &e);
void update(RenderWindow &window, View &view, CircleShape &player);
void playerMovement(CircleShape &player);
#endif