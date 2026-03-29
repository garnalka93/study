#include "Player.h"

int setPlayer(worldPosition2d playerStartPosition, GameState& gameData) {
	playerInitSpeed = 100.f;
	playerDirection = right;

	if (!gameData.playerTexture.loadFromFile("Resources\\Player.png")) {
		OutputDebugStringA("WARNING: Issues with player texture!\n");
		return -1;
	};
	gameData.playerSprite.setTexture(gameData.playerTexture);
	gameData.playerSprite.scale(0.05, 0.05);
	gameData.playerSprite.setOrigin(gameData.playerSprite.getLocalBounds().width / 2, gameData.playerSprite.getLocalBounds().height / 2);
	gameData.playerSprite.setPosition(playerStartPosition.x, playerStartPosition.y);
};

void playerMovement(GameState& gameData) {
	worldPosition2d playerShift = { 0,0 };

	movement(playerShift, gameData);
	gameData.playerSprite.move(playerShift.x, playerShift.y);
}

void checkhWallCollision(GameState& gameData, sf::Vector2f playerPosition, sf::RenderWindow& window) {
	if (playerPosition.x > SCREEN_WIDTH || playerPosition.x < 0 || playerPosition.y < 0 || playerPosition.y > SCREEN_HEIGHT) {
		loseCondition(gameData, window);
	}
}

void checkCollistions(GameState& gameData, sf::RenderWindow& window) {
	sf::Vector2f playerPosition = gameData.playerSprite.getPosition();

	checkhWallCollision(gameData, playerPosition, window);
	checkStoneCollision(gameData, window);
	checkAppleCollision(gameData);
}


void setPlayerScore(int applesConsumed, std::string playerName, std::vector<playerScore>& leaderBoard) {
	//leaderBoard.resize(leaderBoard.size()+1, {"user",0});
	leaderBoard.at(leaderBoard.size() - 1) = { playerName, applesConsumed }; // how to fix rewriting?
	//leaderBoard.insert(leaderBoard.end(), { playerName, applesConsumed});
}