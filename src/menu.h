

#ifndef IGRA_MENU_H
#define IGRA_MENU_H

#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
void menu(RenderWindow& window);
void start_menu_levels(RenderWindow& window1);
void run_level(RenderWindow& window, int i);
#endif