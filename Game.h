#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class Game
{
    public:
        Game(int winSizeX, int winSizeY, std::string gameName);
        ~Game(){}
        void events();
        void display();
        unsigned int getWindowSize(std::string xy);
        bool isRunning();
        void draw(CircleShape &c);
        void draw(RectangleShape &s);
        void clear();
    private:
        Event e;
        RenderWindow window;
};

#endif