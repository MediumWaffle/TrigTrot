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
    //make the window
    Game game(240, 200, "Trig Trot");

    //defaulting the player skins
    string playerskin = "sprites/default.png";
    string cplayerskin = "sprites/default_crouch.png";

    //initilizing booleans
    bool nojump = true;
    bool crouch = false;
    bool skinmenu = false;

    //music initilization
    Music intro;
    intro.openFromFile("music/intro.wav");
    Music ingame;
    ingame.openFromFile("music/play.wav");
    Music dead;
    dead.openFromFile("music/dead.wav");

    //making objects
    Objects floor;
    Objects player;
    Objects cPlayer;
    Objects BackGround;
    Objects start;
    Objects OBS;
    Objects TopObs;

    //initilizing objects
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

    //score counter
    double n = 0;
    Text t;
    Font font;
    font.loadFromFile("font.ttf");
    t.setFont(font);
    t.setPosition(Vector2f(160,0));


    //Game Loop
    while (game.isRunning())
    {
        //event handler
        game.events();
        
        // Into Screen
        if (startW == false)
        {
            intro.setPlayingOffset(seconds(15.0f));
            dead.stop();
            intro.play();
            startScreen(startW, game, player, playerskin, cPlayer, cplayerskin, start, nojump, BackGround, OBS, TopObs, floor, skinmenu);
        }
        // Game Loop Screen
        if (startW == true && deathscreen == false){
            intro.stop();
            ingame.play();
            n = 0.00;
            gameScreen(startW, deathscreen, game, player, playerskin, cPlayer, cplayerskin, floor, BackGround, nojump, crouch, OBS, TopObs,n,t);
        }
        // Death Screen
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
