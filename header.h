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



using namespace sf;
using std::string;

#endif