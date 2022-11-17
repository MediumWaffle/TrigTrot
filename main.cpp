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
    
    bool nojump = true;
    int x = -240;
    int x2 = -340;
    RectangleShape obs;
    RectangleShape plat;
    Texture obst;
    Objects floor;
    Objects player;
    Objects BackGround;
    Objects start;

    obst.loadFromFile("sprites/caveSpike.png");
    obs.setSize(Vector2f(20,20));
    obs.setTexture(&obst);
    obs.setOrigin(x,-130);
    plat.setSize(Vector2f(20,20));
    plat.setOrigin(x2, -130);
    plat.setTexture(&obst);
    
    start.background.setSize(Vector2f(230,100));
    start.background.setPosition(5,5);
    BackGround.makeBackground(240);
    player.makePlayer();
    floor.makeFloor(120);
    bool startW = false;


    while(game.isRunning())
    {
        game.events();

        if(startW == false)
        {
            while(startW == false)
            {
                game.events();

                RectangleShape Gamestart;
                Texture startg;
                startg.loadFromFile("sprites/welcome.png");
                Gamestart.setFillColor(Color::Blue);
                Gamestart.setTexture(&startg);
                start.background.setTexture(&startg);
                Gamestart.setSize(Vector2f(240,200));
                Gamestart.setOrigin(0,0);
                //Window.clear();
                game.clear();
                //Window.draw(Gamestart);
                game.draw(Gamestart);
                player.jump(-70,10,10, x2, nojump);
                //Window.draw(BackGround.background);
                game.draw(BackGround.background);
                //Window.draw(BackGround.background2);
                game.draw(BackGround.background2);
                //Window.draw(player.Player);
                game.draw(player.Player);
                obs.setOrigin(x, -130);
                //Window.draw(obs);
                game.draw(obs);
                //Window.draw(floor.one);
                game.draw(floor.one);
                //Window.draw(floor.two);
                game.draw(floor.two);
                //Window.draw(floor.three); 
                game.draw(floor.three);
                floor.moveFloor(120);
                BackGround.moveBackground(); 
                x += 10;
                x2 += 5;
                //Window.draw(start.background);
                game.draw(start.background);
                //Window.display();
                game.display();
                usleep(55000);
                
                if(Keyboard::isKeyPressed(Keyboard::Key::Enter))
                {
                    startW = true;
                }
            }
        }

        //Window.clear();
        game.clear();
        srand(time(nullptr));
        int mrand = rand()%10;
        
        if(x > 0 and mrand%2==0){x=-240;}
        if(x > 0 and mrand%2!=0){x = -400;}
        if(x2 > 0){x2 = -340;}
        floor.moveFloor(120);
        BackGround.moveBackground();

        if(Keyboard::isKeyPressed(Keyboard::Key::Down))
        {
            player.ptext2.loadFromFile("sprites/psycho.png");
            player.Player.setTexture(&player.ptext2);
        }
        if(!Keyboard::isKeyPressed(Keyboard::Key::Down))
        {
            player.Player.setTexture(&player.ptext);
        }

        player.jump(-70,10,10, x2, nojump);
        obs.setOrigin(x, -130);
        plat.setOrigin(x2,-130);
        //Window.draw(BackGround.background);
        game.draw(BackGround.background);
        //Window.draw(BackGround.background2);
        game.draw(BackGround.background2);
        //Window.draw(player.Player);
        game.draw(player.Player);
        //Window.draw(obs);
        game.draw(obs);
        //Window.draw(floor.one);
        game.draw(floor.one);
        //Window.draw(floor.two);
        game.draw(floor.two);
        //Window.draw(floor.three); 
        game.draw(floor.three);
        //Window.draw(plat);
        game.draw(plat);

        //Window.display();
        game.display();
        
        x += 10;
        x2 += 5;

        if((player.playerX == x or player.playerX == x2) and (player.playerY < -100))
        {
            while(!Keyboard::isKeyPressed(Keyboard::Key::S))
            {
                game.events();

                RectangleShape Gameover;
                Texture over;

                over.loadFromFile("sprites/gameover.png");
                Gameover.setTexture(&over);
                Gameover.setFillColor(Color::Red);
                Gameover.setSize(Vector2f(240,200));
                Gameover.setOrigin(0,0);

                //Window.clear();
                game.clear();
                //Window.draw(Gameover);
                game.draw(Gameover);
                //Window.display();
                game.display();
            }
            startW = false;
        }
        usleep(55000);
    }
    return 0;
}
