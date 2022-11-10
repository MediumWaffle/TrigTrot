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
        void update(CircleShape player, RectangleShape platform1, RectangleShape platform2, RectangleShape platform3);
        unsigned int getWindowSize(std::string xy);
        bool isRunning();
    private:
        Event e;
        RenderWindow window;
};

#endif