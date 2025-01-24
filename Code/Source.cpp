
#include "Game.h"

int main()
{
	char nextScreen = 'M';
	RenderWindow window(VideoMode(1920, 1080), "Plants Vs Zombies");
	//Game icon
	Image icon;
	icon.loadFromFile("icon.png");
	window.setIcon(32, 32, icon.getPixelsPtr());
	Screen* currscreen = new Menu;
	Game game(currscreen);
	while (nextScreen != 'E') {
		nextScreen = game.getCurrScreen()->run(window);
		if (nextScreen == 'G') {
			delete currscreen;
			currscreen = new Gameplay;
		}
		if (nextScreen == 'L') {
			delete currscreen;
			currscreen = new LevelGallery;
		}
		if (nextScreen == 'Z') {
			delete currscreen;
			currscreen = new Menu;
		}
		if (nextScreen == 'I') {
			delete currscreen;
			currscreen = new Instructions;
		}
		if (nextScreen == 'M') {
			delete currscreen;
			currscreen = new Menu;
		}
		if (nextScreen == '1') {
			delete currscreen;
			currscreen = new Gameplay(1);
		}
		if (nextScreen == '2') {
			delete currscreen;
			currscreen = new Gameplay(2);
		}
		if (nextScreen == '3') {
			delete currscreen;
			currscreen = new Gameplay(3);
		}
		if (nextScreen == '4') {
			delete currscreen;
			currscreen = new Gameplay(4);
		}
		game.setCurrScreen(currscreen);
		nextScreen = game.getCurrScreen()->run(window);
	}
	return 0;

}






