#pragma once
#include "gameConstants.h"
#include "Windows.h"
#include "Texts.h"
#include "Sounds.h"
#include "Support.h"

void manualExitCondition(sf::RenderWindow& window);

void winCondition(GameState& gameData, sf::RenderWindow& window);

void changeGameMode(GameState& gameData);

void loseCondition(GameState& gameData, sf::RenderWindow& window);

void setParameters(GameState& gameData);

void manualLeaderBoardOpen(GameState& gameData, sf::RenderWindow& window);

void playAgainCondition(GameState& gameData, sf::RenderWindow& window);
