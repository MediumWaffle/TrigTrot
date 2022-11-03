/**
 * @file main.cpp
 * @ingroup MalAarCal
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Primary file for game loop
 * @date 10-24-2022
 */
#include "header.h"

int main()
{
    //initilize variables
    RenderWindow window(VideoMode(512,512), "Trig Trot", Style::Default);
    View view(Vector2f(0.0f, 0.0f), Vector2f(512.0f, 512.0f));
    CircleShape player(50.0f);
    Event e;

    //adjust initial variables
    player.setOrigin(player.getRadius(), player.getRadius());
    player.setPosition(window.getSize().x/2, window.getSize().y/2);
    player.setFillColor(Color::Green);

    //game loop
    while (window.isOpen()){
        //checks events
        events(window, e);
        //adjust player's movement
        playerMovement(player);
        //set view focus point to player
        view.setCenter(player.getPosition());
        //render updates to window
        update(window, view, player);
    }

    return 0;
}