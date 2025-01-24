#include "Plants.h"
////////////WEAPONS////////

void Weapon::setOriginalPosition(int p) {
	originalPosition = p;
}
int Weapon::getOriginalPosition() {
	return originalPosition;
}
void Weapon::setPos(int x, int y) {
	position.setX(x);
	position.setY(y);
}
void Weapon::updatePosition() {}
void Weapon::DrawPlant(RenderWindow& window) {}

////////Pea////////

Pea::Pea() {
	setSpeed(5);
}
Pea::Pea(Coordinates* c) {
	setPosition(c->getX(), c->getY());
	setSpeed(5);
}
void Pea::DrawPlant(RenderWindow& window) {
	updatePosition();
	Texture peaTexture;
	Sprite peaSprite;
	peaTexture.loadFromFile("pea.png");
	peaSprite.setTexture(peaTexture);
	peaSprite.setPosition(this->position.getX(), this->position.getY());
	window.draw(peaSprite);
}
void Pea::setPos(int x, int y) {
	setPosition(x, y);
}
void Pea::updatePosition() {
	if (position.getX() < 1500) {
		int x = getPosition().getX();
		this->position.setX(x + getSpeed());
	}
	else {
		this->position.setX(getOriginalPosition());
	}
}

////////////SPea/////////

SPea::SPea() {
	setSpeed(5);
}
SPea::SPea(Coordinates* c) {
	setPosition(c->getX(), c->getY());
	setSpeed(5);
}
void SPea::DrawPlant(RenderWindow& window) {
	updatePosition();
	Texture speaTexture;
	Sprite speaSprite;
	speaTexture.loadFromFile("Textures\\icepea.png");
	speaSprite.setTexture(speaTexture);
	speaSprite.setPosition(this->position.getX(), this->position.getY());
	window.draw(speaSprite);
}
void SPea::updatePosition() {
	if (position.getX() < 1500) {
		int x = getPosition().getX();
		this->position.setX(x + getSpeed());
	}
	else {
		this->position.setX(getOriginalPosition());
	}
}

//////////Fumes///////

Fumes::Fumes() {
	setSpeed(5);
}
Fumes::Fumes(Coordinates* c) {
	setPosition(c->getX(), c->getY());
	setSpeed(5);
}
void Fumes::DrawPlant(RenderWindow& window) {
	updatePosition();
	Texture fumeTexture;
	Sprite fumeSprite;
	fumeTexture.loadFromFile("Textures\\fumes.png");
	fumeSprite.setTexture(fumeTexture);
	fumeSprite.setPosition(this->position.getX(), this->position.getY());
	window.draw(fumeSprite);
}
void Fumes::updatePosition() {
	if (position.getX() < 1500) {
		int x = getPosition().getX();
		this->position.setX(x + getSpeed());
	}
	else {
		this->position.setX(getOriginalPosition());
	}
}

/////////Plants/////

Plants::Plants() {}
void Plants::setCurrency(int c) {
	currency = c;
}
int Plants::getCurrency() {
	return currency;
}
void Plants::DrawPlant(RenderWindow& window) {}
Clock& Plants::getClock() {
	return clk;
}

//Sun////

Sun::Sun() {
	texture.loadFromFile("Textures\\sun.png");
	sprite.setTexture(texture);
}
Sun::Sun(Coordinates* c) {
	texture.loadFromFile("Textures\\sun.png");
	sprite.setTexture(texture);
	sprite.setPosition(c->getX(), c->getY());
}
Sun::~Sun() {}
void Sun::DrawPlant(RenderWindow& window) {
	sprite.setPosition(position.getX(), position.getY());
	window.draw(sprite);

}
void Sun::generateRandomSuns() {
	//range =1460-528=932+1
	int x = rand() % 933 + 528;
	this->setPosition(x, 0);
}
void Sun::DrawRndomSun(RenderWindow& window) {
	if (this->getPosition().getY() < 960) {
		this->setPosition(position.getX(), position.getY() + 5);
		this->DrawPlant(window);
	}
	else {
		if (clock.getElapsedTime().asSeconds() > rand() % 20 + 30) {
			generateRandomSuns();
			clock.restart();
		}
	}
}

//////////nonshooters///////

NonShooters::NonShooters() {}
NonShooters::~NonShooters() {}
void NonShooters::DrawPlant(RenderWindow& window) {}
Sun& NonShooters::getSun() {
	return sun;
}

/////////////shooters////////

Weapon* Shooters::getWeapon() {
	return weapon;
}  //new function
void Shooters::setWeapon(Weapon* weapon1) {
	weapon = weapon1;
}
void Shooters::setPosition(int x, int y) {
	position.setY(y);
	position.setX(x);
	getWeapon()->setOriginalPosition(x);
	getWeapon()->setPos(x, y);
}
Shooters::Shooters() {}
Shooters::~Shooters() {}
void Shooters::DrawPlant(RenderWindow& window) {}

//////////////sunflower////////////

Sunflower::Sunflower(Coordinates* c) : sunPlant(c) {
	setPosition(c->getX(), c->getY());
	texture.loadFromFile("Textures\\sunflower.png");
	sprite.setTexture(texture);
	sprite.setPosition(position.getX(), position.getY());
}
Sun& Sunflower::getSun() {
	return sunPlant;
}
void Sunflower::setPosition(int x, int y) {
	position.setY(y);
	position.setX(x);
	sprite.setPosition(x, y);
}
Sunflower::Sunflower() {
	texture.loadFromFile("Textures\\sunflower.png");
	sprite.setTexture(texture);
}
Clock& Sunflower::getClock() {
	return clock;
}
void Sunflower::generateSun(RenderWindow& window) {
	time = clock.getElapsedTime().asSeconds();
	if (time >= 10 && time < 20) {
		sunPlant.setPosition(position.getX() + 30, position.getY());
		sunPlant.DrawPlant(window);
	}
	else {
		sunPlant.setPosition(-100, -100);
		sunPlant.DrawPlant(window);
		clock.restart();
	}
}
void Sunflower::DrawPlant(RenderWindow& window) {
	window.draw(sprite);
	sunPlant.DrawPlant(window);
	time = clock.getElapsedTime().asSeconds();
	if (time < 10) {
		return;
	}
	else {
		generateSun(window);
	}
}
Sunflower::~Sunflower() {}

///////////Torchwood///////

Torchwood::Torchwood() {}
Torchwood::~Torchwood() {}
Torchwood::Torchwood(Coordinates* c) {
	setPosition(c->getX(), c->getY());
}
void Torchwood::DrawPlant(RenderWindow& window) {
	Texture Torchwood;
	Sprite TorchSprite;
	Torchwood.loadFromFile("Textures\\torchwood.png");   //change to torchwood png
	TorchSprite.setTexture(Torchwood);
	TorchSprite.setPosition(position.getX(), position.getY());
	window.draw(TorchSprite);

}

//////////cherrybomb//////

CherryBomb::CherryBomb() {
	setHealth(50);
	cherryAnim = sf::IntRect(0, 0, 207, 200);
	cherrybomb.loadFromFile("cherryBombAnim.png");
	cherrySprite.setTexture(cherrybomb);
	cherrySprite.setTextureRect(cherryAnim);
}
CherryBomb::CherryBomb(Coordinates* c) {
	setPosition(c->getX(), c->getY());
	setHealth(50);
	cherryAnim = sf::IntRect(0, 0, 207, 200);
	cherrybomb.loadFromFile("cherryBombAnim.png");
	cherrySprite.setTexture(cherrybomb);
	cherrySprite.setTextureRect(cherryAnim);
	cherrySprite.setPosition(c->getX(), c->getY());

}
void CherryBomb::DrawPlant(RenderWindow& window) {

	if (clock.getElapsedTime().asMicroseconds() > 0.001f) {
		if (cherryAnim.left >= 6200) {
			cherrySprite.setPosition(-1500, -1500);
		}
		else
			cherryAnim.left += 207;
		cherrySprite.setTextureRect(cherryAnim);
		clock.restart();
	}
	window.draw(cherrySprite);
}

////wallnut//////

WallNut::WallNut() {}
WallNut::WallNut(Coordinates* c) {
	this->setPosition(c->getX(), c->getY());
	cout << position.getX() << "  " << position.getY();
	setHealth(50);
	wallnutAnim = sf::IntRect(95, 0, 95, 115);
	wallnut.loadFromFile("Textures\\wallnutAnim.png");
	wallnutSprite.setTexture(wallnut);
	wallnutSprite.setTextureRect(wallnutAnim);
	this->speed = 5;
	// wallnutSprite.setPosition(position.getX() + this->speed, position.getY());

}
int WallNut::getSpeed() {
	return speed;
}
void WallNut::DrawPlant(RenderWindow& window) {
	// setPosition(c->getX(), c->getY());
	wallnutSprite.setPosition(position.getX(), position.getY());


	if (clock.getElapsedTime().asMicroseconds() > 0.01f) {
		if (wallnutAnim.left >= 760) {
			wallnutAnim.left = 0;
		}
		else wallnutAnim.left += 95;

		wallnutSprite.setTextureRect(wallnutAnim);
		clock.restart();
	}
	this->updatePosition();
	cout << "x : " << position.getX() << endl;
	cout << "Y : " << position.getY() << endl;

	window.draw(wallnutSprite);
}
void WallNut::updatePosition() {
	if (this->position.getX() <= 1600) {
		this->position.setX(this->position.getX() + getSpeed());

	}
}

///Puffshroom//////

PuffShroom::PuffShroom() {}
PuffShroom::PuffShroom(Coordinates* c) {
	setPosition(c->getX(), c->getY());
	setWeapon(new Fumes(c));
	getWeapon()->setOriginalPosition(c->getX());
}
void PuffShroom::DrawPlant(RenderWindow& window) {
	getWeapon()->DrawPlant(window);
	Texture puffShroomText;
	Sprite puffShroomSprite;
	puffShroomText.loadFromFile("puffshroom.png");
	puffShroomSprite.setTexture(puffShroomText);
	puffShroomSprite.setPosition(position.getX(), position.getY());
	window.draw(puffShroomSprite);

}

/////repeater/////////

Repeater::Repeater() {
	setWeapon(new Pea[2]);
}
Repeater::Repeater(Coordinates* c) {
	setPosition(c->getX(), c->getY());
	setWeapon(new Pea[2]);
	getWeapon()->setPosition(c->getX(), c->getY());
	(getWeapon() + 1)->setPosition(c->getX() + 100, c->getY());
	getWeapon()->setOriginalPosition(c->getX());

}
void Repeater::setPosition(int x, int y) {
	position.setY(y);
	position.setX(x);
	(getWeapon() + 1)->setOriginalPosition(x);
	getWeapon()->setOriginalPosition(x);
	getWeapon()->setPos(x, y);
	(getWeapon() + 1)->setPos(x + 100, y);
}
void Repeater::DrawPlant(RenderWindow& window) {
	getWeapon()->DrawPlant(window);
	(getWeapon() + 1)->DrawPlant(window);
	Texture repeaterText;
	Sprite repeaterSprite;
	repeaterText.loadFromFile("Textures\\repeater.png");
	repeaterSprite.setTexture(repeaterText);
	repeaterSprite.setPosition(position.getX(), position.getY());
	window.draw(repeaterSprite);

}

///////////snowpea//////////

SnowPea::SnowPea() {
	setWeapon(new SPea);
}
SnowPea::SnowPea(Coordinates* c) {
	setWeapon(new SPea(c));
	setPosition(c->getX(), c->getY());
	getWeapon()->setOriginalPosition(c->getX());
}
void SnowPea::DrawPlant(RenderWindow& window) {
	getWeapon()->DrawPlant(window);
	Texture snowpeaText;
	Sprite snowpeaSprite;
	snowpeaText.loadFromFile("Textures\\snowpea.png");
	snowpeaSprite.setTexture(snowpeaText);
	snowpeaSprite.setPosition(position.getX(), position.getY());
	window.draw(snowpeaSprite);

}

/////////////peashooter/////////

PeaShooter::PeaShooter() {
	setWeapon(new Pea);
}
PeaShooter::PeaShooter(Coordinates* c) {
	setWeapon(new Pea(c));
	setPosition(c->getX(), c->getY());
	getWeapon()->setOriginalPosition(c->getX());
}
void PeaShooter::DrawPlant(RenderWindow& window) {
	getWeapon()->DrawPlant(window);
	Texture peashooterText;
	Sprite peashooterSprite;
	peashooterText.loadFromFile("Textures\\peashooter.png");
	peashooterSprite.setTexture(peashooterText);
	peashooterSprite.setPosition(position.getX(), position.getY());
	window.draw(peashooterSprite);
}

///////Fumeshroom///////

FumeShroom::FumeShroom() {
}
FumeShroom::FumeShroom(Coordinates* c) {
	setPosition(c->getX(), c->getY());
	setPosition(c->getX(), c->getY());
	setWeapon(new Fumes(c));
	getWeapon()->setOriginalPosition(c->getX());
}
void FumeShroom::DrawPlant(RenderWindow& window) {
	getWeapon()->DrawPlant(window);
	Texture fumeshroomText;
	Sprite fumeshroomSprite;
	fumeshroomText.loadFromFile("fumeshroom.png");
	fumeshroomSprite.setTexture(fumeshroomText);
	fumeshroomSprite.setPosition(position.getX(), position.getY());
	window.draw(fumeshroomSprite);

}

///////NonshooterPlantFactory////

NonshooterPlantFactory::NonshooterPlantFactory(int l) {
	levelNo = l;
	if (l == 1) {
		maxPlantNum = 1;
	}
	else if (l == 2) {
		maxPlantNum = 3;
	}
	else if (l == 3) {
		maxPlantNum = 3;
	}
	else if (l == 4) {
		maxPlantNum = 4;
	}
	plant = new NonShooters * *[maxPlantNum];
	for (int i = 0; i < maxPlantNum; i++) {
		if (i == 0)
			plant[i] = new NonShooters * [15];
		else if (i == 1)
			plant[i] = new NonShooters * [15];
		else if (i == 2)
			plant[i] = new NonShooters * [15];
		else if (i == 3)
			plant[i] = new NonShooters * [15];
	}
}
bool NonshooterPlantFactory::placePlant(int mouseX, int mouseY, bool notPlanted, char plantType, int* currency) {
	int x = 0, y = 0;
	if (notPlanted == true) {
		if (mouseX >= 390 && mouseX <= 1560 && mouseY > 112) {
			if (mouseX >= 390 && mouseX <= 520) {
				x = 420;
			}
			if (mouseX >= 520 && mouseX <= 650) {
				x = 550;
			}
			if (mouseX >= 650 && mouseX <= 780) {
				x = 680;
			}
			if (mouseX >= 780 && mouseX <= 910) {
				x = 810;
			}
			if (mouseX >= 910 && mouseX <= 1040) {
				x = 940;
			}
			if (mouseX >= 1040 && mouseX <= 1170) {
				x = 1070;
			}
			if (mouseX >= 1170 && mouseX <= 1300) {
				x = 1200;
			}
			if (mouseX >= 1300 && mouseX <= 1430) {
				x = 1330;
			}
			if (mouseX >= 1430 && mouseX <= 1560) {
				x = 1460;
			}
			if (mouseY >= 280 && mouseY <= 420) {
				y = 330;
			}
			else if (mouseY >= 420 && mouseY <= 560) {
				y = 470;
			}
			else if (mouseY >= 560 && mouseY <= 700) {
				y = 610;
			}
			else if (mouseY >= 700 && mouseY <= 820) {
				y = 750;
			}
			else if (mouseY >= 820 && mouseY <= 960) {
				y = 870;
			}
			if (plantType == 'S' && *currency >= 100) {
				Coordinates coord(x, y);
				plant[0][sunflowerCount++] = new Sunflower(&coord);
				plant[0][sunflowerCount - 1]->getClock().restart();
				*currency -= 100;
				return false;
			}

			else if (plantType == 'W' && *currency >= 50) {
				Coordinates coord(x, y);
				plant[1][wallnutCount++] = new WallNut(&coord);
				*currency -= 50;
				return false;
			}
			else if (plantType == 'C' && *currency >= 150) {
				Coordinates coord(x, y);
				plant[2][cherryBombCount++] = new CherryBomb(&coord);
				*currency -= 150;
				return false;
			}

			else if (plantType == 'T' && *currency >= 100) {
				Coordinates coord(x, y);
				plant[3][torchwoodCount++] = new Torchwood(&coord);
				*currency -= 100;
				return false;
			}
			else
				return true;
		}
		else
			return true;
	}
}
int NonshooterPlantFactory::getMaxPlantNum() {
	return maxPlantNum;
}
int NonshooterPlantFactory::getCountSunflowers() {
	return sunflowerCount;
}
int NonshooterPlantFactory::getCountWallnuts() {
	return wallnutCount;
}
int NonshooterPlantFactory::getCountCherryBomb() {
	return cherryBombCount;
}
int NonshooterPlantFactory::getCountTorchwood() {
	return torchwoodCount;
}
int NonshooterPlantFactory::getTotalCount() {
	return sunflowerCount + wallnutCount + cherryBombCount + torchwoodCount;
}
NonShooters*** NonshooterPlantFactory::getNonShooterPlantArray() {
	return plant;
}
void NonshooterPlantFactory::drawPlant(RenderWindow& window) {
	for (int i = 0; i < maxPlantNum; i++) {
		if (i == 0)
		{
			for (int j = 0; j < sunflowerCount; j++)
				plant[i][j]->DrawPlant(window);
		}
		if (i == 1)
		{
			for (int j = 0; j < wallnutCount; j++)
				plant[i][j]->DrawPlant(window);
		}
		if (i == 2)
		{
			for (int j = 0; j < cherryBombCount; j++)
				plant[i][j]->DrawPlant(window);
		}
		if (i == 3)
		{
			for (int j = 0; j < torchwoodCount; j++)
				plant[i][j]->DrawPlant(window);
		}
	}
}

///////////shooterFactory/////////

ShooterPlantFactory::ShooterPlantFactory(int l) {
	levelNo = l;
	if (l == 1) {
		maxPlantNum = 1;
	}
	else if (l == 2) {
		maxPlantNum = 1;
	}
	else if (l == 3) {
		maxPlantNum = 3;
	}
	else if (l == 4) {
		maxPlantNum = 3;
	}
	plant = new Shooters * [maxPlantNum];
	for (int i = 0; i < maxPlantNum; i++) {
		if (i == 0)
			plant[i] = new PeaShooter[15];
		else if (i == 1)
			plant[i] = new  Repeater[15];
		else if (i == 2)
			plant[i] = new  SnowPea[15];
	}
}
bool ShooterPlantFactory::placePlant(int mouseX, int mouseY, bool notPlanted, char plantType, int* currency) {
	int x = 0, y = 0;
	if (notPlanted == true) {
		if (mouseX >= 390 && mouseX <= 1560 && mouseY > 112) {
			if (mouseX >= 390 && mouseX <= 520) {
				x = 420;
			}
			if (mouseX >= 520 && mouseX <= 650) {
				x = 550;
			}
			if (mouseX >= 650 && mouseX <= 780) {
				x = 680;
			}
			if (mouseX >= 780 && mouseX <= 910) {
				x = 810;
			}
			if (mouseX >= 910 && mouseX <= 1040) {
				x = 940;
			}
			if (mouseX >= 1040 && mouseX <= 1170) {
				x = 1070;
			}
			if (mouseX >= 1170 && mouseX <= 1300) {
				x = 1200;
			}
			if (mouseX >= 1300 && mouseX <= 1430) {
				x = 1330;
			}
			if (mouseX >= 1430 && mouseX <= 1560) {
				x = 1460;
			}
			if (mouseY >= 280 && mouseY <= 420) {
				y = 330;
			}
			else if (mouseY >= 420 && mouseY <= 560) {
				y = 470;
			}
			else if (mouseY >= 560 && mouseY <= 700) {
				y = 610;
			}
			else if (mouseY >= 700 && mouseY <= 820) {
				y = 750;
			}
			else if (mouseY >= 820 && mouseY <= 960) {
				y = 870;
			}
			if (plantType == 'P' && *currency >= 100) {
				plant[0][peashooterCount++].setPosition(x, y);
				*currency -= 100;
				return false;
			}

			else if (plantType == 'R' && *currency >= 200) {
				plant[1][repeaterCount++].setPosition(x, y);
				*currency -= 200;
				return false;
			}
			else if (plantType == 'N' && *currency >= 150) {
				plant[2][snowpeaCount++].setPosition(x, y);
				*currency -= 150;
				return false;
			}
			else
				return true;
		}
		else
			return true;
	}
}
void ShooterPlantFactory::drawPlant(RenderWindow& window) {
	for (int i = 0; i < maxPlantNum; i++) {
		if (i == 0)
		{
			for (int j = 0; j < peashooterCount; j++)
				plant[i][j].DrawPlant(window);
		}
		if (i == 1)
		{
			for (int j = 0; j < repeaterCount; j++)
				plant[i][j].DrawPlant(window);
		}
		if (i == 2)
		{
			for (int j = 0; j < snowpeaCount; j++)
				plant[i][j].DrawPlant(window);
		}
	}
}
int ShooterPlantFactory::getMaxPlantNum() {
	return maxPlantNum;
}
int ShooterPlantFactory::getCountPeaShooters() {
	return peashooterCount;
}
int ShooterPlantFactory::getCountRepeaters() {
	return repeaterCount;
}
int ShooterPlantFactory::getCountSnowpea() {
	return snowpeaCount;
}
int ShooterPlantFactory::getTotalCount() {
	return peashooterCount + repeaterCount + snowpeaCount;
}
Shooters** ShooterPlantFactory::getShooterPlantArray() {
	return plant;
}