#pragma once
#include "SFML/Graphics.hpp"
#include "gameConstants.h"
#include "Stone.h"
#include "Apple.h"
#include "Support.h"
#include <windows.h>
#include "Sounds.h"
#include "Texts.h"
#include "Conditions.h"

typedef worldPosition2d Vector2D;
using worldPosition2D = worldPosition2d;

int setPlayer(worldPosition2d playerStartPosition, GameState& gameData);

void playerMovement(GameState& gameData);

void checkhWallCollision(GameState& gameData, sf::Vector2f playerPosition, sf::RenderWindow& window);

void checkCollistions(GameState& gameData, sf::RenderWindow& window);

void setPlayerScore(int applesConsumed, std::string playerName, std::vector<playerScore>& leaderBoard);