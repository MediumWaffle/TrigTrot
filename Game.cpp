#include "Game.h"

Game::Game(int winSizeX, int winSizeY, std::string gameName){
    window.create(VideoMode(winSizeX,winSizeY), gameName, Style::Default);
}

void Game::events(){
    while(window.pollEvent(e)){
        if (e.type == e.Closed){
            window.close();
        }
    }
}

void Game::update(CircleShape player, RectangleShape platform1, RectangleShape platform2, RectangleShape platform3){
    window.clear();
    window.draw(player);
    window.draw(platform1);
    window.draw(platform2);
    window.draw(platform3);
    window.display();
}

unsigned int Game::getWindowSize(std::string xy){
    if(xy == "x"){
        return window.getSize().x;
    } else if(xy == "y"){
        return window.getSize().y;
    }
    return 0;
}

bool Game::isRunning(){
    if(window.isOpen())
        return true;
    
    return false;
}