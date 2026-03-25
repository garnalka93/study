#include "Stone.h"
#include "Texts.h"
#include "Conditions.h"

using namespace GameConstants; 

int setStones(sf::Sprite* stoneSprite, int STONES_AMOUNT, sf::Texture& stoneTexture) {
	if (!stoneTexture.loadFromFile("Resources\\Rock.png")) {
		OutputDebugStringA("WARNING: Issues with player texture!\n");
		return -1;
	};
	for (int i = 0; i < STONES_AMOUNT; i++) {
		stoneSprite[i].setTexture(stoneTexture);
		stoneSprite[i].setOrigin(STONE_SIZE / 2.f, STONE_SIZE / 2.f);
		stoneSprite[i].setPosition(getRandomNumber(0, SCREEN_WIDTH), getRandomNumber(0, SCREEN_HEIGHT));
		stoneSprite[i].setScale(0.1, 0.1);
	}
}

void checkStoneCollision(GameState& gameData, sf::RenderWindow& window) {
	for (int i = 0; i < STONES_AMOUNT; i++) {
		sf::FloatRect stoneBounds = gameData.stoneShape[i].getGlobalBounds();
		sf::FloatRect playerBounds = gameData.playerSprite.getGlobalBounds();
		if (playerBounds.intersects(stoneBounds)) {
			loseCondition(gameData, window);
		}
	}
}

