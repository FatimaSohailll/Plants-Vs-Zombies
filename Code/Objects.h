#pragma once
#ifndef Objects_H
#define Objects_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;



// COORDINATES

class Coordinates {
	int x;
	int y;
public:
	Coordinates();
	Coordinates(int x, int y);
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
};

/////////////////////////////////////////////
//              OBJECTS                    //
/////////////////////////////////////////////


class Objects {
protected:
	Coordinates position; // composed object
	Texture texture;
	Sprite sprite;
	int damage;
	int health;
public:
	Objects();
	virtual void setPosition(int x, int y);
	virtual Coordinates getPosition();
	void setHealth(int h);
	int getHealth();
	void setDamage(int d);
	int getDamage();
	virtual void DrawPlant(RenderWindow& window);//change to drawobject and update other classes too
};


/////////////////////////////////////////////////////
//                Moving objects                   //
/////////////////////////////////////////////////////


class MovingObjects : public Objects {
	int speed;
public:
	int getSpeed();
	virtual void setSpeed(int sp);
	MovingObjects();
	virtual void updatePosition();

};
#endif // !Objects_H

