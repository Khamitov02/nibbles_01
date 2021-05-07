//
// Created by Эрик on 07.05.2021.
//

#ifndef NIBBLES_01_ENEMY_H
#define NIBBLES_01_ENEMY_H
#include <iostream>
#include <cstdlib>
#include "Personages.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game_map1.h"
#include "game_map2.h"
#include <sstream>

class Enemy :public Personages{
public:

    Enemy(Image &image, float X, float Y,int W,int H,String Name):Personages(image,X,Y,W,H,Name){
        if (name == "enemy"){
            sprite.setTextureRect(IntRect(0, 0, w, h));
            sprite.setScale(0.4,0.4);
            dx = 0.1;
        }
    }
    FloatRect getRect() final{
        return FloatRect(x, y, w, h);
    }
    void set_dx(){
        dx=0;
    }
    void checkCollisionWithMap(float Dx, float Dy,int I)//ф ция проверки столкновений с картой
    {
        for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты
            for (int j = x / 32; j<(x + w) / 32; j++)
            {if (I==1) {
                    if (map1::TMap[i][j] == '0' || map1::TMap[i][j] == 'k')
                    {
                        if (Dy > 0) {
                            y = i * 32 - h;
                        }
                        if (Dy < 0) { y = i * 32 + 32; }//столкновение с верхними краями карты
                        if (Dx > 0) {
                            x = j * 32 - w;
                            dx = -0.1;
                            sprite.scale(-1, 1);
                        }//с правым краем карты
                        if (Dx < 0) {
                            x = j * 32 + 32;
                            dx = 0.1;
                            sprite.scale(-1, 1);

                        }// с левым краем карты
                    }
                }
                else if (I==2){
                    if (map2::TMap[i][j] == '0' || map2::TMap[i][j] == 'k')
                    {
                        if (Dy > 0) {
                            y = i * 32 - h;
                        }
                        if (Dy < 0) { y = i * 32 + 32; }
                        if (Dx > 0) {
                            x = j * 32 - w;
                            dx = -0.1;
                            sprite.scale(-1, 1);
                        }//с правым краем карты
                        if (Dx < 0) {
                            x = j * 32 + 32;
                            dx = 0.1;
                            sprite.scale(-1, 1);
                        }// с левым краем карты
                    }

                }
            }
    }

    void update(float time, int i) final
    {   double Dy = 1;
        if (name == "enemy"){


            x += dx*time;
            checkCollisionWithMap(dx, 0,i);
            y += (0.5)*time;
          checkCollisionWithMap(0, Dy,i);
            sprite.setPosition(x + w / 2, y + h / 2); //задаем позицию спрайта в место его центра
            if (health <= 0){ life = false; }
        }
    }
    const int get_life() {
        return this->health;
    };
     void change_life(int delta) final{
        health+=delta;
    };
    const  Sprite get_sprite() final{
      return this->sprite;
    };
    const  float get_x() final{
        return this->x;
    };
    const  float get_y() final{
        return this->y;
    };
};
#endif //NIBBLES_01_ENEMY_H
