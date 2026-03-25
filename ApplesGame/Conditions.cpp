#include "Conditions.h"
#include "Support.h"

void manualExitCondition(sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		playAgain = false;
		window.close();
	}
}

void winCondition(GameState& gameData, sf::RenderWindow& window) {
	if (applesConsumed == APPLES_TO_WIN) {
		playAgain = false;
		setText(gameData, victoryText);
		window.draw(victoryText.text);
		window.display();
		Sleep(5000);
		window.close();
	}
}

void loseCondition(GameState& gameData, sf::RenderWindow& window) {
	setText(gameData, gameOverText);
	window.draw(gameOverText.text);
	playDeathSound(gameData);
	window.display();
	Sleep(5000);
	window.close();
	playAgain = false;
}


void changeGameMode(GameState& gameData) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		gameData.gameMode = easyMode;
		setParameters(gameData);
		configureGame(gameData);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
		gameData.gameMode = normalMode;
		setParameters(gameData);
		configureGame(gameData);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
		gameData.gameMode = hardMode;
		setParameters(gameData);
		configureGame(gameData);
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