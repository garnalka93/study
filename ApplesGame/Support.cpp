#include "Support.h"
#include <SFML/Audio.hpp>
#include "SFML/Graphics.hpp"

float getRandomNumber(float min, float max) {
	static std::mt19937 gen(std::random_device{}());
	return std::uniform_real_distribution<float>{min, max}(gen);
}

void movement(worldPosition2d& playerShift, GameState& gameData) {
	float timeSinceLastMove = gameData.timer.restart().asSeconds(); // sec gone
	playerInitSpeed += acceleration * timeSinceLastMove;
	switch (playerDirection) {
	case left:
		playerShift.x = (-playerInitSpeed * timeSinceLastMove); // px * second
		gameData.playerSprite.setRotation(0);
		gameData.playerSprite.setScale(-0.05, 0.05);
		break;
	case directions::up:
		gameData.playerSprite.setRotation(-90);
		gameData.playerSprite.setScale(0.05, 0.05);
		playerShift.y = (-playerInitSpeed * timeSinceLastMove);
		break;
	case directions::down:
		gameData.playerSprite.setScale(0.05, 0.05);
		gameData.playerSprite.setRotation(90);
		playerShift.y = (playerInitSpeed * timeSinceLastMove);
		break;
	case right:
		gameData.playerSprite.setRotation(0);
		gameData.playerSprite.setScale(0.05, 0.05);
		playerShift.x = (playerInitSpeed * timeSinceLastMove);
		break;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		playerDirection = directions::up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		playerDirection = directions::down;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		playerDirection = left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		playerDirection = right;
	}
}

void drawGame(GameState& gameData, sf::RenderWindow& window) {
	scoreText.textString = "Score: " + std::to_string(applesConsumed);
	scoreText.text.setString(scoreText.textString);

	window.clear();
	window.draw(gameData.playerSprite);
	window.draw(infoText.text);
	window.draw(scoreText.text);
	window.draw(controlInfoText.text);
	window.draw(winInfoText.text);
	window.draw(gameModesText.text);

	for (int i = 0; i < gameData.apples.size(); i++) {
		window.draw(gameData.apples[i]);
	}
	for (int i = 0; i < STONES_AMOUNT; i++) {
		window.draw(gameData.stoneShape[i]);
	}

	window.display();
}

void configureGame(GameState& gameData) {
	loadAllSounds(gameData);
	setPlayer(playerStartPosition,gameData);
	setStones(gameData.stoneShape, STONES_AMOUNT, gameData.stoneTexture);
	setApples(gameData);
}