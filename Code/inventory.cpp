#include"Inventory.h"

inventory::inventory() {
	levelNo = 1;
	select.setPosition(-100, -120);

}
inventory::inventory(int level) {
	levelNo = level;
	select.setPosition(-100, -120);
}
void inventory::displayLevel1(RenderWindow& window) {
	Sprite cardPea;
	Texture textureCardPea;
	Sprite cardSunflower;
	Texture textureCardsunflower;
	textureCardPea.loadFromFile("peashooterCard.png");
	cardPea.setTexture(textureCardPea);
	cardPea.setPosition(176, 0);
	window.draw(cardPea);
	textureCardsunflower.loadFromFile("sunflowerCard.png");
	cardSunflower.setTexture(textureCardsunflower);
	cardSunflower.setPosition(352, 0);
	window.draw(cardSunflower);
}
void inventory::displayLevel2(RenderWindow& window) {
	Sprite cardWallnut;
	Texture textureCardWallnut;
	Sprite cardCherry;
	Texture textureCardCherry;
	textureCardWallnut.loadFromFile("wallnutCard.png");
	cardWallnut.setTexture(textureCardWallnut);
	cardWallnut.setPosition(528, 0);
	window.draw(cardWallnut);
	textureCardCherry.loadFromFile("cherrybombCard.png");
	cardCherry.setTexture(textureCardCherry);
	cardCherry.setPosition(704, 0);
	window.draw(cardCherry);
}
void inventory::displayLevel3(RenderWindow& window) {
	Sprite cardRepeater;
	Texture textureCardRepeater;
	textureCardRepeater.loadFromFile("repeaterCard.png");
	cardRepeater.setTexture(textureCardRepeater);
	cardRepeater.setPosition(884, 0);
	window.draw(cardRepeater);
	Sprite cardSnowpea;
	Texture textureCardSnowpea;
	textureCardSnowpea.loadFromFile("snowpeaCard.png");
	cardSnowpea.setTexture(textureCardSnowpea);
	cardSnowpea.setPosition(1064, 0);
	window.draw(cardSnowpea);
}
void inventory::displayLevel4(RenderWindow& window) {
	Sprite cardTorchwood;
	Texture textureCardTorchwood;
	textureCardTorchwood.loadFromFile("torchwoodCard.png");
	cardTorchwood.setTexture(textureCardTorchwood);
	cardTorchwood.setPosition(1249, 0);
	window.draw(cardTorchwood);
}
void inventory::displayCards(RenderWindow& window) {
	if (levelNo == 1) {
		displayLevel1(window);
		return;
	}
	else if (levelNo == 2) {
		displayLevel1(window);
		displayLevel2(window);
		return;
	}
	else if (levelNo == 3) {
		displayLevel1(window);
		displayLevel2(window);
		displayLevel3(window);
		return;
	}
	else if (levelNo == 4) {
		displayLevel1(window);
		displayLevel2(window);
		displayLevel3(window);
		displayLevel4(window);
	}
}
void inventory::drawSelect(RenderWindow& window) {
	window.draw(select);
}
char inventory::isClicked(int x, int y, RenderWindow& window) {
	selectText.loadFromFile("Textures\\select.png");
	select.setTexture(selectText);
	if (levelNo == 1) {
		if (x >= 176 && x < 352 && y <= 112) {
			select.setPosition(176, 0);
			return 'P';
		}
		if (x >= 352 && x < 528 && y <= 112) {
			select.setPosition(352, 0);
			return 'S';
		}
	}
	if (levelNo == 2) {
		if (x >= 176 && x < 352 && y <= 112) {
			select.setPosition(176, 0);
			return 'P';
		}
		if (x >= 352 && x < 528 && y <= 112) {
			select.setPosition(352, 0);
			return 'S';
		}
		if (x >= 528 && x < 704 && y <= 112) {
			select.setPosition(528, 0);
			return 'W';
		}
		if (x >= 704 && x < 884 && y <= 112) {
			select.setPosition(704, 0);
			return 'C';
		}

	}
	if (levelNo == 3) {
		if (x >= 176 && x < 352 && y <= 112) {
			select.setPosition(176, 0);
			return 'P';
		}
		if (x >= 352 && x < 528 && y <= 112) {
			select.setPosition(352, 0);
			return 'S';
		}
		if (x >= 528 && x < 704 && y <= 112) {
			select.setPosition(528, 0);
			return 'W';
		}
		if (x >= 704 && x < 884 && y <= 112) {
			select.setPosition(704, 0);
			return 'C';
		}
		if (x >= 884 && x < 1064 && y <= 112) {
			select.setPosition(884, 0);
			return 'R';
		}
		if (x >= 1064 && x < 1249 && y <= 112) {
			select.setPosition(1064, 0);
			return 'N';    //snowPea
		}
	}
	if (levelNo == 4) {
		if (x >= 176 && x < 352 && y <= 112) {
			select.setPosition(176, 0);
			return 'P';
		}
		if (x >= 352 && x < 528 && y <= 112) {
			select.setPosition(352, 0);
			return 'S';
		}
		if (x >= 528 && x < 704 && y <= 112) {
			select.setPosition(528, 0);
			return 'W';
		}
		if (x >= 704 && x < 884 && y <= 112) {
			select.setPosition(704, 0);
			return 'C';
		}
		if (x >= 884 && x < 1064 && y <= 112) {
			select.setPosition(884, 0);
			return 'R';
		}
		if (x >= 1064 && x < 1249 && y <= 112) {
			select.setPosition(1064, 0);
			return 'N';
		}
		if (x >= 1249 && x < 1434 && y <= 112) {
			select.setPosition(1249, 0);
			return 'F';
		}
	}
	else {
		select.setPosition(-100, -120);
		return 'O';
	}
}