#include"Levels.h"

/////////Levels/////////

Levels::Levels() {
	currency = 400;
	lives = 3;
	gameover = false;
	countSun.loadFromFile("Textures\\Button2.png");
	countSunSp.setTexture(countSun);
	countSunSp.setPosition(1460, 0);
}
int Levels::getLevelNo() {
	return levelNo;
}
int Levels::getCurrency() {
	return currency;
}
void Levels::setCurrency(int c) {
	currency = c;
}
int Levels::getLives() {
	return lives;
}
void Levels::setLives(int l) {
	lives = l;
}
void Levels::checkSunClick(NonShooters*** plants, int sunflowerCount, int mouseX, int mouseY) {
	for (int i = 0; i < sunflowerCount; i++) {
		if (mouseX >= plants[0][i]->getSun().getPosition().getX() - 80 &&
			mouseX <= plants[0][i]->getSun().getPosition().getX() + 80
			&& mouseY >= plants[0][i]->getSun().getPosition().getY() - 80 &&
			mouseY <= plants[0][i]->getSun().getPosition().getY() + 80) {
			setCurrency(getCurrency() + 25);
			plants[0][i]->getSun().setPosition(-100, -100);
			plants[0][i]->getClock().restart();
		}

	}

}
void Levels::checkSunRandClick(Sun* sunPtr, int mouseX, int mouseY) {
	if (mouseX >= sunPtr->getPosition().getX() - 80 &&
		mouseX <= sunPtr->getPosition().getX() + 80
		&& mouseY >= sunPtr->getPosition().getY() - 80 &&
		mouseY <= sunPtr->getPosition().getY() + 80) {
		setCurrency(getCurrency() + 25);
		sunPtr->setPosition(sunPtr->getPosition().getX(), 1200);

	}
}
char Levels::run(RenderWindow& window) {
	srand(time(0));
	//Create a window, n*n
	//////sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Plants vs. Zombies", sf::Style::Fullscreen);
	////sf::Vector2u windowSize = window.getSize();
	////unsigned int windowWidth = windowSize.x;
	////unsigned int windowHeight = windowSize.y;
	////// Now you can use windowWidth and windowHeight to access the width and height of the window


	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	//height = 140/150, width = 130
	const int ROWS = 5;
	const int COLS = 9;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
		}
	}

	Clock timeMoney;

	Clock clock;
	char plantType;
	char plantWhere;
	bool notPlanted = false;

	ZombieFactory ZF;
	Zombie** zombies = ZF.createWave(levelNo);
	int numZombiesSpawned = 0;
	Clock zombieTimer;
	NonshooterPlantFactory plantFactory(levelNo);
	ShooterPlantFactory shooterFactory(levelNo);
	Sun* sunPtr = new Sun;
	sunPtr->generateRandomSuns();

	MowerFactory MowerF;
	LawnMower** mowers = MowerF.createLawnMowers();

	inventory I(levelNo);
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text text;
	text.setFont(font); // Set the font
	text.setCharacterSize(50); // Set the character size
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setPosition(1500.f, 10.f);
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		float moneyTime = timeMoney.getElapsedTime().asSeconds();

		//	sf::Time timePerFrame = sf::seconds(1.f / 8000.f); // Set target frame rate (e.g., 60 FPS)

		clock.restart();
		time = time / 800;
		Event event;
		while (window.pollEvent(event) && lives > 0)
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {

					int mouseX = sf::Mouse::getPosition(window).x;
					int mouseY = sf::Mouse::getPosition(window).y;
					int x = 0;
					int y = 0;
					checkSunClick(plantFactory.getNonShooterPlantArray(), plantFactory.getCountSunflowers(), mouseX, mouseY);
					checkSunRandClick(sunPtr, mouseX, mouseY);
					cout << "Currency: " << getCurrency() << endl;;
					if (notPlanted == false)
						plantType = I.isClicked(mouseX, mouseY, window);
					else
						plantWhere = I.isClicked(mouseX, mouseY, window);
					if (plantType != 'O') {
						notPlanted = true;
					}
					if (notPlanted == true) {

						notPlanted = plantFactory.placePlant(mouseX, mouseY, notPlanted, plantType, &currency);
						if (notPlanted == true)
							notPlanted = shooterFactory.placePlant(mouseX, mouseY, notPlanted, plantType, &currency);
					}
				}
			}

		}


		//Create a background
		setBackground(window);
		//createMap(window);
		sunPtr->DrawRndomSun(window);
		I.displayCards(window);
		//Z.drawZombie(window);
		for (int i = 0; i < 5; ++i) {
			mowers[i]->drawMower(window);
		}

		for (int i = 0; i < 5; ++i) {
			mowers[i]->updatePosition();
		}

		if (numZombiesSpawned < ZF.calculateNumZombies(levelNo) && zombieTimer.getElapsedTime().asSeconds() >= rand() % 15 + 5)
		{
			numZombiesSpawned++;

			zombieTimer.restart();
		}
		for (int i = 0; i < numZombiesSpawned; i++) {
			zombies[i]->drawZombie(window, mowers, shooterFactory.getShooterPlantArray(), shooterFactory.getCountSnowpea(),
				shooterFactory.getCountRepeaters(), shooterFactory.getCountPeaShooters());
		}
		for (int i = 0; i < numZombiesSpawned; i++)
		{
			zombies[i]->PlantCollisions(shooterFactory.getShooterPlantArray(), shooterFactory.getCountSnowpea(), shooterFactory.getCountRepeaters(), shooterFactory.getCountPeaShooters(), plantFactory.getNonShooterPlantArray(), plantFactory.getCountSunflowers(),
				plantFactory.getCountWallnuts(), plantFactory.getCountCherryBomb(), plantFactory.getCountTorchwood());
		}
		for (int i = 0; i < numZombiesSpawned; i++) {
			if (zombies[i]->getPosition().getX() <= 390 && zombies[i]->getEnd() == true) {
				if (this->getLives() > 0) {
					this->setLives(this->getLives() - 1);
					cout << this->getLives();
				}
				else if (this->getLives() <= 0) {
					cout << "game over" << endl;
					gameover = true;
					break;
					return 'Z';
				}
			}
		}
		text.setString("Suns: " + std::to_string(currency));

		I.drawSelect(window);
		plantFactory.drawPlant(window);
		shooterFactory.drawPlant(window);
		if (lives == 0) {
			return 'Z';
		}
		window.setSize(sf::Vector2u(1920, 975));
		//window size is 1920 x 1080
		window.draw(countSunSp);
		window.draw(text);
		window.display();


	}
	ZF.destroyWave(zombies, ZF.calculateNumZombies(levelNo));
	MowerF.destroyLawnMowers(mowers);

}
Levels:: ~Levels() {
}

///////////Level1////////////

Level1::Level1() {
	levelNo = 1;
}
void Level1::setBackground(RenderWindow& window) {
	Image map_image;
	map_image.loadFromFile("Textures\\Beginner'sGarden.jpg");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
	window.draw(countSunSp);
}
Level1:: ~Level1() {
	lives = 0;
}

///////////////Level2/////////

Level2::Level2() {
	levelNo = 2;
}
void Level2::setBackground(RenderWindow& window) {
	Image map_image;
	map_image.loadFromFile("Textures\\outskirts.jpg");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
	window.draw(countSunSp);
}

/////////////Level3///////////

Level3::Level3() {
	levelNo = 3;
}
void Level3::setBackground(RenderWindow& window) {

	Image map_image;
	map_image.loadFromFile("Textures\\sunflowerField.jpg");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
	window.draw(countSunSp);

}

////////////Level4////////////
Level4::Level4() {
	levelNo = 4;
}
void Level4::setBackground(RenderWindow& window) {
	Image map_image;
	map_image.loadFromFile("Textures\\foggy.jpg");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
	window.draw(countSunSp);

}
