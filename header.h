/**
 * @file header.h
 * @GroupName MalAarCal 
 * @GroupMembers Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Header for game. Stores all important global information
 * @date 10-24-2022
 */

//DO NOT FORGET TO CHECK README.md FREQUENTLY!!! Important updates and notes should be made here!

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
#include <iomanip>
#include <fstream>
#include <SFML/Graphics.hpp>

//We should try not to use namespace std. It may earn us extra points if we use good coding habbits for final submission.
using namespace sf;

//Global Variables

//Classes

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



#endif