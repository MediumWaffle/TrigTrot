/**
 * @file main.cpp
 * @ingroup MalAarCal
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Primary file for game loop
 * @date 10-24-2022
 */
#include "header.h"
#include "Game.h"

int main()
{
    //initilize variables
    Game game(522, 522, "Trig Trot");
    CircleShape player(50.0f);
    Vector2f rectSize(174, 174);
    RectangleShape platform1(rectSize);
    RectangleShape platform2(rectSize);
    RectangleShape platform3(rectSize);

    //adjust initial variables
    player.setOrigin(player.getRadius(), player.getRadius());
    player.setPosition(game.getWindowSize("x"), game.getWindowSize("y"));
    player.setFillColor(Color::Green);

    //game loop
    while (game.isRunning()){
        //checks events
        game.events();
        //adjust player's movement
        playerMovement(player);
        //render updates to window
        game.update(player, platform1, platform2, platform3);
    }

    return 0;
}