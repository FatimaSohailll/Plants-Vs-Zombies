#pragma once
#ifndef Zombies_H
#define Zombies_H
#include "Plants.h"
#include "Lawnmower.h"


////////////////////           ZOMBIES            ///////////////////
/////////////////////////////////////////////////////////////////////
//////////    Zombie height = approx. 170px 

class Zombie : public MovingObjects {
	int TotalZombies;
protected:
	Sprite zombieSprite;
	Texture zombieTexture;
	int originalSpeed;
	bool end;
public:
	void setOriginalSpeed(int s);
	int getOriginalSpeed();
	bool getEnd();
	void spawnInRow(Zombie& Z);
	virtual void drawZombie(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount);
	void MowerZombieCollision(LawnMower** mowers);
	void checkCollisionZom(Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount);
	void PlantCollisions(Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount,
		NonShooters*** nonshooters, int sunflowerCount, int wallnutCount, int cherrybombCount, int torchwoodCount);
};

class SimpleZombie : public Zombie {
private:
	Clock clock;
	IntRect walkingAnim;
	bool MoveLeft;
public:
	SimpleZombie();
	void drawZombie(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount);
	void updatePosition(LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount);
};
class FootballZombie : public Zombie {
private:
	Clock clock;
	IntRect FootballAnim;
	bool MoveLeft;

public:
	FootballZombie();
	void drawZombie(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount);
	void updatePosition(LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount);
};

class BackupDancer : public Zombie {
	Clock clock;
	IntRect backup;
	bool MoveLeft;
	bool movingDown;
public:
	BackupDancer();
	void drawZombie(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount);
	void updatePosition(LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount);
};

class DancingZombie : public Zombie {
private:
	Clock clock;
	IntRect dancingAnim;
	bool MoveLeft;
	bool movingDown;
	bool backupsSpawned;
	BackupDancer* dancersArr;
	int numBackup;
public:
	DancingZombie();
	BackupDancer* getDancersPtr();
	void drawZombie(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount);
	void updatePosition(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount);
	void spawnBackups(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount);
	void destroyBackups();
};

class FlyingZombie : public Zombie {
	Clock clock;
	IntRect flyingAnim;
	bool MoveLeft;
public:
	FlyingZombie();
	void drawZombie(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount);
	void updatePosition(LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount);
};

class ZombieFactory {
	const int maxTypes = 5;
	Zombie** Z;
public:
	Zombie** createWave(int level);
	int calculateNumZombies(int level);
	int calculateNumTypes(int level);
	Zombie* createRandomZombie(int typesInLevel);
	void destroyWave(Zombie** zombies, int totalInLevel);
};
#endif // !Zombies_H
