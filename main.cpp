/**
 * @file main.cpp
 * @ingroup MalAarCal
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Primary file for game loop
 * @date 10-24-2022
 */
#include "header.h"
//#include "Game.h"

int main()
{
    Game game(240, 200, "Trig Trot");

    string playerskin = "sprites/default.png";
    string cplayerskin = "sprites/default_crouch.png";

    bool nojump = true;
    bool crouch = false;
    bool skinmenu = false;

    Music intro;
    intro.openFromFile("music/intro.wav");
    Music ingame;
    ingame.openFromFile("music/play.wav");
    Music dead;
    dead.openFromFile("music/dead.wav");

    Objects floor;
    Objects player;
    Objects cPlayer;
    Objects BackGround;
    Objects start;
    Objects OBS;
    Objects TopObs;

    start.background.setSize(Vector2f(230, 100));
    start.background.setPosition(5, 5);
    BackGround.makeBackground(240);
    player.makePlayer(playerskin);
    cPlayer.makePlayer(cplayerskin);
    floor.makeFloor(120);
    OBS.makeObs(-240, -130);
    TopObs.makeTopObs(-340, 0);
    bool startW = false;
    bool deathscreen = false;

    while (game.isRunning())
    {
        game.events();
        
        if (startW == false)
        {
            dead.stop();
            intro.play();
            startScreen(startW, game, player, playerskin, cPlayer, cplayerskin, start, nojump, BackGround, OBS, TopObs, floor, skinmenu);
        }
        if (startW == true && deathscreen == false){
            intro.stop();
            ingame.play();
            gameScreen(startW, deathscreen, game, player, playerskin, cPlayer, cplayerskin, floor, BackGround, nojump, crouch, OBS, TopObs);
        }
        if (deathscreen)
        {
            ingame.stop();
            dead.setPlayingOffset(seconds(25.3f));
            dead.play();
            deathScreen(deathscreen, game, startW);
        }
    }
    return 0;
}
