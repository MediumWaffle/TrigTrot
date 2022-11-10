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
       
    
    
    RenderWindow Window(VideoMode(240,200), "Game",Style::Default);
    
  
    /*
    RectangleShape one;
    RectangleShape two;
    RectangleShape three;
    */
    RectangleShape obs;
    RectangleShape plat;
   // CircleShape player;

    /*
    one.setSize(sf::Vector2f(120, 50));
    one.setFillColor(Color::Blue);
    two.setSize(sf::Vector2f(120,50));
    two.setFillColor(Color::Red);
    three.setSize(Vector2f(120,50));
    three.setFillColor(Color::Green);
    */
    int x = -240;
    int x2 = -340;
    /*
    int floor1 = 0;
    int floor2 = floor1-120;
    int floor3 = floor1-240;
    */
    Texture obst;
    Texture platt;
    platt.loadFromFile("floatingPlatform.png");
    obst.loadFromFile("Spike-1.png");
    //obs.setFillColor(Color(0,0,0));
    obs.setSize(Vector2f(20,20));
    obs.setTexture(&obst);
    obs.setOrigin(x,-130);
    plat.setSize(Vector2f(20,20));
    plat.setOrigin(x2, -100);
    plat.setTexture(&platt);
   // int playerY = -130; 
   // int playerX = -40;
    /*
    player.setRadius(25/2);
    player.setFillColor(Color(255,255,255));
    player.setOrigin(playerX,playerY);
    */

    
    /*
    one.setOrigin(floor1,-150);
    two.setOrigin(floor2,-150);
    three.setOrigin(floor3,-150);
    */
    Objects floor;
    Objects player;
    player.makePlayer();
    floor.makeFloor(120);
    bool start = false;

 
    while(Window.isOpen())
    {
        Event e;
        while(Window.pollEvent(e))
        {
            if(e.type == e.Closed)
            {
                Window.close();
            }
        }

        if(start == false)
        {
            while(start == false)
                {
                    while(Window.pollEvent(e))
                    {
                        if(e.type == e.Closed)
                        {
                            Window.close();
                        }
                    }
                    RectangleShape Gameover;
                    Gameover.setFillColor(Color::Blue);
                    Gameover.setSize(Vector2f(240,200));
                    Gameover.setOrigin(0,0);
                    Window.clear();
                    Window.draw(Gameover);
                    Window.display();
                    if(Keyboard::isKeyPressed(Keyboard::Key::Enter))
                    {
                        start = true;
                    }
                    

                }

        }
        Window.clear();

        
    
        if(x > 0)
        {
            x=-240;
            
        } 
        if(x2 > 0)
        {
            x2 = -340;
        }
        floor.moveFloor(120);

        /*
       if(floor1 > 120)
       {
            floor2 = 0;
            floor3 = -120;
            floor1 = -240;
       }
       if(floor2 > 120)
       {
            floor3 = 0;
            floor1 = -120;
            floor2 = -240;
       }
       if(floor3 > 120)
       {
            floor1 = 0;
            floor2 = -120;
            floor3 = -240;
       }
        
        one.setOrigin(floor1,-150);
        two.setOrigin(floor2,-150);
        three.setOrigin(floor3,-150);
        
       
        if(Keyboard::isKeyPressed(Keyboard::Key::Space) and playerY < -70)
        {
            playerY += 10;

        }
        if(playerY > -130 and !Keyboard::isKeyPressed(Keyboard::Key::Space))
        {
            playerY -= 10;
        }
        if(playerX == x and playerY == -130)
        {
           // Window.close();
        }
        */
       if(Keyboard::isKeyPressed(Keyboard::Key::C))
       {   
             
             player.ptext2.loadFromFile("psycho.png");
             player.Player.setTexture(&player.ptext2);

       }
       
       
         player.jump(-70,10,10, x2);
        
        
        Window.draw(player.Player);
        obs.setOrigin(x, -130);
        Window.draw(obs);


        
        Window.draw(floor.one);
        Window.draw(floor.two);
        Window.draw(floor.three); 
        plat.setOrigin(x2,-100);
        Window.draw(plat);

        Window.display();
        


        x += 10;
        x2 += 5;


        /*
        floor1 += 10;
        floor2 += 10;
        floor3 += 10;
        */
        
       if(player.playerX == x and player.playerY < -100)
       {
            while(!Keyboard::isKeyPressed(Keyboard::Key::S))
            {
                while(Window.pollEvent(e))
                {
                    if(e.type == e.Closed)
                    {
                        Window.close();
                    }
                }
                RectangleShape Gameover;
                Gameover.setFillColor(Color::Red);
                Gameover.setSize(Vector2f(240,200));
                Gameover.setOrigin(0,0);
                Window.clear();
                Window.draw(Gameover);
                Window.display();     

            }
            start = false;
       }
        
        usleep(55000);
        
    }
        

    //initilize variables
    /*
    Game game(522, 522, "Trig Trot");
    
    
    
    Objects Player;
    //adjust initial variables
    Player.player.setOrigin(Player.player.getRadius(), Player.player.getRadius());
    //Player.player.setPosition(game.getWindowSize("x"), game.getWindowSize("y"));
    Player.player.setFillColor(Color::Green);

    //game loop
    while (game.isRunning()){
        //checks events
        game.events();
        //adjust player's movement
        
        //render updates to window
        //game.update(player, platform1, platform2, platform3);
    }
    */
    
 
    

    return 0;
}