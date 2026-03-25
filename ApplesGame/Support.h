#pragma once
#include "gameConstants.h"
#include "Player.h"
#include "Stone.h"
#include "Apple.h"
#include "Windows.h"
#include <random>
#include "SFML/Graphics.hpp"

using namespace GameConstants;

float getRandomNumber(float min, float max);

void movement(worldPosition2d& playerShift, GameState& gameData);

void drawGame(GameState& gameData, sf::RenderWindow& window);

void configureGame(GameState& gameData);