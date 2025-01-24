#include"Game.h"

Game::Game(Screen* screenFirst) {
	setCurrScreen(screenFirst);
}
void Game::setCurrScreen(Screen* screen) {
	currScreen = screen;
}
Screen* Game::getCurrScreen() {
	return currScreen;
}
Game::~Game() {
	delete currScreen;

}