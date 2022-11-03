/**
 * @file functions.cpp
 * @ingroup MalAarCal
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Function list for game
 * @date 10-24-2022
 */
#include "header.h"

/**
 * @brief updates events happening to the window
 * @param window checks the events happening to window
 * @param e our event
 * @author Aaron Jarnes
 */
void events(RenderWindow &window, Event &e){
    while(window.pollEvent(e)){
        if (e.type == e.Closed){
            window.close();
        }
    }
}

/**
 * @brief updates the window with the objects
 * @param window checks the events happening to window
 * @param view the view inside our window
 * @param player the movable character
 * @author Aaron Jarnes
 */
void update(RenderWindow &window, View &view, CircleShape &player){
    window.clear();
    window.setView(view);
    window.draw(player);
    window.display();
}

/**
 * @brief takes keybaord input and chnages the player position accordingly
 * @param player the object the user can control
 * @author Aaron Jarnes
 */
void playerMovement(CircleShape &player){
    //jump
    if(Keyboard::isKeyPressed(Keyboard::Key::Space)){
        //check if character is at reg position (that way they cant go out of play area)
        //set y value to +10 then set back to -10 after 1 second
    }
    //crouch
    if(Keyboard::isKeyPressed(Keyboard::Key::LShift)){
        //check the character sprite
            //if it's in the crouch sprite, dont crouch again
            //else change sprite to crouch while user holds down button
    }
}