#include "Objects.h"

void Objects::makeFloor(int s)
{
    one.setSize(sf::Vector2f(s, 50));
    one.setFillColor(Color::Blue);
    two.setSize(sf::Vector2f(s,50));
    two.setFillColor(Color::Red);
    three.setSize(Vector2f(s,50));
    three.setFillColor(Color::Green);

    floor1 = 0;
    floor2 = floor1-s;
    floor3 = floor1-(s*2);

    one.setOrigin(floor1,-150);
    two.setOrigin(floor2,-150);
    three.setOrigin(floor3,-150);

}

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