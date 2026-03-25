#pragma once
#include "gameConstants.h"
#include "Windows.h"
#include "Texts.h"
#include "Sounds.h"

using namespace GameConstants;

void manualExitCondition(sf::RenderWindow& window);

void winCondition(GameState& gameData, sf::RenderWindow& window);

void changeGameMode(GameState& gameData);

void loseCondition(GameState& gameData, sf::RenderWindow& window);

void setParameters(GameState& gameData);
