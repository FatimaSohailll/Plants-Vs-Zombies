#pragma once
#ifndef Screen_H
#define Screen_H
#include"Levels.h"

using namespace sf;
using namespace std;

class Screen {
public:
	virtual void createBack(RenderWindow& window) = 0;
	virtual char run(RenderWindow& window) = 0;
	virtual void showBackButton(RenderWindow& window) = 0;
	char touchButton(int mouseX, int mouseY);
	virtual Levels* getCurrLevel();
	virtual ~Screen();
};
class Menu : public Screen {
	Texture instructButton;
	Texture startButton;
	Sprite instructSprite;
	Sprite startSprite;
public:
	virtual void showBackButton(RenderWindow& window);
	virtual void createBack(RenderWindow& window);
	virtual char run(RenderWindow& window);
};
class Gameplay : public Screen {
	int levelNo;
	Texture Backbutton;
	Sprite SpriteBack;
	Levels* currlevel;
public:
	Gameplay(int levelnum = 1);
	Levels* getCurrLevel();
	virtual void showBackButton(RenderWindow& window);
	virtual void createBack(RenderWindow& window);
	char run(RenderWindow& window);
	~Gameplay();
};
class Instructions : public Screen {
	Texture Backbutton;
	Sprite SpriteBack;
public:
	Instructions();
	virtual void showBackButton(RenderWindow& window);
	virtual void createBack(RenderWindow& window);
	virtual char run(RenderWindow& window);
};
class GameOver : public Screen {
	Texture Backbutton;
	Sprite SpriteBack;
public:
	GameOver();
	virtual void showBackButton(RenderWindow& window);
	virtual void createBack(RenderWindow& window);
	virtual char run(RenderWindow& window);
};
class Pause : public Screen {
	Texture Backbutton;
	Sprite SpriteBack;
public:
	Pause();
	virtual void showBackButton(RenderWindow& window);
	virtual void createBack(RenderWindow& window);
};
class LevelGallery : public Screen {
	Texture Backbutton;
	Sprite SpriteBack;
public:

	LevelGallery();
	virtual char touchButton(int mouseX, int mouseY);
	virtual void showBackButton(RenderWindow& window);
	virtual void createBack(RenderWindow& window);
	virtual char run(RenderWindow& window);
};
#endif // !Screen_H

