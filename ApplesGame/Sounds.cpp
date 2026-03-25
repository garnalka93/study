#include "Sounds.h"

using namespace GameConstants;

int loadAllSounds(GameState& gameData) {
	if (!gameData.bufferForAppleSound.loadFromFile("Resources\\AppleEat.wav")) {
		return -1;
	};

	if (!gameData.bufferForDeathSound.loadFromFile("Resources\\Death.wav")) {
		return -1;
	}

	gameData.appleEatSound.setBuffer(gameData.bufferForAppleSound);
	gameData.deathSound.setBuffer(gameData.bufferForDeathSound);
}

void playAppleEatSound(GameState& gameData) {
	gameData.appleEatSound.setVolume(100.f);
	gameData.appleEatSound.play();
}

void playDeathSound(GameState& gameData) {
	gameData.deathSound.setVolume(100.f);
	gameData.deathSound.play();
}