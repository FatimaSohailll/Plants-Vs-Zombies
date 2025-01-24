#include"Lawnmower.h"

LawnMower::LawnMower() {
	MowerAnim = sf::IntRect(0, 0, 130, 100);
	position.setX(290);
	position.setY(320);
	hasRun = false;
}
LawnMower::LawnMower(int Y) {
	MowerAnim = sf::IntRect(0, 0, 130, 100);
	position.setX(290);
	position.setY(Y);
	hasRun = false;
}
void LawnMower::drawMower(RenderWindow& window) {//, Zombie **zombies, int total) {
	Texture LawnMowertexture;
	LawnMowertexture.loadFromFile("lawnmower.png");
	Sprite LawnMower(LawnMowertexture, MowerAnim);

	LawnMower.setPosition(position.getX(), position.getY());
	//			MowerZombieCollision(zombies, total);

	if (this->hasRun == true && clock.getElapsedTime().asSeconds() > 0.000001f) {
		if (MowerAnim.left >= 1950/*2080*/) {
			MowerAnim.left = 260;//130;
		}
		else MowerAnim.left += 260;//130;

		LawnMower.setTextureRect(MowerAnim);
		clock.restart();
	}

	window.draw(LawnMower);

}
void LawnMower::updatePosition(/*Zombie** zombies, int total*/) {
	//	MowerZombieCollision(zombies, total);
	if (this->hasRun == true) {
		this->position.setX(this->position.getX() + 20);
	}
}
LawnMower** MowerFactory::createLawnMowers() {
	int startY = 320;
	LawnMower** mowers = new LawnMower * [totalMowers];
	for (int i = 0; i < totalMowers; ++i) {
		mowers[i] = new LawnMower(startY);
		startY += 140; // Increase Y position for the next row
	}
	return mowers;
}
void MowerFactory::destroyLawnMowers(LawnMower** mowers) {
	for (int i = 0; i < 5; ++i) {
		delete mowers[i];
	}
	delete[] mowers;
}