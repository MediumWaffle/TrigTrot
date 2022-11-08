/**
 * @file functions.cpp
 * @ingroup MalAarCal
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Function list for game
 * @date 10-24-2022
 */
#include "header.h"

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