#pragma once
#ifndef inventory_H
#define inventory_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include"Plants.h"
using namespace sf;
using namespace std;

//other card size= 176 x 112
//repeater and cherry card=180x112
// snowpea=187x112
//torchwood=185 x112
class inventory {
	int levelNo;
	Sprite select;
	Texture selectText;
public:
	inventory();
	inventory(int level);

	void displayLevel1(RenderWindow& window);
	void displayLevel2(RenderWindow& window);
	void displayLevel3(RenderWindow& window);
	void displayLevel4(RenderWindow& window);
	void displayCards(RenderWindow& window);
	void drawSelect(RenderWindow& window);
	char isClicked(int x, int y, RenderWindow& window);
};
#endif // !inventory_H


