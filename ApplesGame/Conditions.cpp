#include "Conditions.h"

void manualExitCondition(sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		playAgain = false;
		window.close();
	}
}

void winCondition(GameState& gameData, sf::RenderWindow& window) {
	if (applesConsumed == APPLES_TO_WIN) {
		setText(gameData, victoryText);
		gameData.leaderBoardOpen = true;
		drawLeaderBoardText(leaderBoard, gameData, window);
	}
}

void loseCondition(GameState& gameData, sf::RenderWindow& window) {
	setText(gameData, gameOverText);
	playDeathSound(gameData);
	gameData.leaderBoardOpen = true;
	drawLeaderBoardText(leaderBoard, gameData, window);

}


void changeGameMode(GameState& gameData) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		gameData.gameMode = easyMode;
		setParameters(gameData);
		configureGame(gameData);
		gameData.gameModeSelected = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
		gameData.gameMode = normalMode;
		setParameters(gameData);
		configureGame(gameData);
		gameData.gameModeSelected = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
		gameData.gameMode = hardMode;
		setParameters(gameData);
		configureGame(gameData);
		gameData.gameModeSelected = true;
	}

}

void setParameters(GameState& gameData) {
	if (gameData.gameMode & gameModeSettings::appleMode20) {
		gameData.APPLES_AMOUNT = 20;
		OutputDebugStringA(("Apples set to: " + std::to_string(gameData.APPLES_AMOUNT) + "\n").c_str());
	}
	else if (gameData.gameMode & gameModeSettings::appleMode50) {
		gameData.APPLES_AMOUNT = 50;
	}

	if (gameData.gameMode & gameModeSettings::limitedApplesEnabled) {
		gameData.endlessApples = false;
	}
	if (gameData.gameMode & gameModeSettings::playerAccelerationEnabled) {
		acceleration = 3.f;
	}
}

void manualLeaderBoardOpen(GameState& gameData, sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		gameData.leaderBoardOpen = true;
		drawLeaderBoardText(leaderBoard, gameData, window);
	}
}

void playAgainCondition(GameState& gameData, sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
		playAgain = true;
		gameData.leaderBoardOpen = false;
		gameData.gameModeSelected = false;
		window.clear();
		configureGame(gameData);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
		window.close();
		playAgain = false;
	}
}

