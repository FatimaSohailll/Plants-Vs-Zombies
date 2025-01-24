#pragma once
#ifndef LawnMower_H
#define LawnMower_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Objects.h"
using namespace sf;
using namespace std;


////////////////         LAWN MOWER          ////////////////////
/////////////////////////////////////////////////////////////////
///////////////// height = 100px, width = 130px;




class LawnMower : public MovingObjects {
private:
	Clock clock;
	IntRect MowerAnim;

public:
	bool hasRun;
	LawnMower();
	LawnMower(int Y);

	void drawMower(RenderWindow& window);
	void updatePosition();
};


class MowerFactory {
	const int totalMowers = 5;
public:
	LawnMower** createLawnMowers();

	void destroyLawnMowers(LawnMower** mowers);
};
#endif // !LawnMower_H
