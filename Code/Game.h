#pragma once
#ifndef Game_H
#define Game_H

#include "Screen.h"
class Game {
	Screen* currScreen;
public:
	Game(Screen* screenFirst);
	void setCurrScreen(Screen* screen);
	Screen* getCurrScreen();
	~Game();
};
#endif // !Game_H
