/**
 * @file main.cpp
 * @ingroup MalAarCal
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Primary file for game loop
 * @date 10-24-2022
 */
#include "header.h"
//#include "Game.h"

int main()
{
    Game game(240, 200, "Trig Trot");

    string playerskin = "sprites/default.png";
    string cplayerskin = "sprites/default_crouch.png";

    bool nojump = true;
    bool crouch = false;
    bool skinmenu = false;

    Music intro;
    intro.openFromFile("music/intro.wav");
    Music ingame;
    ingame.openFromFile("music/play.wav");
    Music dead;
    dead.openFromFile("music/dead.wav");

    Objects floor;
    Objects player;
    Objects cPlayer;
    Objects BackGround;
    Objects start;
    Objects OBS;
    Objects TopObs;

    start.background.setSize(Vector2f(230, 100));
    start.background.setPosition(5, 5);
    BackGround.makeBackground(240);
    player.makePlayer(playerskin);
    cPlayer.makePlayer(cplayerskin);
    floor.makeFloor(120);
    OBS.makeObs(-240, -130);
    TopObs.makeTopObs(-340, 0);
    bool startW = false;
    bool deathscreen = false;

    while (game.isRunning())
    {

        game.events();
        // ingame.play();

        if (startW == false)
        {
            // ingame.stop();
            dead.stop();
            intro.play();
            while (startW == false)
            {
                game.events();

                player.makePlayer(playerskin);
                cPlayer.makePlayer(cplayerskin);

                RectangleShape Gamestart;
                RectangleShape Start;
                RectangleShape Skins;
                Texture tstart;
                Texture skin;
                Texture startg;
                skin.loadFromFile("sprites/skins.png");
                tstart.loadFromFile("sprites/start.png");
                startg.loadFromFile("sprites/welcome.png");
                Gamestart.setFillColor(Color::Blue);
                Gamestart.setTexture(&startg);
                Start.setTexture(&tstart);
                Skins.setTexture(&skin);
                start.background.setTexture(&startg);
                Gamestart.setSize(Vector2f(240, 200));
                Start.setSize(Vector2f(100, 50));
                Skins.setSize(Vector2f(100, 50));
                Gamestart.setOrigin(0, 0);
                Start.setOrigin(-10, -150);
                Skins.setOrigin(-130, -150);
                // Window.clear();
                game.clear();
                // Window.draw(Gamestart);
                game.draw(Gamestart);
                player.jump(-70, 10, 10, 1, nojump);
                // Window.draw(BackGround.background);
                game.draw(BackGround.background);
                // Window.draw(BackGround.background2);
                game.draw(BackGround.background2);
                // Window.draw(player.Player);
                game.draw(player.Player);

                // Window.draw(obs);
                game.draw(OBS.obs);
                game.draw(TopObs.obs);
                // Window.draw(floor.one);
                game.draw(floor.one);
                // Window.draw(floor.two);
                game.draw(floor.two);
                // Window.draw(floor.three);
                game.draw(floor.three);
                game.draw(Start);
                game.draw(Skins);
                floor.moveFloor(120);
                BackGround.moveBackground();
                OBS.moveObs(10);
                TopObs.moveObs(10);

                // Window.draw(start.background);
                game.draw(start.background);
                // Window.display();
                game.display();
                usleep(55000);

                if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
                {
                    startW = true;
                }
                if (Keyboard::isKeyPressed(Keyboard::Key::S))
                {
                    skinmenu = true;
                }
                while (skinmenu == true)
                {
                    game.clear();
                    RectangleShape b, s, p;
                    Texture ts, csbg, pt;
                    player.makePlayer(playerskin);
                    player.Player.setOrigin(-10, -50);
                    player.Player.setSize(Vector2f(70, 70));
                    pt.loadFromFile("sprites/default.png");
                    csbg.loadFromFile("sprites/characterSelectBG.png");
                    ts.loadFromFile("sprites/charSelect.png");
                    s.setTexture(&ts);
                    s.setSize(Vector2f(60, 60));
                    p.setSize(Vector2f(50, 40));
                    // b.setFillColor(Color::Blue);
                    b.setTexture(&csbg);
                    b.setSize(Vector2f(240, 200));
                    b.setOrigin(0, 0);

                    p.setTexture(&pt);
                    p.setOrigin(-85, -2.5);
                    s.setOrigin(-80, -0);
                    game.draw(b);
                    game.draw(s);
                    game.draw(p);
                    game.draw(player.Player);

                    s.setOrigin(-150, -0);
                    p.setOrigin(-155, -2.5);
                    pt.loadFromFile("sprites/psycho.png");
                    p.setTexture(&pt);
                    game.draw(s);
                    game.draw(p);

                    s.setOrigin(-80, -70);
                    p.setOrigin(-85, -72.5);
                    pt.loadFromFile("sprites/piggy.png");
                    p.setTexture(&pt);
                    game.draw(s);
                    game.draw(p);

                    s.setOrigin(-150, -70);
                    p.setOrigin(-155, -72.5);
                    pt.loadFromFile("sprites/ghost.png");
                    p.setTexture(&pt);
                    game.draw(s);
                    game.draw(p);

                    s.setOrigin(-80, -140);
                    p.setOrigin(-85, -142.5);
                    pt.loadFromFile("sprites/minecraft.png");
                    p.setTexture(&pt);
                    game.draw(s);
                    game.draw(p);

                    s.setOrigin(-150, -140);
                    p.setOrigin(-155, -142.5);
                    pt.loadFromFile("sprites/spiderman.png");
                    p.setTexture(&pt);
                    game.draw(s);
                    game.draw(p);
                    game.display();

                    if (Keyboard::isKeyPressed(Keyboard::Key::B))
                    {
                        skinmenu = false;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::Num1))
                    {
                        playerskin = "sprites/default.png";
                        cplayerskin = "sprites/default_crouch.png";
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::Num2))
                    {
                        playerskin = "sprites/psycho.png";
                        cplayerskin = "sprites/psycho_crouch.png";
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::Num3))
                    {
                        playerskin = "sprites/piggy.png";
                        cplayerskin = "sprites/piggy_crouch.png";
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::Num4))
                    {
                        playerskin = "sprites/ghost.png";
                        cplayerskin = "sprites/ghost_crouch.png";
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::Num5))
                    {
                        playerskin = "sprites/minecraft.png";
                        cplayerskin = "sprites/minecraft_crouch.png";
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Key::Num6))
                    {
                        playerskin = "sprites/spiderman.png";
                        cplayerskin = "sprites/spiderman_crouch.png";
                    }
                }
            }
        }
        if (startW == true && deathscreen == false){
            ingame.play();
            while (startW == true && deathscreen == false)
            {
                game.events();
                intro.stop();

                player.makePlayer(playerskin);
                cPlayer.makePlayer(cplayerskin);

                floor.moveFloor(120);
                BackGround.moveBackground();
                player.jump(-70, 10, 10, 1, nojump);
                game.draw(BackGround.background);
                game.draw(BackGround.background2);

                if (Keyboard::isKeyPressed(Keyboard::Key::Down))
                {
                    game.draw(cPlayer.Player);
                    crouch = true;
                }
                if (!Keyboard::isKeyPressed(Keyboard::Key::Down))
                {
                    game.draw(player.Player);
                    crouch = false;
                }
                game.draw(OBS.obs);
                game.draw(TopObs.obs);
                OBS.moveObs(10);
                TopObs.moveObs(10);
                game.draw(floor.one);
                game.draw(floor.two);
                game.draw(floor.three);
                game.display();
                usleep(55000);
                if ((player.playerX == OBS.obsx and player.playerY < -100) or (player.playerX == TopObs.obsx and crouch == false))
                {
                    deathscreen = true;
                }
            }
        }

        if (deathscreen)
        {
            ingame.stop();
            dead.setPlayingOffset(seconds(25.3f));
            // dead.play();
            dead.play();
            // intro.play();

            while (!Keyboard::isKeyPressed(Keyboard::Key::R))
            {

                game.events();

                RectangleShape Gameover;
                Texture over;

                over.loadFromFile("sprites/gameover.png");
                Gameover.setTexture(&over);
                // Gameover.setFillColor(Color::Red);
                Gameover.setSize(Vector2f(240, 200));
                Gameover.setOrigin(0, 0);

                // Window.clear();
                game.clear();
                // Window.draw(Gameover);
                game.draw(Gameover);
                // Window.display();
                game.display();
            }
            deathscreen = false;
            startW = false;
        }
    }
    return 0;
}
