/**
 * @file header.h
 * @ingroup MalAarCal 
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Header for game. Stores all important global information
 * @date 10-24-2022
 */
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

void events(RenderWindow &window, Event &e);
void update(RenderWindow &window, View &view, CircleShape &player);
void playerMovement(CircleShape &player);
/* Ideas for classes(delete me)
    class playerInfo{}
    class enemyInfo{} / cpuInfo{}
*/
#endif