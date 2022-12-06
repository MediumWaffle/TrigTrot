/**
 * @file functions.cpp
 * @ingroup MalAarCal
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Function list for game
 * @date 10-24-2022
 */
#include "header.h"

void startScreen(bool &startW, Game &game, Objects &player, string &playerskin, Objects &cPlayer, string &cplayerskin, Objects &start, bool &nojump, Objects &BackGround, Objects &OBS, Objects &TopObs, Objects &floor, bool &skinmenu){
    while (startW == false)
    {
        game.events();

        player.makePlayer(playerskin);
        cPlayer.makePlayer(cplayerskin);

        player.invis = true;

        RectangleShape Gamestart;
        Texture startg;
        Text enterStart;
        Text sSkins;
        Font textFont;
        textFont.loadFromFile("font.ttf");
        enterStart.setFont(textFont);
        enterStart.setString("Press 'Enter' to start");
        enterStart.setScale(.5,.5);
        enterStart.setPosition(15,150);
        sSkins.setFont(textFont);
        sSkins.setString("Press 'S' for Skins");
        sSkins.setScale(.5,.5);
        sSkins.setPosition(35,170);
        //skin.loadFromFile("sprites/skins.png");
        //tstart.loadFromFile("sprites/start.png");
        startg.loadFromFile("sprites/welcome.png");
        Gamestart.setFillColor(Color::Blue);
        Gamestart.setTexture(&startg);
        //Start.setTexture(&tstart);
        //Skins.setTexture(&skin);
        start.background.setTexture(&startg);
        Gamestart.setSize(Vector2f(240, 200));
        //Start.setSize(Vector2f(100, 50));
        //Skins.setSize(Vector2f(100, 50));
        Gamestart.setOrigin(0, 0);
        //Start.setOrigin(-10, -150);
        //Skins.setOrigin(-130, -150);
        game.clear();
        game.draw(Gamestart);
        player.jump(-70, 10, 10, 1, nojump);
        game.draw(BackGround.background);
        game.draw(BackGround.background2);
        game.draw(player.Player);
        game.draw(OBS.obs);
        game.draw(TopObs.obs);
        game.draw(floor.one);
        game.draw(floor.two);
        game.draw(floor.three);
        game.draw(enterStart);
        game.draw(sSkins);
        floor.moveFloor(120);
        BackGround.moveBackground();
        OBS.moveObs(10);
        TopObs.moveObs(10);

        game.draw(start.background);
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
        skinScreen(skinmenu, player, game, playerskin, cplayerskin);
    }
}

void skinScreen(bool &skinmenu, Objects &player, Game &game, string &playerskin, string &cplayerskin){
    while (skinmenu == true)
    {
        game.events();
        game.clear();
        RectangleShape b, s, p;
        Texture ts, csbg, pt;
        Font tFont;
        tFont.loadFromFile("font.ttf");
        Text skinSelect;
        Text goBack;
        Text skin1;
        Text skin2;
        Text skin3;
        Text skin4;
        Text skin5;
        Text skin6;

        skin1.setFont(tFont);
        skin1.setString("1) Default");
        skin1.setScale(.2,.2);
        skin1.setPosition(90,48);

        skin2.setFont(tFont);
        skin2.setString("2) Psycho");
        skin2.setScale(.2,.2);
        skin2.setPosition(163,48);

        skin3.setFont(tFont);
        skin3.setString("3) Piggy");
        skin3.setScale(.2,.2);
        skin3.setPosition(95,118);

        skin4.setFont(tFont);
        skin4.setString("4) Ghost");
        skin4.setScale(.2,.2);
        skin4.setPosition(163,118);

        skin5.setFont(tFont);
        skin5.setString("5) Steve");
        skin5.setScale(.2,.2);
        skin5.setPosition(93,188);

        skin6.setFont(tFont);
        skin6.setString("6) Spiderman");
        skin6.setScale(.2,.2);
        skin6.setPosition(158,188);

        goBack.setFont(tFont);
        goBack.setString("Press 'B'\nto go back");
        goBack.setScale(.35,.4);
        goBack.setPosition(14,17);

        skinSelect.setFont(tFont);
        skinSelect.setString(" 1 - 6 to\nPick Skin");
        skinSelect.setScale(.4,.4);
        skinSelect.setPosition(12,140);

        player.makePlayer(playerskin);
        player.Player.setOrigin(-10, -50);
        player.Player.setSize(Vector2f(70, 70));
        pt.loadFromFile("sprites/default.png");
        csbg.loadFromFile("sprites/characterSelectBG.png");
        ts.loadFromFile("sprites/charSelect.png");
        s.setTexture(&ts);
        s.setSize(Vector2f(60, 60));
        p.setSize(Vector2f(50, 40));
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
        game.draw(goBack);
        game.draw(skinSelect);
        game.draw(skin1);
        game.draw(skin2);
        game.draw(skin3);
        game.draw(skin4);
        game.draw(skin5);
        game.draw(skin6);
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

void gameScreen(bool &startW, bool &deathscreen, Game &game, Objects &player, string &playerskin, Objects &cPlayer, string &cplayerskin, Objects &floor, Objects &BackGround, bool &nojump, bool &crouch, Objects &OBS, Objects &TopObs, double &n, Text t){
    int move = 240;
    while (startW == true && deathscreen == false)
    {
        double speed = 55000;
        game.events();

        Text tutorial;
        Font tFont;
        
        tFont.loadFromFile("font.ttf");
        tutorial.setFont(tFont);
        tutorial.setString("Space to jump!\nShift to crouch!");
        tutorial.setScale(.4,.4);
        tutorial.setPosition(move,150);

        player.makePlayer(playerskin);
        cPlayer.makePlayer(cplayerskin);

        std::stringstream s;
        s << n;
        string str = s.str();
        t.setString(str);
        if((n > 4.00))
        {
            player.invis = false;
        }
        if(Keyboard::isKeyPressed(Keyboard::Key::I))
        {
            player.invis = true;
        }

        floor.moveFloor(120);
        BackGround.moveBackground();
        player.jump(-70, 10, 10, 1, nojump);
        game.draw(BackGround.background);
        game.draw(BackGround.background2);

        if (Keyboard::isKeyPressed(Keyboard::Key::RShift) || Keyboard::isKeyPressed(Keyboard::Key::LShift)) 
        {
            game.draw(cPlayer.Player);
            crouch = true;
        }
        if (!Keyboard::isKeyPressed(Keyboard::Key::RShift) && !Keyboard::isKeyPressed(Keyboard::Key::LShift))
        {
            game.draw(player.Player);
            crouch = false;
        }
        
        OBS.moveObs(10);
        TopObs.moveObs(10);
        if((TopObs.obsx >= OBS.obsx and TopObs.obsx < OBS.obsx+20))
        {
            TopObs.obsx =  (OBS.obsx+40);
            TopObs.obs.setOrigin(TopObs.obsx,TopObs.obsy);
        }
        if(TopObs.obsx <= OBS.obsx and TopObs.obsx > OBS.obsx-20)
        {
            TopObs.obsx = (OBS.obsx-40);
            TopObs.obs.setOrigin(TopObs.obsx,TopObs.obsy);
        }
        game.draw(OBS.obs);
        game.draw(TopObs.obs);
        
        game.draw(floor.one);
        game.draw(floor.two);
        game.draw(floor.three);
        game.draw(t);
        game.draw(tutorial);
        move -= 5;
        game.display();
        speed -= (n*150);
        usleep(speed);
        n += .06;
        if (((player.playerX == OBS.obsx and player.playerY < -100) or (player.playerX == TopObs.obsx and crouch == false)) and (player.invis == false))
        {
            deathscreen = true;
        }
    }
}

void deathScreen(bool &deathscreen, Game &game, bool &startW, double& n, Text t){
    while (!Keyboard::isKeyPressed(Keyboard::Key::R))
    {
        game.events();

        RectangleShape Gameover;
        Texture over;
        Text gOver;
        Font tFont;
        tFont.loadFromFile("font.ttf");

        gOver.setFont(tFont);
        gOver.setString("Press 'R'\nto Restart");
        gOver.setScale(.3,.3);
        gOver.setPosition(6,90);

        std::stringstream s;
        s << n;
        string str = s.str();
        t.setString("Score: "+str);
        t.setPosition(Vector2f(20, 160));
        t.setFillColor(Color::Red);

        over.loadFromFile("sprites/gameover.png");
        Gameover.setTexture(&over);
        Gameover.setSize(Vector2f(240, 200));
        Gameover.setOrigin(0, 0);

        game.clear();
        game.draw(Gameover);
        game.draw(t);
        game.draw(gOver);
        game.display();
    }
    deathscreen = false;
    startW = false;
}
