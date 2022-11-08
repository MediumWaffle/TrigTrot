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
    RectangleShape player;

    /*
    one.setSize(sf::Vector2f(120, 50));
    one.setFillColor(Color::Blue);
    two.setSize(sf::Vector2f(120,50));
    two.setFillColor(Color::Red);
    three.setSize(Vector2f(120,50));
    three.setFillColor(Color::Green);
    */
    int x = -240;
    /*
    int floor1 = 0;
    int floor2 = floor1-120;
    int floor3 = floor1-240;
    */
    obs.setFillColor(Color(0,0,255));
    obs.setSize(Vector2f(20,20));
    obs.setOrigin(x,-100);

    player.setSize(Vector2f(25,25));
    player.setFillColor(Color(255,255,255));
    player.setOrigin(-40,-130);


    
    /*
    one.setOrigin(floor1,-150);
    two.setOrigin(floor2,-150);
    three.setOrigin(floor3,-150);
    */
    Objects floor;
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

        
    
        if(x > -10)
        {
            x=-240;
            
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
        */

        Window.draw(player);
        Window.draw(obs);


        
        Window.draw(floor.one);
        Window.draw(floor.two);
        Window.draw(floor.three);    
        Window.display();
        


        x += 10;


        /*
        floor1 += 10;
        floor2 += 10;
        floor3 += 10;
        */
        obs.setOrigin(x, -100);
        usleep(55000);
    }


    return 0;
}