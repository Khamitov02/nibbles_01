//
// Created by Эрик on 06.05.2021.
//

#ifndef IGRA_CLASS_H
#define IGRA_CLASS_H
#include <iostream>
#include <cstdlib>
#include "Personages.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game_map1.h"
#include "game_map2.h"
#include <sstream>

/*
class Igrok {


public:

    float x, y;
    float  w, h, dx, dy, speed;
    int dir, score, bubble, health,ss;
    bool life;
    String File;
    Image image;
    Texture texture;
    Sprite sprite;
    Igrok(String F, float X, float Y, float W, float H) {
        dx = 0; dy = 0; speed = 0; dir = 0; score = 0; health = 5; bubble = 0; ss = 0;
        bool life;
        File = F;
        w = W; h = H;
        image.loadFromFile("images/" + File);
        image.createMaskFromColor(Color(41, 33, 59));
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        x = X; y = Y;
        sprite.setTextureRect(IntRect(0, 0, w, h));
    }

    void update(float time)
    {
        if (health <= 0) { life = false; speed = 0; }
        switch (dir)
        {
            case 0: dx = speed; dy = 0; break;
            case 1: dx = -speed; dy = 0; break;
            case 2: dx = 0; dy = speed; break;
            case 3: dx = 0; dy = -speed; break;
        }

        x += dx * time;
        y += dy * time;
        interactionWithMap();
        if (bubble != 1)
            speed = 0;

        sprite.setPosition(x, y);

        if (health <= 0) { life = false; speed = 0; }
    }

    void interactionWithMap()
    {

        for (int i = y / 32; i < (y + h) / 32; i++)
            for (int j = x / 32; j < (x + w) / 32; j++)
            {
                if (TMap[i][j] == '0' || TMap[i][j] == 'k')
                {
                    if (dy > 0)
                    {
                        y = i * 32 - h;
                    }
                    if (dy < 0)
                    {
                        y = i * 32 + 32;
                    }
                    if (dx > 0)
                    {
                        x = j * 32 - w;
                    }
                    if (dx < 0)
                    {
                        x = j * 32 + 32;
                    }
                }

                if (TMap[i][j] == 's')
                {
                    score++;
                    ss++;
                    health = health + 1 - 1;
                    TMap[i][j] = ' ';
                }
                if (TMap[i][j] == 'l')
                {
                    health -= 1;
                    TMap[i][j] = ' ';
                }
                if (TMap[i][j] == 'r')
                {
                    health += score;
                    score = 0;


                }
                bubble = 0;
                if (TMap[i][j] == 'f')
                {
                    bubble = 1;


                }

            }
    }
};
*/


class Player :public Personages {


    private:
        enum { left, right, up, jump, stay } state;//добавляем тип перечисления - состояние объекта
        int score;//эта переменная может быть только у игрока
        bool proverka;//проверка на окончание уровня при наступлении на алтарь
        double CurrentFrame;
    public:
        Player(Image &image, float X, float Y,int W,int H,String Name):Personages(image,X,Y,W,H,Name){
             state = stay;this->score = 0;CurrentFrame=0;proverka=false;
            if (name == "Player1"){
                sprite.setTextureRect(IntRect(0, 0, w, h));
            }
        }


    FloatRect getRect() final{
        return FloatRect(x, y, w, h);
    }
        bool Proverka(){
            return proverka;
        }
        int get_score(){
             return score;
        }
        void change_life(int delta) final{
            health += delta;
        }
        bool get_onGround(){
            return onGround;
        }
        double get_dy(){
            return dy;
        }
        double get_dx(){
        return dx;
            }
            void change_dy(double delta){
            dy+=delta;
        }
        void control(){
            if (Keyboard::isKeyPressed){//если нажата клавиша
                if (Keyboard::isKeyPressed(Keyboard::Left)) {//а именно левая
                    state = left; speed = 0.2;

                }
                if (Keyboard::isKeyPressed(Keyboard::Right)) {
                    state = right; speed = 0.2;

                }

                if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround)) {//если нажата клавиша вверх и мы на земле, то можем прыгать
                    state = jump; dy = -0.7; onGround = false;//увеличил высоту прыжка

                }



            }





        }
    void checkCollisionWithMap(float Dx, float Dy,int I)//ф ция проверки столкновений с картой
    {
        for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты
            for (int j = x / 32; j<(x + w) / 32; j++)
            {if (I==1) {


                    if (map1::TMap[i][j] == '0' || map1::TMap[i][j] == 't' || map1::TMap[i][j] == 'k')//если элемент наш тайлик земли? то
                    {
                        if (Dy > 0) {
                            this->y = i * 32 - this->h;
                            this->dy = 0;
                            this->onGround = true;
                        }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
                        if (Dy < 0) {
                            this->y = i * 32 + 32;
                            this->dy = 0;
                        }//столкновение с верхними краями карты(может и не пригодиться)
                        if (Dx > 0) { this->x = j * 32 - this->w; }//с правым краем карты
                        if (Dx < 0) { this->x = j * 32 + 32; }// с левым краем карты
                    }
                    if (map1::TMap[i][j] == 'y') {
                        score++;

                        change_life(+1);
                        map1::TMap[i][j] = ' ';
                    }
                    if (map1::TMap[i][j] == 'r') {


                        proverka = true;
                    }
                    if (map1::TMap[i][j] == ' '){
                        onGround=false;
                    }
                }
                else if (I==2){

                        if (map2::TMap[i][j] == '0'||map2::TMap[i][j] == 't'|| map2::TMap[i][j] == 'k' )//если элемент наш тайлик земли? то
                        {
                            if (Dy>0){ this->y = i * 32 - this->h;  this->dy = 0; this->onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
                            if (Dy<0){ this->y = i * 32 + 32;  this->dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
                            if (Dx>0){ this->x = j * 32 - this->w; }//с правым краем карты
                            if (Dx<0){ this->x = j * 32 + 32; }// с левым краем карты
                        }
                        if (map2::TMap[i][j] == 'y')
                        {
                            score++;

                            change_life(+1);
                            map2::TMap[i][j] = ' ';
                        }
                        if (map2::TMap[i][j] == 'r')
                        {



                            proverka=true;
                        }
                    if (map2::TMap[i][j] == ' '){
                        onGround=false;
                    }
            }


                //else { onGround = false; }//надо убрать т.к мы можем находиться и на другой поверхности или платформе которую разрушит враг
            }
    }
    void set_proverka(){
            proverka=false;
        }

        void update(float time,int i)
        {
            control();//функция управления персонажем
            switch (state)//тут делаются различные действия в зависимости от состояния
            {
                case right:dx = speed;
                    CurrentFrame += 0.009 * time;
                    if (CurrentFrame > 4) CurrentFrame = 0;
                    this->sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 96, 32, 48));
                break;
                //состояние идти вправо
                case left:
                    dx = -speed;
                    CurrentFrame += 0.009 * time;
                    if (CurrentFrame > 4) CurrentFrame = 0;
                    this->sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 48, 32, 48));
                break;//состояние идти влево
                case up:
                    dy = -speed;
                    CurrentFrame += 0.009 * time;
                    if (CurrentFrame > 4) CurrentFrame = 0;
                    this->sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 144, 32, 48));
                    //будет состояние поднятия наверх (например по лестнице)

                break;//будет состояние во время спуска персонажа (например по лестнице)
                case stay:
                    this->sprite.setTextureRect(IntRect(32 * int(0), 0, 32, 48));
                    break;//и здесь тоже
            }
            x += dx*time;
            checkCollisionWithMap(dx, 0,i);//обрабатываем столкновение по Х
            y += dy*time;
            checkCollisionWithMap(0, dy,i);

            //checkCollisionWithMap();//обрабатываем столкновение по Y
            sprite.setPosition(x+w/2 , y +h/2); //задаем позицию спрайта в место его центра
            if (health <= 0){ life = false; }
            if (!isMove){ speed = 0; }
            //if (!onGround) { dy = dy + 0.0015*time; }//убираем и будем всегда притягивать к земле
            //if (life) { setPlayerCoordinateForView(x, y); }
            dy = dy + 0.0015*time;//постоянно притягиваемся к земле
        }
        const int get_life() final{
            return this->health;

        }
    const  Sprite get_sprite() final{

            return this->sprite;
        };
    const float get_x() final{
        return this->x;
    };
    const  float get_y() final{
        return this->y;
    };
    };
#endif
