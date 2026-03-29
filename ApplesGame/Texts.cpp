#include "Texts.h"

int setText(GameState& gameData, textData& textData) {
	if (!gameData.font.loadFromFile("Resources\\Fonts\\Roboto-Black.ttf")) {
		OutputDebugStringA("WARNING: Issues with font!\n");
		return 0;
	}
	textData.text.setFont(gameData.font);
	textData.text.setCharacterSize(textData.size);
	textData.text.setString(textData.textString);
	textData.text.setFillColor(textData.color);
	textData.text.setPosition(textData.worldPosition.x, textData.worldPosition.y);
}

void setAllTexts(GameState& gameData) {
	setText(gameData, infoText);
	setText(gameData, scoreText);
	setText(gameData, controlInfoText);
	setText(gameData, winInfoText);
}

bool compareByScore(playerScore playerOne, playerScore playerTwo) {
	return playerOne.score > playerTwo.score;
};

void drawLeaderBoardText(std::vector<playerScore>& leaderBoard, GameState& gameData, sf::RenderWindow& window) {
	playAgainCondition(gameData, window);
	if (gameData.leaderBoardOpen) {
		std::stable_sort(leaderBoard.begin(), leaderBoard.end(), compareByScore);
		sf::Text text;
		int size = 15;
		std::string textString;
		sf::Color color = sf::Color(200, 200, 200);
		worldPosition2d leaderBoardPosition = { 500,450 };

		setText(gameData, leaderBoardHeaderText);
		setText(gameData, playAgainText);
		window.draw(text);
		int place = 0;
		for (auto& elem : leaderBoard) {
			textData tableRow = { sf::Text(), size,std::to_string(place) + ". " + elem.playerName + " -------- " + std::to_string(elem.score),color,leaderBoardPosition };

			place++;
			setText(gameData, tableRow);

			leaderBoardPosition.y += 50;
			window.draw(tableRow.text);
		}

		window.draw(victoryText.text);
		window.draw(gameOverText.text);
		window.draw(playAgainText.text);
		window.display();
	}
}