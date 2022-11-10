/**
 * @file main.cpp
 * @GroupName MalAarCal
 * @GroupMembers Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Primary file for game loop
 * @date 10-24-2022
 */

//DO NOT FORGET TO CHECK README.md FREQUENTLY!!! Important updates and notes should be made here!

#include "header.h"



int main()
{
       
    
    
    RenderWindow Window(VideoMode(240,200), "Game",Style::Default);
    
   
    /*
    RectangleShape one;
    RectangleShape two;
    RectangleShape three;
    */
    RectangleShape obs;
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
    obs.setFillColor(Color(0,0,255));
    obs.setSize(Vector2f(20,20));
    obs.setOrigin(x,-130);
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
       
         player.jump(-70,10,10);
        
        
        Window.draw(player.player);
        obs.setOrigin(x, -130);
        Window.draw(obs);


        
        Window.draw(floor.one);
        Window.draw(floor.two);
        Window.draw(floor.three); 
        obs.setOrigin(x2,-100);
        Window.draw(obs);

        Window.display();
        


        x += 10;
        x2 += 5;


        /*
        floor1 += 10;
        floor2 += 10;
        floor3 += 10;
        */
        
       if(player.playerX == x and player.playerY < -90)
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
            
       }
        
        usleep(55000);
        

    }
    
 
    


    return 0;
}