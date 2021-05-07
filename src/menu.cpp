#include <iostream>
#include <cstdlib>
#include "Personages.h"
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "game_map1.h"
#include "game_map2.h"
#include "player.h"
#include "enemy.h"
#include <string>
#include <vector>
using namespace sf;
//if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
void menu(RenderWindow& window )
{
    Music music;
    music.openFromFile("../Sound/March.ogg");
    music.play();

    Image     menubackground;       menubackground.loadFromFile("../Images/menu/menu.jpg");
    //run.createMaskFromColor(Color(41, 33, 59));
    Texture   menutexture;          menutexture.loadFromImage(menubackground);
    Sprite    menusprite;           menusprite.setTexture(menutexture);
    menusprite.setPosition(0, 0);



    Image     run;              run.loadFromFile("../Images/menu/Start.jpg");
    //run.createMaskFromColor(Color(0, 0, 0));
   // run.createMaskFromColor(Color(41, 33, 59));
    Texture   runtexture;       runtexture.loadFromImage(run);
    Sprite    runsprite;        runsprite.setTexture(runtexture);
    runsprite.setPosition(150, 150);
    runsprite.setScale(0.3f, 0.3f);

    //-------------------------------------------------------level made

    Image     exitgame;             exitgame.loadFromFile("../Images/menu/exit.png");

    Texture   exitgametexture;      exitgametexture.loadFromImage(exitgame);
    Sprite    exitgamesprite;       exitgamesprite.setTexture(exitgametexture);
    exitgamesprite.setPosition(600, 120);
    exitgamesprite.setScale(0.15f, 0.15f);

    /*//-------------------------------------------------exit made

    Image     info;             info.loadFromFile("../Images/menu/about.png");
    Texture   infotexture;      infotexture.loadFromImage(info);
    Sprite    infosprite;       infosprite.setTexture(infotexture);
    infosprite.setPosition(1100, 10);
*/
    //-------------------------------------------------about made
    music.setLoop(true);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        int menuNum = 0;

        //--------------------------------------------making color when aiming

            if (IntRect(150, 150, 240, 180).contains(Mouse::getPosition(window))) { runsprite.setColor(Color::Green); menuNum = 0; }

        if (IntRect(600, 120, 240, 240).contains(Mouse::getPosition(window))) { exitgamesprite.setColor(Color::Red); menuNum = 1; }

        //-------------------------------------------clearing color when out
        if (!IntRect(150, 150, 240, 180).contains(Mouse::getPosition(window))) { runsprite.setColor(Color::White); }

        if (!IntRect(600, 120, 240, 240).contains(Mouse::getPosition(window))) { exitgamesprite.setColor(Color::White); }


        if (Mouse::isButtonPressed(Mouse::Left))
        {
            switch (menuNum)
            {
                case 0:
                {   music.pause();
                    RenderWindow new_window(VideoMode(1920, 1080), "LEVEL");
                    window.close();

                   start_menu_levels(new_window);
                    new_window.close();


                    break;
                }


                case 1:
                    window.close();
                    break;

                default:
                    break;
            }
            if (menuNum ==0)
            {
                RenderWindow after_window(VideoMode(1920, 1080), "IGRA");
                menu(after_window);
            }


        }
        window.clear();
        window.draw(menusprite);
        window.draw(runsprite);
        window.draw(exitgamesprite);


        window.display();
    }
}

    void start_menu_levels(RenderWindow& window1)
{

    Image     level1;             level1.loadFromFile("../Images/menu/level1.png");
    Texture   level1texture;      level1texture.loadFromImage(level1);
    Sprite    level1sprite;       level1sprite.setTexture(level1texture);
    level1sprite.setPosition(0, 0);
    Image     level2;             level2.loadFromFile("../Images/menu/level2.png");
    Texture   level2texture;      level2texture.loadFromImage(level2);
    Sprite    level2sprite;       level2sprite.setTexture(level2texture);
    level2sprite.setPosition(0, 250);

    Image     leveld;             leveld.loadFromFile("../Images/menu/leveld.jpg");
    Texture   leveldtexture;      leveldtexture.loadFromImage(leveld);
    Sprite    leveldsprite;       leveldsprite.setTexture(leveldtexture);
    leveldsprite.setPosition(0, 0);




    while (window1.isOpen())
    {
        Event event1;
        while (window1.pollEvent(event1))
            if (event1.type == Event::Closed)
                window1.close();
        int level=0;
        if (IntRect(0, 0, 216, 87).contains(Mouse::getPosition(window1))) { level1sprite.setColor(Color::Green); level = 0; }
        if (IntRect(0, 250, 215, 87).contains(Mouse::getPosition(window1))) { level2sprite.setColor(Color::Blue); level = 1; }

        if (!IntRect(0, 0, 216, 87).contains(Mouse::getPosition(window1))) { level1sprite.setColor(Color::White);  }
        if (!IntRect(0, 250, 215, 87).contains(Mouse::getPosition(window1))) { level2sprite.setColor(Color::White); }


        if (Mouse::isButtonPressed(Mouse::Left))
        {
            switch (level)
            {
                case 0:
                {
                    RenderWindow new_window(VideoMode(1920, 1080), "level1");
                    window1.close();
                    run_level(new_window, 1);
                    break;
                }


                case 1:
                {   RenderWindow new_window(VideoMode(1920, 1080), "level2");
                    window1.close();
                    run_level(new_window, 2);
                    break;
                }

                default:
                    break;

            }


        }

        window1.clear();
        window1.draw(leveldsprite);
        window1.draw(level1sprite);
        window1.draw(level2sprite);


        // window.draw(textsprite);
        window1.display();
    }






};

void run_level(RenderWindow& window,int i)
{//window.close();
    Font font;
    font.loadFromFile("../font/CyrilicOld.ttf");
    sf::Text text("", font, 16);
    sf::Text text1("", font, 16);
    text.setFillColor(Color::Green);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text1.setFillColor(Color::Red);
    text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
    View view;

    float CurrentFrame = 0;
    Clock clock;
    Clock gameTimeClock;
    int gameTime = 0;
    view.reset(FloatRect(0, 0, 640, 480));
    Image     mapimg;       mapimg.loadFromFile("../Images/map/err.png");
    //run.createMaskFromColor(Color(41, 33, 59));
    Texture   maptexture;          maptexture.loadFromImage(mapimg);
    Sprite    map;           map.setTexture(maptexture);
    map.setPosition(0, 0);


    Image heroImage;
    heroImage.loadFromFile("../Images/characters/mando.png");
    Image enemyImage;
    enemyImage.loadFromFile("../Images/characters/Grogy.png");
   /*
    Image easyEnemyImage;
    easyEnemyImage.loadFromFile("../Images/menu/exit.png");
    easyEnemyImage.createMaskFromColor(Color(255, 0, 0));//сделали маску по цвету.но лучше изначально иметь прозрачную картинку
*/
    Image mapp;
    mapp.loadFromFile("../Images/map/eee3.png");
    Texture map1;
    map1.loadFromImage(mapp);
    Sprite s_map1;
    s_map1.setTexture(map1);
    int k,j,i1;
    k = rand() % 6 + 5;
    if (i==1) {
        for (int k1 = 0; k1 < k; k1++) {
            i1 = rand() % 14 + 10;

            j = rand() % 40 + 3;

            map1::TMap[i1][j] = 'y';
        }
    }
    else if (i==2)
    {
        for (int k1 = 0; k1 < k; k1++) {
            i1 = rand() % 14 + 10;

            j = rand() % 40 + 3;

            map2::TMap[i1][j] = 'y';
        }
    }





    std::vector<Personages*>  enemies;// создали вектор врагов
if (i==1) {
    int l = 4; //число врагов на карте
    for (int i = 0; i < l; i++)
        enemies.push_back(new Enemy(enemyImage, 200 + i * 300, 200, 120.0, 80.0, "enemy"));
}
    if (i==2) {
        int l = 5; //число врагов на карте
        for (int i = 0; i < l; i++)
            enemies.push_back(new Enemy(enemyImage, 200 + i * 200, 200, 120.0, 80.0, "enemy"));
    }
Player p(heroImage, 32, 500,32.0,46.0,"Player1");//объект класса игрока
    //Enemy e(enemyImage, 500, 200,120.0,80.0,"enemy");
   // Enemy e2(enemyImage, 1000, 200,120.0,80.0,"enemy");//объект класса игрока
    //Enemy easyEnemy(easyEnemyImage, 850, 671,200,97,"EasyEnemy");//простой враг, объект класса врага
    Music music;
    music.openFromFile("../Sound/March.ogg");
    music.play();
    music.setLoop(true);

    while (window.isOpen())
    {float time = clock.getElapsedTime().asMicroseconds();
        {

            std::ostringstream IgrokScore, aat;
            std::ostringstream IgrokLife, gameTimeString;
            IgrokScore << p.get_score();
            gameTimeString << gameTime;
            aat << k-2;
            IgrokLife << p.get_life();
            text.setString(
                    "Collected scores " + IgrokScore.str() + "/" + aat.str() + "\n Time played: " + gameTimeString.str());
            text1.setString("Amount of health:" + IgrokLife.str());
            if (int(p.get_x()) < 400 ) {
                text.setPosition(p.get_x() + 100, p.get_y() - 200);
                text1.setPosition(p.get_x() + 100, p.get_y() - 220);

            }
            if (int(p.get_x()) >1200){
                text.setPosition(p.get_x() - 250, p.get_y() - 200);
                text1.setPosition(p.get_x() - 250, p.get_y() - 220);

            }
            else
            {text.setPosition(p.get_x() - 0, p.get_y() - 200);
                text1.setPosition(p.get_x() - 0, p.get_y() - 220);

            }



        }
        if (p.get_life()>0 && p.get_score()!=(k-2)) gameTime = gameTimeClock.getElapsedTime().asSeconds();
        else if (p.get_life()<=0)

        {

            std::ostringstream IgrokScore;
            std::ostringstream IgrokLife, gameTimeString;
            IgrokScore << p.get_score();
            gameTimeString << gameTime;

            IgrokLife << p.get_life();
            text.setString( "This is the way");
            //text1.setString("Количество жизней:" + IgrokLife.str());
            text.setCharacterSize(50);

            text.setPosition(p.get_x() , p.get_y()-100 );
            //text1.setPosition(p.x - 150, p.y + 140);

            view.rotate(0.01);

        }
        else if (p.get_score()>=(k-2) && p.Proverka())
        {
            std::ostringstream IgrokScore;
            std::ostringstream IgrokLife, gameTimeString;
            IgrokScore << p.get_score();
            gameTimeString << gameTime;

            IgrokLife << p.get_life();
            String levelstr;
            levelstr="The level complited:";
            levelstr+=std::to_string(i);
            text.setString(levelstr);
            //text1.setString("Количество жизней:" + IgrokLife.str());
            text.setCharacterSize(20);

            text.setPosition(p.get_x()-300, p.get_y() - 100);
            //text1.setPosition(p.x - 150, p.y + 140);
            break;


        }

        clock.restart();
        time = time / 1500;
        p.set_proverka();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        p.update(time,i);// Player update function
       // easyEnemy.update(time);//easyEnemy update function
        view.setCenter(p.get_x(), p.get_y());
        std::vector<Personages*>::iterator it;
        for (it = enemies.begin(); it != enemies.end();) {
            Personages *h = *it;
            h->update(time, i);
           // std::cout<<std::to_string( h->get_life());
            if (h->get_life() <= 0) {
                enemies.erase(it);
                delete h;

            }
            else it++;
        }

        for (it = enemies.begin(); it != enemies.end(); it++)//проходимся по эл-там списка
        {
            if ((*it)->getRect().intersects(p.getRect()))//если прямоугольник спрайта объекта пересекается с игроком
            {std::cout<<"ss";
                Personages *h = *it;
                std::cout<<std::to_string(p.get_dy())<<" "<<std::boolalpha<<(p.get_onGround());
                    if ((p.get_dy()>0) && (p.get_onGround() == false)) {
                        //(*it)->set_dx();
                         p.change_dy(-0.3); h->change_life(-100) ; }//если прыгнули на врага,то даем врагу скорость 0,отпрыгиваем от него чуть вверх,даем ему здоровье 0
                    else {

                        p.change_dy(-1);
                        p.change_life(-1);
                        //std::cout<<std::to_string(p.get_life());
                        //иначе враг подошел к нам сбоку и нанес урон
                    }

            }
        }
        window.clear();

        window.clear(Color(128, 106, 89));
        int ur = 1;
        if (i==1) {

            for (int i = 0; i < map1::HEIGHT_MAP; i++)
                for (int j = 0; j < map1::WIDTH_MAP; j++) {
                    if (map1::TMap[i][j] == 'y') {
                        s_map1.setTextureRect(IntRect(32, 0, 32, 32));
                        CurrentFrame += 0.001 * time;
                        if (CurrentFrame > 5) {
                            CurrentFrame -= 5;
                            ur++;
                        }
                        if (ur = 1) { s_map1.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32)); }
                        if (ur = 2) { s_map1.setTextureRect(IntRect(32 * int(CurrentFrame), 32, 32, 32)); }
                        if (ur = 3) { s_map1.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32)); }


                        s_map1.setPosition(j * 32, i * 32);
                        window.draw(s_map1);

                        if (ur > 5) ur = 1;
                    } else {
                        if (map1::TMap[i][j] == ' ') map.setTextureRect(IntRect(128, 0, 32, 32));
                        if (map1::TMap[i][j] == 'r') map.setTextureRect(IntRect(192, 320, 32, 32));
                        if ((map1::TMap[i][j] == '0')) map.setTextureRect(IntRect(256, 0, 32, 32));
                        if ((map1::TMap[i][j] == 'l')) map.setTextureRect(IntRect(480, 448, 32, 32));
                        if ((map1::TMap[i][j] == 'k')) map.setTextureRect(IntRect(0, 32, 32, 32));
                        if ((map1::TMap[i][j] == 't')) map.setTextureRect(IntRect(96, 128, 32, 32));

                        map.setPosition(j * 32, i * 32);

                        window.draw(map);
                    }
                }
        }
        else if (i==2){
            for (int i = 0; i < map2::HEIGHT_MAP; i++)
                for (int j = 0; j < map2::WIDTH_MAP; j++) {
                    if (map2::TMap[i][j] == 'y') {
                        s_map1.setTextureRect(IntRect(32, 0, 32, 32));
                        CurrentFrame += 0.001 * time;
                        if (CurrentFrame > 5) {
                            CurrentFrame -= 5;
                            ur++;
                        }
                        if (ur = 1) { s_map1.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32)); }
                        if (ur = 2) { s_map1.setTextureRect(IntRect(32 * int(CurrentFrame), 32, 32, 32)); }
                        if (ur = 3) { s_map1.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32)); }


                        s_map1.setPosition(j * 32, i * 32);
                        window.draw(s_map1);

                        if (ur > 5) ur = 1;
                    } else {
                        if (map2::TMap[i][j] == ' ') map.setTextureRect(IntRect(128, 0, 32, 32));
                        if (map2::TMap[i][j] == 'r') map.setTextureRect(IntRect(192, 320, 32, 32));
                        if ((map2::TMap[i][j] == '0')) map.setTextureRect(IntRect(256, 0, 32, 32));
                        if ((map2::TMap[i][j] == 'l')) map.setTextureRect(IntRect(480, 448, 32, 32));
                        if ((map2::TMap[i][j] == 'k')) map.setTextureRect(IntRect(0, 32, 32, 32));
                        if ((map2::TMap[i][j] == 't')) map.setTextureRect(IntRect(96, 128, 32, 32));

                        map.setPosition(j * 32, i * 32);

                        window.draw(map);
                    }
                }

        }

        //window.draw(easyEnemy.sprite);
        double tX, tY;
        tX = p.get_x();
        tY = p.get_y();
        if (tX < 620) tX = 320;
        if (tY < 240) tY = 240;
        if (tY > 554) tY = 554;
        if (tX > 1100) tX = 1282;
        view.setCenter(tX, tY);
        window.setView(view);
        window.draw(text);
        window.draw(text1);
        for (auto it: enemies)
      window.draw(it->get_sprite());

        window.draw(p.get_sprite());
        window.display();


    }


}




