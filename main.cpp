/**
 * @file main.cpp
 * @GroupName MalAarCal
 * @GroupMembers Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Primary file for game loop
 * @date 10-24-2022
 */

//DO NOT FORGET TO CHECK README.md FREQUENTLY!!! Important updates and notes should be made here!

#include "header.h"

//main function headers
void events(RenderWindow &window, Event &e);

int main()
{
    RenderWindow window(VideoMode(512,512), "Trig Trot", Style::Default);

    while (window.isOpen()){
        Event e;
        events(window, e);
    }

    return 0;
}

//main function headers
void events(RenderWindow &window, Event &e){
    while(window.pollEvent(e)){
        if (e.type == e.Closed){
            window.close();
        }
    }
}