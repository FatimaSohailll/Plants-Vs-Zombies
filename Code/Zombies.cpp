#include"Zombies.h"

////////////zombie//////////
void Zombie::setOriginalSpeed(int s) {
	this->originalSpeed = s;
}
int  Zombie::getOriginalSpeed() {
	return this->originalSpeed;
}
bool  Zombie::getEnd() {
	return end;
}
void  Zombie::spawnInRow(Zombie& Z) {
	int row = rand() % 5 + 1;
	switch (row) {
	case (1):  this->setPosition(1600, 280);
		break;
	case (2):  this->setPosition(1600, 420);
		break;
	case (3):  this->setPosition(1600, 560);
		break;
	case (4):  this->setPosition(1600, 700);
		break;
	case (5):  this->setPosition(1600, 820);
		break;
	}
}
void  Zombie::drawZombie(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount) {}
void  Zombie::MowerZombieCollision(LawnMower** mowers) {
	for (int i = 0; i < 5; i++) {
		if (mowers[i]->getPosition().getX() <= this->getPosition().getX() + 150 && mowers[i]->getPosition().getX() + 100 >= this->getPosition().getX() &&
			mowers[i]->getPosition().getY() <= this->getPosition().getY() + 150 && mowers[i]->getPosition().getY() + 50 >= this->getPosition().getY()) {
			mowers[i]->hasRun = true;
			this->setHealth(0);
			this->setPosition(-1000, -1000);
		}
	}
}
void  Zombie::checkCollisionZom(Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount) {
	for (int i = 0; i < 3; i++) {
		int k;
		if (i == 0)
			k = peashooterCount;
		else if (i == 1)
			k = repeaterCount;
		else if (i == 2)
			k = snowpeaCount;

		for (int j = 0; j < k; j++) {
			int numPeas = 1; // Default number of peas fired by the shooter
			if (i == 1) {
				numPeas = 2; // If shooter type is repeater, set the number of peas to 2
			}

			for (int p = 0; p < numPeas; p++) { // Iterate through each pea
				if (((shooters[i][j].getWeapon()) + p)->getPosition().getX() + 50 >= this->position.getX() &&
					((shooters[i][j].getWeapon()) + p)->getPosition().getX() <= this->position.getX() + 100 &&
					((shooters[i][j].getWeapon()) + p)->getPosition().getY() + 50 >= this->position.getY() &&
					((shooters[i][j].getWeapon()) + p)->getPosition().getY() <= this->position.getY() + 150) {

					((shooters[i][j].getWeapon()) + p)->setPosition(shooters[i][j].getPosition().getX(), ((shooters[i][j].getWeapon()) + p)->getPosition().getY());

					if (i == 2) {          // Snow pea
						this->setSpeed(2);
					}

					// Update zombie's health based on weapon's damage
					this->setHealth(this->getHealth() - ((shooters[i][j].getWeapon()) + p)->getDamage());

					// If zombie's health reaches zero move it outside the screen
					if (this->getHealth() <= 0) {
						this->setPosition(-1000, -1000);
					}
				}
			}
		}
	}
}
void  Zombie::PlantCollisions(Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount,
	NonShooters*** nonshooters, int sunflowerCount, int wallnutCount, int cherrybombCount, int torchwoodCount)
{	//int zOriginalSpeed = this->getSpeed();
	Clock shooterClock, nonshooterClock;
	//	shooterClock.restart(); // Start the clock

		// Handle shooter collisions
	for (int i = 0; i < 3; i++) {
		int k;
		if (i == 0)
			k = peashooterCount;
		else if (i == 1)
			k = repeaterCount;
		else if (i == 2)
			k = snowpeaCount;

		for (int j = 0; j < k; j++) {
			// cout << zOriginalSpeed << endl;
			if (shooters[i][j].getPosition().getX() + 90 >= this->position.getX() &&
				shooters[i][j].getPosition().getX() <= this->position.getX() + 350 &&
				shooters[i][j].getPosition().getY() + 90 >= this->position.getY() &&
				shooters[i][j].getPosition().getY() <= this->position.getY() + 100) {
				shooters[i][j].getWeapon()->setPosition(-2000, -2000);
				shooters[i][j].getWeapon()->setSpeed(0);
				cout << "first if\n";
			}

			if (shooters[i][j].getPosition().getX() + 90 >= this->position.getX() &&
				shooters[i][j].getPosition().getX() <= this->position.getX() + 150 &&
				shooters[i][j].getPosition().getY() + 90 >= this->position.getY() &&
				shooters[i][j].getPosition().getY() <= this->position.getY() + 100) {
				shooterClock.restart();
				cout << "shooter collision detected\n";
				this->setSpeed(0);

				// Set the position of the shooter's weapon outside the screen
				shooters[i][j].getWeapon()->setPosition(-2000, -2000);

				// Set the speed of the shooter's weapon to 0
				shooters[i][j].getWeapon()->setSpeed(0);


				if (shooterClock.getElapsedTime().asSeconds() >= 0.0001f) {
					//cout << "Time elapsed > 1\n";
					shooters[i][j].setHealth(shooters[i][j].getHealth() - this->getDamage());
					// Restart the clock to track the time for the next damage
					shooterClock.restart();
					if (shooterClock.getElapsedTime().asSeconds() >= 1.0f) {
						//cout << "Time elapsed > 1\n";
						shooters[i][j].setHealth(shooters[i][j].getHealth() - this->getDamage());
						// Restart the clock to track the time for the next damage
						shooterClock.restart();

					}
				}


				// Check if the shooter's health is less than or equal to zero
				if (shooters[i][j].getHealth() <= 0) {
					shooters[i][j].setPosition(-2000, -2000);
					//cout << zOriginalSpeed;
					this->setSpeed(this->getOriginalSpeed());
					cout << this->getSpeed();
				}
			}
		}
	}

	// Handle non-shooter collisions
	for (int i = 0; i < 4; i++) {
		int k;
		if (i == 0)
			k = sunflowerCount;
		else if (i == 1)
			k = wallnutCount;
		else if (i == 2)
			k = cherrybombCount;
		else if (i == 3)
			k = torchwoodCount;

		for (int j = 0; j < k; j++) {
			if (nonshooters[i][j]->getPosition().getX() + 90 >= this->position.getX() &&
				nonshooters[i][j]->getPosition().getX() <= this->position.getX() + 100 &&
				nonshooters[i][j]->getPosition().getY() + 90 >= this->position.getY() &&
				nonshooters[i][j]->getPosition().getY() <= this->position.getY() + 100) {

				if (i == 2 || i == 3) {
					this->setHealth(0);
					this->setPosition(-1500, -1500);
					if (i == 2) {
						nonshooters[i][j]->setPosition(-1100, -1100);
					}
					break;
				}

				cout << "nonshooter collision detected\n";
				this->setSpeed(0);

				if (nonshooterClock.getElapsedTime().asSeconds() >= 0.0001f) {
					//cout << "Time elapsed > 1\n";
					nonshooters[i][j]->setHealth(shooters[i][j].getHealth() - this->getDamage());
					// Restart the clock to track the time for the next damage
					nonshooterClock.restart();
					if (nonshooterClock.getElapsedTime().asSeconds() >= 1.0f) {
						//cout << "Time elapsed > 1\n";
						nonshooters[i][j]->setHealth(shooters[i][j].getHealth() - this->getDamage());
						// Restart the clock to track the time for the next damage
						nonshooterClock.restart();

					}
				}


				// Check if the shooter's health is less than or equal to zero
				if (nonshooters[i][j]->getHealth() <= 0) {
					nonshooters[i][j]->setPosition(-2000, -2000);
					this->setSpeed(this->getOriginalSpeed());
				}
			}
		}
	}
}

//////////////Simple Zombie///////////
SimpleZombie::SimpleZombie() {
	this->spawnInRow(*this);
	this->setSpeed(4);
	this->setOriginalSpeed(4);
	this->end = true;
	setHealth(50);
	setDamage(10);
	MoveLeft = false;
	zombieTexture.loadFromFile("simplewalking.png");
	zombieSprite.setTexture(zombieTexture);
	walkingAnim = sf::IntRect(502, 0, 251, 170);
	zombieSprite.setTextureRect(walkingAnim);
}
void SimpleZombie::drawZombie(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount) {
	//cout << "Inside simple draw \n";
	if (clock.getElapsedTime().asMicroseconds() > 0.01) {
		if (walkingAnim.left >= 11200/*11250*/) {
			walkingAnim.left = 251;
		}
		else {
			walkingAnim.left += 251;
		}
		zombieSprite.setTextureRect(walkingAnim);
		clock.restart();
	}
	zombieSprite.setPosition(position.getX(), position.getY());
	window.draw(zombieSprite);
	this->updatePosition(mowers, shooters, snowpeaCount, repeaterCount, peashooterCount);
}
void SimpleZombie::updatePosition(LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount) {
	//	cout << "inside update \n";
	MowerZombieCollision(mowers);
	checkCollisionZom(shooters, snowpeaCount, repeaterCount, peashooterCount);

	if (position.getX() > 380) {
		this->position.setX(this->position.getX() - getSpeed());
		//cout << position.getX() << endl;
	}
	else this->end = false;

}

//////////Football Zombie///////////
FootballZombie::FootballZombie() {
	this->spawnInRow(*this);
	FootballAnim = sf::IntRect(266/*266*/, 0, 251, 170);
	this->setSpeed(10);
	this->setOriginalSpeed(10);
	this->end = true;
	setHealth(70);
	zombieTexture.loadFromFile("footballAnim.png");
	zombieSprite.setTexture(zombieTexture);
	zombieSprite.setTextureRect(FootballAnim);
	setDamage(10);

}
void FootballZombie::drawZombie(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount) {

	if (clock.getElapsedTime().asMicroseconds() > 0.001f) {
		if (FootballAnim.left >= 7440) {
			FootballAnim.left = 266;
		}
		else FootballAnim.left += 266;

		zombieSprite.setTextureRect(FootballAnim);
		clock.restart();
	}
	zombieSprite.setPosition(position.getX(), position.getY());
	window.draw(zombieSprite);
	this->updatePosition(mowers, shooters, snowpeaCount, repeaterCount, peashooterCount);
}
void FootballZombie::updatePosition(LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount) {
	MowerZombieCollision(mowers);
	checkCollisionZom(shooters, snowpeaCount, repeaterCount, peashooterCount);

	if (position.getX() > 390) {
		this->position.setX(this->position.getX() - getSpeed());
	}
	else this->end = false;

}

///////////////Backup dancer//////////
BackupDancer::BackupDancer() {
	this->spawnInRow(*this);
	backup = sf::IntRect(500/*251*/, 0, 250, 170);
	movingDown = false;
	this->setSpeed(5);
	this->setOriginalSpeed(5);
	this->end = true;
	setHealth(50);
	zombieTexture.loadFromFile("backupDancer.png");
	zombieSprite.setTexture(zombieTexture);
	zombieSprite.setTextureRect(backup);
	setDamage(10);


}
void BackupDancer::drawZombie(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount) {
	zombieSprite.setPosition(this->position.getX(), position.getY());
	if (clock.getElapsedTime().asMicroseconds() > 0.01f) {
		if (backup.left >= 14900) {
			MoveLeft = true;
		}
		if (MoveLeft == true) {
			backup.left -= 500;
		}
		if (MoveLeft == false) {
			backup.left += 500;
		}
		if (backup.left <= 500) {
			MoveLeft = false;
		}

		zombieSprite.setTextureRect(backup);
		clock.restart();
	}

	window.draw(zombieSprite);
	this->updatePosition(mowers, shooters, snowpeaCount, repeaterCount, peashooterCount);
}
void BackupDancer::updatePosition(LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount) {
	MowerZombieCollision(mowers);
	checkCollisionZom(shooters, snowpeaCount, repeaterCount, peashooterCount);

	if (position.getX() > 390) {
		this->position.setX(this->position.getX() - getSpeed());
	}
	else this->end = false;

}

///////////Dancing zombie////////////

DancingZombie::DancingZombie() {
	this->spawnInRow(*this);
	dancingAnim = sf::IntRect(502/*251*/, 0, 251, 170);
	movingDown = false;
	numBackup = rand() % 2 + 3;
	this->setSpeed(7);
	this->setOriginalSpeed(7);
	setHealth(70);
	bool end = true;
	zombieTexture.loadFromFile("dancingAnim1.png");
	zombieSprite.setTexture(zombieTexture);
	zombieSprite.setTextureRect(dancingAnim);
	setDamage(10);

}
BackupDancer* DancingZombie::getDancersPtr() {
	return dancersArr;
}
void DancingZombie::drawZombie(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount) {
	zombieSprite.setPosition(position.getX(), position.getY());

	if (clock.getElapsedTime().asMicroseconds() > 0.01f) {
		if (dancingAnim.left >= 15848/*15900*/) {
			MoveLeft = true;
			//cout << MoveLeft << endl;
			//dancingAnim.left = 251;
		}
		if (MoveLeft == true) {
			dancingAnim.left -= 502;//251;
			//cout << MoveLeft << endl;

		}
		if (MoveLeft == false) {
			dancingAnim.left += 502;//251;
			//cout << MoveLeft << endl;

		}
		if (dancingAnim.left <= 502/*251*/) {
			MoveLeft = false;
			//cout << MoveLeft << endl;

		}

		zombieSprite.setTextureRect(dancingAnim);
		clock.restart();
	}

	window.draw(zombieSprite);
	this->updatePosition(window, mowers, shooters, snowpeaCount, repeaterCount, peashooterCount);
}
void DancingZombie::updatePosition(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount) {
	MowerZombieCollision(mowers);
	checkCollisionZom(shooters, snowpeaCount, repeaterCount, peashooterCount);

	if (position.getX() <= 1200 && backupsSpawned == false) {
		spawnBackups(window, mowers, shooters, snowpeaCount, repeaterCount, peashooterCount);
		backupsSpawned = true;
	}
	if (backupsSpawned == true) {
		for (int i = 0; i < numBackup; i++) {
			dancersArr[i].drawZombie(window, mowers, shooters, snowpeaCount, repeaterCount, peashooterCount);
		}
		//if (dancersArr[1].getPosition().getX() <= 400 && dancersArr[2].getPosition().getX() <= 400 || /*run loop to check if health of all dancerarr zombies is 0 */) {
		//	destroyBackups();
		//}
	}

	// Check if zombie is within the horizontal bounds
	if (position.getX() > 390) {
		// Move horizontally
		this->position.setX(this->position.getX() - getSpeed());

		// Move vertically based on direction
		if (movingDown) {
			this->position.setY(this->position.getY() + 2);
			// Reverse direction if reaching bottom
			if (position.getY() >= 960 - 170)
				movingDown = false;
		}
		else {
			this->position.setY(this->position.getY() - 2);
			// Reverse direction if reaching top
			if (position.getY() <= 280)
				movingDown = true;
		}
	}
	else this->end = false;

}
void DancingZombie::spawnBackups(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount) {
	dancersArr = new BackupDancer[numBackup];
	dancersArr[0].setPosition(this->getPosition().getX() - 100, this->getPosition().getY() - 100);
	dancersArr[1].setPosition(this->getPosition().getX() + 100, this->getPosition().getY() - 100);
	dancersArr[2].setPosition(this->getPosition().getX() + 100, this->getPosition().getY() + 100);
	if (numBackup == 4) {
		dancersArr[3].setPosition(this->getPosition().getX() - 100, this->getPosition().getY() + 100);
	}
	for (int i = 0; i < numBackup; i++) {
		dancersArr[i].drawZombie(window, mowers, shooters, snowpeaCount, repeaterCount, peashooterCount);
	}
}
void DancingZombie::destroyBackups() {
	delete[] dancersArr;
}

///////////////Flying zombie/////////
FlyingZombie::FlyingZombie() {
	this->spawnInRow(*this);
	flyingAnim = sf::IntRect(250, 0, 250, 170);
	setHealth(70);
	setSpeed(5);
	this->setOriginalSpeed(5);
	this->end = true;
	zombieTexture.loadFromFile("flyingAnim.png");
	zombieSprite.setTexture(zombieTexture);
	zombieSprite.setTextureRect(flyingAnim);
	setDamage(10);
}
void FlyingZombie::drawZombie(RenderWindow& window, LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount) {

	if (clock.getElapsedTime().asMicroseconds() > 0.001f) {
		if (flyingAnim.left >= 1250/*15900*/) {
			MoveLeft = true;
			//cout << MoveLeft << endl;
			//dancingAnim.left = 251;
		}
		if (MoveLeft == true) {
			flyingAnim.left -= 250;//251;
			//cout << MoveLeft << endl;

		}
		if (MoveLeft == false) {
			flyingAnim.left += 250;//251;
			//cout << MoveLeft << endl;

		}
		if (flyingAnim.left <= 250/*251*/) {
			MoveLeft = false;
			//cout << MoveLeft << endl;

		}

		zombieSprite.setTextureRect(flyingAnim);
		clock.restart();
	}


	window.draw(zombieSprite);
	this->updatePosition(mowers, shooters, snowpeaCount, repeaterCount, peashooterCount);
}
void FlyingZombie::updatePosition(LawnMower** mowers, Shooters** shooters, int snowpeaCount, int repeaterCount, int peashooterCount) {
	MowerZombieCollision(mowers);
	checkCollisionZom(shooters, snowpeaCount, repeaterCount, peashooterCount);

	if (position.getX() > 390) {
		this->position.setX(this->position.getX() - getSpeed());
	}
	else this->end = false;

}

////////////Zombie factory//////////
Zombie** ZombieFactory::createWave(int level) {
	srand(time(0));
	int totalInLevel = calculateNumZombies(level);
	int typesInLevel = calculateNumTypes(level);
	Z = new Zombie * [totalInLevel];
	for (int i = 0; i < totalInLevel; ++i) {
		Z[i] = createRandomZombie(typesInLevel);
	}
	return Z;
}
int ZombieFactory::calculateNumZombies(int level) {
	return 5 * level;
}
int ZombieFactory::calculateNumTypes(int level) {
	switch (level) {
	case 1: return 1;
		break;
	case 2: return 3;
		break;
	case 3: return 4;
		break;
	case 4: return 5;
		break;
	case 6: return 5;
		break;
	default: return 2;
	}
}
Zombie* ZombieFactory::createRandomZombie(int typesInLevel) {
	int zombieType = rand() % typesInLevel;
	Zombie* zombie = nullptr;

	switch (zombieType) {
	case 0: zombie = new SimpleZombie;
		break;
	case 1: zombie = new FootballZombie;
		break;
	case 2: zombie = new DancingZombie;
		break;
	case 3: zombie = new FootballZombie;//FlyingZombie;
		break;
	case 4: zombie = new SimpleZombie; // NO DolphinRiderZombie yet;
		break;
	default: zombie = new SimpleZombie;
	}
	return zombie;
}
void ZombieFactory::destroyWave(Zombie** zombies, int totalInLevel) {
	for (int i = 0; i < totalInLevel; ++i) {
		delete zombies[i];
		zombies[i] = nullptr;
	}
	delete[] zombies;
	zombies = nullptr;
}
