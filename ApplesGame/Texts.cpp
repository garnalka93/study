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