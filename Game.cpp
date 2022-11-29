#include "Game.h"

Game::Game(int winSizeX, int winSizeY, std::string gameName){
    window.create(VideoMode(winSizeX,winSizeY), gameName, Style::Default);
}

void Game::events(){
    while(window.pollEvent(e)){
        if (e.type == e.Closed){
            window.close();
            exit(0);
        }
    }
}

void Game::display(){
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

void Game::draw(CircleShape &c){
    window.draw(c);
}

void Game::draw(RectangleShape &s){
    window.draw(s);
}

void Game::clear(){
    window.clear();
}

void Game::draw(Text &t){
    window.draw(t);
}