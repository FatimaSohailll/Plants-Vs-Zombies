#pragma once
#ifndef Levels_H
#define Levels_H
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Objects.h"
#include "Zombies.h"
#include "Plants.h"
#include "Lawnmower.h"
#include "Inventory.h"
class Levels {
protected:
	Texture countSun;
	Sprite countSunSp;
	int levelNo;
	int currency;
	int lives;
	bool gameover;
public:
	Levels();
	int getLevelNo();
	virtual int getCurrency();
	virtual void setCurrency(int c);
	int getLives();
	void setLives(int l);
	void checkSunClick(NonShooters*** plants, int sunflowerCount, int mouseX, int mouseY);
	char run(RenderWindow& window);
	void checkSunRandClick(Sun* sunPtr, int mouseX, int mouseY);
	virtual void setBackground(RenderWindow& window) = 0;
	virtual ~Levels();
};
class Level1 : public Levels {
public:
	Level1();
	virtual void setBackground(RenderWindow& window);
	virtual ~Level1();

};
class Level2 : public Levels {
public:
	Level2();
	virtual void setBackground(RenderWindow& window);

};
class Level3 : public Levels {
public:
	Level3();
	virtual void setBackground(RenderWindow& window);

};
class Level4 : public Levels {
public:
	Level4();
	virtual void setBackground(RenderWindow& window);

};
#endif // !Levels_H

