#pragma once
#include "gameConstants.h"
#include <windows.h>
#include "Player.h"

int setText(GameState& gameData, textData& textData);

void setAllTexts(GameState& gameData);

void drawLeaderBoardText(std::vector<playerScore>& leaderBoard, GameState& gameData, sf::RenderWindow& window);
