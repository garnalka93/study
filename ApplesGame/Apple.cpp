#include "Apple.h"
#include "Sounds.h"

using namespace GameConstants;

int setApples(GameState& gameData) {
	gameData.apples.resize(gameData.APPLES_AMOUNT);
	if (!gameData.appleTexture.loadFromFile("Resources\\Apple.png")) {
		OutputDebugStringA("WARNING: Issues with apple image!\n");
		return -1;
	};
	applesConsumed = 0;
	for (int i = 0; i < gameData.APPLES_AMOUNT; i++) {
		gameData.apples[i].setTexture(gameData.appleTexture);
		gameData.apples[i].setOrigin(APPLE_SIZE / 2.f, APPLE_SIZE / 2.f);
		gameData.apples[i].setPosition(getRandomNumber(0, SCREEN_WIDTH), getRandomNumber(0, SCREEN_HEIGHT));
		gameData.apples[i].setScale(0.05,0.05);

		for (int c = 0; c < i; c++) {
			if (gameData.apples[i].getPosition() == gameData.apples[c].getPosition()) {
				gameData.apples[i].setPosition(getRandomNumber(0, SCREEN_WIDTH), getRandomNumber(0, SCREEN_HEIGHT));
				i--;
				break;
			}
		}
	}
}

void checkAppleCollision(GameState& gameData) {
	for (int i = 0; i < gameData.apples.size(); i++) {
		sf::FloatRect appleBounds = gameData.apples[i].getGlobalBounds();
		sf::FloatRect playerBounds = gameData.playerSprite.getGlobalBounds();
		if (playerBounds.intersects(appleBounds)) {
			if (gameData.endlessApples) {
				gameData.apples[i].setPosition(getRandomNumber(0, SCREEN_WIDTH), getRandomNumber(0, SCREEN_HEIGHT));
				i--;
			} else {
				gameData.apples.erase(gameData.apples.begin() + i);
			}			
			applesConsumed += 1;
			playAppleEatSound(gameData);
		}
	}
}