//
// Created by Эрик on 06.05.2021.
//


#ifndef IGRA_PERSONAGES_H
#define IGRA_PERSONAGES_H
#include<string>

#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
class Personages {
protected:

    float dx, dy, x, y, speed,moveTimer;
    int w,h,health;
    bool life, isMove, onGround;
    Texture texture;
    Sprite sprite;
    String name;
public:
    Personages(Image &image, float X, float Y,int W,int H,String Name){
        x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0;
        speed = 0; health = 100; dx = 0; dy = 0;
        life = true; onGround = false; isMove = false;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(w / 2, h / 2);
    };
    virtual FloatRect getRect()=0;
    virtual void update(float time,int i)=0;
    const virtual int get_life() =0;
    virtual void change_life(int delta)=0;
    const virtual Sprite get_sprite()=0;
    const virtual float get_x()=0;
    const virtual float get_y()=0;
};
#endif //IGRA_PERSONAGES_H
