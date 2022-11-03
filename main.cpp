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
    RectangleShape one;
    RectangleShape two;
    RectangleShape three;
    RectangleShape obs;

    one.setSize(sf::Vector2f(80, 50));
    one.setFillColor(Color(255,0,0));
    two.setSize(sf::Vector2f(80,50));
    two.setFillColor(Color(200,0,0));
    three.setSize(Vector2f(80,50));
    three.setFillColor(Color(150,0,0));
    int x = -240;
    obs.setFillColor(Color(0,0,255));
    obs.setSize(Vector2f(20,20));
    obs.setOrigin(x,-100);


    int c=1;
    
    one.setOrigin(0,-150);
    two.setOrigin(-80,-150);
    three.setOrigin(-160,-150);
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
        if(c == 1)
        {
            one.setFillColor(Color(200,0,0));
            two.setFillColor(Color(150,0,0));
            three.setFillColor(Color(255,0,0));
            c = 2;
        }
        else if(c == 2)
        {
            one.setFillColor(Color(150,0,0));
            two.setFillColor(Color(255,0,0));
            three.setFillColor(Color(200,0,0));
            c = 3;
        }
        else if(c == 3)
        {
            one.setFillColor(Color(255,0,0));
            two.setFillColor(Color(200,0,0));
            three.setFillColor(Color(150,0,0));
            c = 1;

        }
        if(x > -10)
        {
            x=-240;
            
        } 
        Window.draw(obs);
       // obs.move(-10,0);
        
        Window.draw(one);
        Window.draw(two);
        Window.draw(three);
        usleep(25000);
        Window.display();
        x += 10;
        obs.setOrigin(x, -100);
        
    }


    return 0;
}