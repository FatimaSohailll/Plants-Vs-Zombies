#include"Screen.h"

/////////////Screen/////////
char Screen::touchButton(int mouseX, int mouseY) {
	if (mouseX >= 0 && mouseX <= 68 && mouseY >= 0 && mouseY <= 68) {
		return 'M';
	}
	if (mouseX >= 800 && mouseX <= 1106 && mouseY >= 570 && mouseY <= 703) {
		return 'L';
	}
	if (mouseX >= 800 && mouseX <= 1106 && mouseY >= 660 && mouseY <= 793) {
		return 'I';
	}
}
Levels* Screen::getCurrLevel() {
	return nullptr;
}
Screen:: ~Screen() {}

///////////////Menu/////////////
void Menu::showBackButton(RenderWindow& window) {}
void Menu::createBack(RenderWindow& window) {
	//Drawing the background
	Image back_image;
	back_image.loadFromFile("Textures\\mainmenu.jpg");
	Texture background;
	background.loadFromImage(back_image);
	Sprite s_back;
	s_back.setTexture(background);
	s_back.setPosition(0, 0);
	startButton.loadFromFile("Textures\\StartButton.png");
	startSprite.setTexture(startButton);
	startSprite.setPosition(800, 570);
	instructButton.loadFromFile("Textures\\InstructionsButton1.png");
	instructSprite.setTexture(instructButton);
	instructSprite.setPosition(800, 660);
	window.draw(s_back);
	window.draw(startSprite);
	window.draw(instructSprite);
}
char Menu::run(RenderWindow& window) {
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					int mouseX = sf::Mouse::getPosition(window).x;
					int mouseY = sf::Mouse::getPosition(window).y;
					cout << mouseX << " " << mouseY << endl;
					return touchButton(mouseX, mouseY);

				}
			}
		}

		// Clear the window
		window.clear();

		// Draw the background
		createBack(window);

		// Display everything
		window.display();
	}
}

//////////Gameplay/////////////
Gameplay::Gameplay(int levelnum) {
	levelNo = levelnum;
	Backbutton.loadFromFile("backbutton.png");
	SpriteBack.setTexture(Backbutton);
	SpriteBack.setPosition(0, 0);
}
Levels* Gameplay::getCurrLevel() {
	return currlevel;
}
void Gameplay::showBackButton(RenderWindow& window) {
	window.draw(SpriteBack);
}
void Gameplay::createBack(RenderWindow& window) {
	showBackButton(window);
}
char Gameplay::run(RenderWindow& window) {
	if (levelNo == 1) {
		currlevel = new Level1;
	}
	else if (levelNo == 2) {
		currlevel = new Level2;
	}
	else if (levelNo == 3) {
		currlevel = new Level3;
	}
	if (levelNo == 4) {
		currlevel = new Level4;
	}
	return currlevel->run(window);

}
Gameplay:: ~Gameplay() {
	delete currlevel;
}

/////////////Instructions///////////////
Instructions::Instructions() {
	Backbutton.loadFromFile("backbutton.png");
	SpriteBack.setTexture(Backbutton);
	SpriteBack.setPosition(0, 0);
}
void Instructions::showBackButton(RenderWindow& window) {
	window.draw(SpriteBack);
}
void Instructions::createBack(RenderWindow& window) {
	//Drawing the background
	Image back_image;
	back_image.loadFromFile("Textures\\instructions.jpg");
	Texture background;
	background.loadFromImage(back_image);
	Sprite s_back;
	s_back.setTexture(background);
	s_back.setPosition(0, -100);
	window.draw(s_back);
	showBackButton(window);
}
char Instructions::run(RenderWindow& window) {
	while (window.isOpen()) {
		// Handle events
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {

					int mouseX = sf::Mouse::getPosition(window).x;
					int mouseY = sf::Mouse::getPosition(window).y;
					return touchButton(mouseX, mouseY);

				}
			}
		}

		// Clear the window
		window.clear();

		// Draw the background
		createBack(window);

		// Display everything
		window.display();
	}
	return 'O';

}

////////////////Gameover////////////
GameOver::GameOver() {
	Backbutton.loadFromFile("backbutton.png");
	SpriteBack.setTexture(Backbutton);
	SpriteBack.setPosition(0, 0);
}
void GameOver::showBackButton(RenderWindow& window) {
	window.draw(SpriteBack);
}
void GameOver::createBack(RenderWindow& window) {
	//Drawing the background
	Image back_image;
	back_image.loadFromFile("mainmenu-01.png");
	Texture background;
	background.loadFromImage(back_image);
	Sprite s_back;
	s_back.setTexture(background);
	s_back.setPosition(650, 300);
	window.draw(s_back);
	showBackButton(window);
}
char GameOver::run(RenderWindow& window) {
	while (window.isOpen()) {
		// Handle events
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {

					int mouseX = sf::Mouse::getPosition(window).x;
					int mouseY = sf::Mouse::getPosition(window).y;
					return touchButton(mouseX, mouseY);

				}
			}
		}

		// Clear the window
		window.clear();

		// Draw the background
		createBack(window);

		// Display everything
		window.display();
	}
	return 'O';

}

///////////Pause///////////////
Pause::Pause() {
	Backbutton.loadFromFile("backbutton.png");
	SpriteBack.setTexture(Backbutton);
	SpriteBack.setPosition(0, 0);
}
void Pause::showBackButton(RenderWindow& window) {
	window.draw(SpriteBack);
}
void Pause::createBack(RenderWindow& window) {
	//Drawing the background
	Image back_image;
	back_image.loadFromFile("mainmenu-01.png");
	Texture background;
	background.loadFromImage(back_image);
	Sprite s_back;
	s_back.setTexture(background);
	s_back.setPosition(0, 0);
	window.draw(s_back);
	showBackButton(window);
}

///////////////Levelgallery////////
LevelGallery::LevelGallery() {
	Backbutton.loadFromFile("backbutton.png");
	SpriteBack.setTexture(Backbutton);
	SpriteBack.setPosition(0, 0);
}
char LevelGallery::touchButton(int mouseX, int mouseY) {
	if (mouseX >= 100 && mouseX <= 463 && mouseY >= 300 && mouseY <= 700) {
		return '1';
	}
	if (mouseX >= 500 && mouseX <= 863 && mouseY >= 300 && mouseY <= 700) {
		return '2';
	}
	if (mouseX >= 900 && mouseX <= 1263 && mouseY >= 300 && mouseY <= 700) {
		return '3';
	}
	if (mouseX >= 1300 && mouseX <= 1663 && mouseY >= 300 && mouseY <= 700) {
		return '4';
	}

}
void LevelGallery::showBackButton(RenderWindow& window) {
	window.draw(SpriteBack);
}
void LevelGallery::createBack(RenderWindow& window) {
	//Drawing the background
	Image back_image;
	back_image.loadFromFile("Textures\\menu_dark_mode.png");
	Texture background;
	background.loadFromImage(back_image);
	Sprite s_back;
	s_back.setTexture(background);
	s_back.setPosition(0, -60);
	Texture L1;
	Sprite L1S;
	Texture L2;
	Sprite L2S;
	Texture L3;
	Sprite L3S;
	Texture L4;
	Sprite L4S;
	L1.loadFromFile("Textures\\L1.png");
	L1S.setTexture(L1);
	L1S.setPosition(100, 300);
	L2.loadFromFile("Textures\\L2.png");
	L2S.setTexture(L2);
	L2S.setPosition(500, 300);
	L3.loadFromFile("Textures\\L3.png");
	L3S.setTexture(L3);
	L3S.setPosition(900, 300);
	L4.loadFromFile("Textures\\L4.png");
	L4S.setTexture(L4);
	L4S.setPosition(1300, 300);
	window.draw(s_back);
	window.draw(L1S);
	window.draw(L2S);
	window.draw(L3S);
	window.draw(L4S);
	showBackButton(window);
}
char LevelGallery::run(RenderWindow& window) {
	while (window.isOpen()) {
		// Handle events
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {

					int mouseX = sf::Mouse::getPosition(window).x;
					int mouseY = sf::Mouse::getPosition(window).y;
					return touchButton(mouseX, mouseY);

				}
			}
		}

		// Clear the window
		window.clear();

		// Draw the background
		createBack(window);

		// Display everything
		window.display();
	}
	return 'O';

}