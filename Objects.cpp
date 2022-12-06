/**
 * @file functions.cpp
 * @ingroup MalAarCal
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Function list for game
 * @date 10-24-2022
 */
#include "header.h"
//#include "Objects.h"

/**
 * @brief Initilizes the floor, loads in the .png files and sets size and posistion
 * @param s sets lengh of floor all must be the same
 * @author Malik Robinson
 */
void Objects::makeFloor(int s)
{
     
     text1.loadFromFile("sprites/floorNormal.png");
     text2.loadFromFile("sprites/floorWater.png");
     text3.loadFromFile("sprites/floorBones.png");

 
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
/**
 * @brief Moves all 3 floor objects in synce 
 * 
 * @param s the lenght of the floor objects
 * @author Malik Robinson
 */
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
/**
 * @brief Controlls the jumping logic and checks player position 
 * 
 * @param height how high the player can jump
 * @param falls how fast the player falls 
 * @param rises how fast the player rises
 * @param plat tracks plattform if one is used
 * @param nojump tracks if the player has already jumped so there can not be flying
 * @author Malik Robinson
 */
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
/**
 * @brief initializes the player character, setting the size and position
 * 
 * @param t A .png file that gives the player character a skin
 * @author Malik Robinson
 */
void Objects::makePlayer(std::string t)
{
     
     ptext.loadFromFile(t);
     ptext2.loadFromFile(t);
     Player.setSize(Vector2f(25,25));
     Player.setTexture(&ptext);
     //player.setFillColor(Color(255,255,255));
     Player.setOrigin(playerX,playerY);
}
/**
 * @brief Initillizes the background, setting the .png file size and position 
 * 
 * @param s the size of the background
 * @author Malik Robinson
 */
void Objects::makeBackground(int s)
{
     background.setOrigin(backx,0);
    background.setSize(Vector2f(s,150));
    background2.setOrigin(backx2,0);
    background2.setSize(Vector2f(s,150));
    back.loadFromFile("sprites/caveWallMerge.png");
    background.setTexture(&back);
    background2.setTexture(&back);
}
/**
 * @brief Initilizes the bottom Spike objects 
 * 
 * @param x set the initial x position
 * @param y set the initial y position
 * @author Malik Robinson
 */
void Objects::makeObs(int x, int y)
{
     obsx = x;
     obsy = y;
     obst.loadFromFile("sprites/caveSpike.png");
     obs.setSize(Vector2f(20,20));
    obs.setTexture(&obst);
    obs.setOrigin(obsx,obsy);
    top = false;

}
/**
 * @brief Initilizes the top spike objects
 * 
 * @param x set the initial x position
 * @param y set the initial y position
 * @author Malik Robinson
 */
void Objects::makeTopObs(int x, int y)
{
     obsx = x;
     obsy = y;
     obst.loadFromFile("sprites/topSpike.png");
     obs.setSize(Vector2f(50,130));
     obs.setTexture(&obst);
     obs.setOrigin(x,y);
     top = true;


}
/**
 * @brief Moves the Spike objects accross the screen
 * 
 * @param speed speed the objects move
 * @author Malik Robinson
 */
void Objects::moveObs(int speed)
{
     /*
     srand(time(NULL));
     int r = rand();
     */
     obsx += speed;
     obs.setOrigin(obsx,obsy);
     if(obsx > 20 and top == false)
     {
          obsx = -240;   
     }
     if(obsx > 20 and top == true)
     {
          obsx = -340;   
     }
     
}

/**
 * @brief Moves the Background 
 * @author Malik Robinson
 * 
 */
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
