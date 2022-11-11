/**
 * @file functions.cpp
 * @ingroup MalAarCal
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Function list for game
 * @date 10-24-2022
 */
#include "header.h"
//sets the rectengles used for the floor to the right texture the s is for size
void Objects::makeFloor(int s)
{
     
     text1.loadFromFile("floorNormal.png");
     text2.loadFromFile("floorWater.png");
     text3.loadFromFile("floorBones.png");

 
    one.setSize(sf::Vector2f(s, 50));
    //one.setFillColor(Color::Blue);
    one.setTexture(&text1);
    two.setSize(sf::Vector2f(s,50));
    //two.setFillColor(Color::Red);
    two.setTexture(&text2);
    three.setSize(Vector2f(s,50));
    //three.setFillColor(Color::Green);
    three.setTexture(&text3);


    floor1 = 0;
    floor2 = floor1-s;
    floor3 = floor1-(s*2);

    one.setOrigin(floor1,-150);
    two.setOrigin(floor2,-150);
    three.setOrigin(floor3,-150);

}
//moves the floor s is the offset it should be the same as the size of the blocks
void Objects::moveFloor(int s)
{
     if(floor1 > s)
       {
            floor2 = 0;
            floor3 = 0-s;
            floor1 = 0-(s*2);
       }
       if(floor2 > s)
       {
            floor3 = 0;
            floor1 = 0-s;
            floor2 = 0-(s*2);
       }
       if(floor3 > s)
       {
            floor1 = 0;
            floor2 = 0-s;
            floor3 = 0-(s*2);
       }
        
        one.setOrigin(floor1,-150);
        two.setOrigin(floor2,-150);
        three.setOrigin(floor3,-150);

        floor1 += 10;
        floor2 += 10;
        floor3 += 10;

}
//the function that controls the jump logic the height of the jump as well as the speed going up and down can be controlled
void Objects::jump(int height, int falls, int rises, int plat, bool &nojump)
{
     
     
     if(Keyboard::isKeyPressed(Keyboard::Key::Space) and playerY <= height and nojump == true)
        {
          
               playerY += rises;
               Player.setOrigin(playerX, playerY);
               if(playerY >= height)
               {
                    nojump = false;
               }
          
        }
        if((nojump == false) or (playerY > -120 and !Keyboard::isKeyPressed(Keyboard::Key::Space)))
        {
            playerY -= falls;

            Player.setOrigin(playerX, playerY);
            if(playerY < -118)
            {
               nojump = true;
            }
        }
}
//Makes and sets the player to defuault will need to be changed when skin select is done
void Objects::makePlayer()
{
     
     ptext.loadFromFile("default.png");
     Player.setRadius(25/2);
     Player.setTexture(&ptext);
     //player.setFillColor(Color(255,255,255));
     Player.setOrigin(playerX,playerY);
}
//sets the background this works fine just need to agree on the background texture
void Objects::makeBackground(int s)
{
     background.setOrigin(backx,0);
    background.setSize(Vector2f(s,150));
    background2.setOrigin(backx2,0);
    background2.setSize(Vector2f(s,150));
    back.loadFromFile("cavewall.png");
    background.setTexture(&back);
    background2.setTexture(&back);
}
//movess the background might change to make speed ajustable
void Objects::moveBackground()
{
     if(backx2 == 0)
        {
            backx = -240;
            backx2 = 0;
        }
        if(backx == 0)
        {
            backx = 0;
            backx2 = -240;
        }

        background.setOrigin(backx,0);
        background2.setOrigin(backx2,0);

        backx += 2;
        backx2 += 2;

}
