
//#pragma once
#ifndef Plants_H
#define Plants_H

#include "Objects.h"


//Weapons
class Weapon : public MovingObjects {
	int originalPosition;
public:
	void setOriginalPosition(int p);
	int getOriginalPosition();
	void setPos(int x, int y);

	virtual void updatePosition();
	virtual void DrawPlant(RenderWindow& window);   //change to DrawObject
};

//Weapons subTypes
class Pea : public Weapon {
public:
	Pea();
	Pea(Coordinates* c);
	virtual void DrawPlant(RenderWindow& window);
	void setPos(int x, int y);
	virtual void updatePosition();
};
class SPea : public Weapon {
public:
	SPea();
	SPea(Coordinates* c);
	virtual void DrawPlant(RenderWindow& window);
	virtual void updatePosition();
};
class Fumes : public Weapon {
public:
	Fumes();
	Fumes(Coordinates* c);
	virtual void DrawPlant(RenderWindow& window);
	virtual void updatePosition();
};


// /////////////////           PLANTS            ////////////////////
///////////////////////////////////////////////////////////////////
////////////          Plant height = approx. 90 px (except puff-shroom)

class Plants : public Objects {
	int currency;
	Clock clk;
public:
	Plants();
	void setCurrency(int c);
	int getCurrency();
	virtual void DrawPlant(RenderWindow& window);
	virtual Clock& getClock();

};
class Sun : public Objects {
	float time;
	Clock clock;
public:
	Sun();
	Sun(Coordinates* c);
	~Sun();
	virtual void DrawPlant(RenderWindow& window);
	void generateRandomSuns();
	void DrawRndomSun(RenderWindow& window);
};

class NonShooters : public Plants {
	Sun sun;
public:
	NonShooters();
	~NonShooters();
	virtual void DrawPlant(RenderWindow& window);
	virtual Sun& getSun();
};
class Shooters : public Plants {
private:
	Weapon* weapon;
public:
	virtual Weapon* getWeapon();
	void setWeapon(Weapon* weapon1);
	virtual void setPosition(int x, int y);
	Shooters();
	~Shooters();
	virtual void DrawPlant(RenderWindow& window);
};

//NonShooter Plants Sub-types 
class Sunflower : public NonShooters {
	float time; // changed int to float
	Clock clock;   //new
	Sun sunPlant;
public:
	Sunflower(Coordinates* c);
	virtual Sun& getSun();
	virtual void setPosition(int x, int y);
	Sunflower();
	virtual Clock& getClock();
	void generateSun(RenderWindow& window);
	virtual void DrawPlant(RenderWindow& window);
	~Sunflower();

};
class Torchwood : public NonShooters {
public:
	Torchwood();
	~Torchwood();
	Torchwood(Coordinates* c);
	virtual void DrawPlant(RenderWindow& window);
};
class CherryBomb : public NonShooters {
	int radius;
	Clock clock;
	IntRect cherryAnim;
	Sprite cherrySprite;
	Texture cherrybomb;

public:
	CherryBomb();
	CherryBomb(Coordinates* c);
	virtual void DrawPlant(RenderWindow& window);
};
class WallNut : public NonShooters {
	Clock clock;
	IntRect wallnutAnim;
	Sprite wallnutSprite;
	Texture wallnut;
	int speed;
	bool MoveLeft;
public:
	WallNut();
	WallNut(Coordinates* c);
	int getSpeed();
	virtual void DrawPlant(RenderWindow& window);
	void updatePosition();

};

//Shooter plants SubTypes

class PuffShroom : public Shooters {
public:
	PuffShroom();
	PuffShroom(Coordinates* c);
	virtual void DrawPlant(RenderWindow& window);
};
class Repeater : public Shooters {
public:
	Repeater();
	Repeater(Coordinates* c);
	void setPosition(int x, int y);
	virtual void DrawPlant(RenderWindow& window);
};
class SnowPea : public Shooters {
public:
	SnowPea();
	SnowPea(Coordinates* c);
	virtual void DrawPlant(RenderWindow& window);

};
class PeaShooter : public Shooters {
public:
	PeaShooter();
	PeaShooter(Coordinates* c);
	virtual void DrawPlant(RenderWindow& window);
};
class FumeShroom : public Shooters {
public:
	FumeShroom();
	FumeShroom(Coordinates* c);
	virtual void DrawPlant(RenderWindow& window);

};

class PlantFactory {
	virtual bool placePlant(int mouseX, int mouseY, bool notPlanted, char plantType, int* currency) = 0;
	virtual void drawPlant(RenderWindow& window) = 0;
};
class NonshooterPlantFactory : public PlantFactory {
	NonShooters*** plant;
	int levelNo;
	int maxPlantNum;
	int sunflowerCount = 0, wallnutCount = 0, cherryBombCount = 0, torchwoodCount = 0;
public:
	// sunflower index=0, wallnut=1, cherry=2, torcwood=3
	NonshooterPlantFactory(int l);
	virtual bool placePlant(int mouseX, int mouseY, bool notPlanted, char plantType, int* currency);
	int getMaxPlantNum();
	int getCountSunflowers();
	int getCountWallnuts();
	int getCountCherryBomb();
	int getCountTorchwood();
	int getTotalCount();
	NonShooters*** getNonShooterPlantArray();
	virtual void drawPlant(RenderWindow& window);
};
class ShooterPlantFactory : public PlantFactory {
	Shooters** plant;
	int levelNo;
	int maxPlantNum;
	int peashooterCount = 0, repeaterCount = 0, snowpeaCount = 0;
public:
	// peashooter index=0, repeater=1, snowpea=2
	ShooterPlantFactory(int l);
	virtual bool placePlant(int mouseX, int mouseY, bool notPlanted, char plantType, int* currency);
	virtual void drawPlant(RenderWindow& window);
	int getMaxPlantNum();
	int getCountPeaShooters();
	int getCountRepeaters();
	int getCountSnowpea();
	int getTotalCount();
	Shooters** getShooterPlantArray();
};
#endif // !Plants_H
