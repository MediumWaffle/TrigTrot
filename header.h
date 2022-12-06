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

#include <ctime>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Objects.h"
#include "Game.h"
#include <SFML/Audio.hpp>
#include <sstream>

using namespace sf;
using std::string;

void startScreen(bool &startW, Game &game, Objects &player, string &playerskin, 
Objects &cPlayer, string &cplayerskin, Objects &start, bool &nojump, Objects &BackGround, Objects &OBS, 
Objects &TopObs, Objects &floor, bool &skinmenu);
void skinScreen(bool &skinmenu, Objects &player, Game &game, string &playerskin, string &cplayerskin);
void gameScreen(bool &startW, bool &deathscreen, Game &game, Objects &player, 
string &playerskin, Objects &cPlayer, string &cplayerskin, Objects &floor, Objects &BackGround, bool &nojump,
bool &crouch, Objects &OBS, Objects &TopObs, double &n, Text t);
void deathScreen(bool &deathscreen, Game &game, bool &startW, double &n, Text t);

#endif