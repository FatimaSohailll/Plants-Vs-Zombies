#include"Objects.h"

////////////Coordinates//////////
Coordinates::Coordinates(int x, int y) {
	this->x = x;
	this->y = y;
}
Coordinates::Coordinates() {}
void Coordinates::setX(int x) {
	this->x = x;
}
int Coordinates::getX() {
	return x;
}
void Coordinates::setY(int y) {
	this->y = y;
}
int Coordinates::getY() {
	return y;
}

///////////objects//////////
void Objects::setPosition(int x, int y) {
	position.setY(y);
	position.setX(x);
}
Coordinates Objects::getPosition() {
	return position;
}
Objects::Objects() {}
void Objects::setHealth(int h) {
	health = h;
}
int Objects::getHealth() {
	return health;
}
void Objects::setDamage(int d) {
	damage = d;
}
int Objects::getDamage() {
	return damage;
}
void Objects::DrawPlant(RenderWindow& window) {}

/////////Moving object///////////////
int MovingObjects::getSpeed() {
	return speed;
}
void MovingObjects::setSpeed(int sp) {
	speed = sp;
}
MovingObjects::MovingObjects() {
	speed = 0;
}
void MovingObjects::updatePosition() {}
