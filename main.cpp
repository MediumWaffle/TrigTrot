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

   

    Objects floor;
    Objects player;
    Objects cPlayer;
    Objects BackGround;
    Objects start;
    Objects OBS;

    start.background.setSize(Vector2f(230,100));
    start.background.setPosition(5,5);
    BackGround.makeBackground(240);
    player.makePlayer("sprites/default.png");
    cPlayer.makePlayer("default_crouch.png");
    floor.makeFloor(120);
    OBS.makeObs(-240,-130);
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
                player.jump(-70,10,10, 1, nojump);
                //Window.draw(BackGround.background);
                game.draw(BackGround.background);
                //Window.draw(BackGround.background2);
                game.draw(BackGround.background2);
                //Window.draw(player.Player);
                game.draw(player.Player);
                
                //Window.draw(obs);
                game.draw(OBS.obs);
                //Window.draw(floor.one);
                game.draw(floor.one);
                //Window.draw(floor.two);
                game.draw(floor.two);
                //Window.draw(floor.three); 
                game.draw(floor.three);
                floor.moveFloor(120);
                BackGround.moveBackground(); 
                OBS.moveObs(10);
    
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

            floor.moveFloor(120);
            BackGround.moveBackground();
            player.jump(-70,10,10, 1, nojump);
            game.draw(BackGround.background);
            game.draw(BackGround.background2);
        

       if(Keyboard::isKeyPressed(Keyboard::Key::Down))
       {   
            
            game.draw(cPlayer.Player);

       }
       if(!Keyboard::isKeyPressed(Keyboard::Key::Down))
       {
           
            game.draw(player.Player);
            
       }
       
    
        game.draw(OBS.obs);


        
        
        
       OBS.moveObs(10);

        
        
       

        
       
        game.draw(floor.one);
       
        game.draw(floor.two);
       
        game.draw(floor.three);
       
        game.display();
        
        
       

        if((player.playerX == OBS.obsx) and (player.playerY < -100))
        {

            while(!Keyboard::isKeyPressed(Keyboard::Key::S))
            {
                game.events();

                RectangleShape Gameover;
                Texture over;

                over.loadFromFile("gameOver.jpg");
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





