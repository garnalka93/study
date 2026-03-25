#pragma once
#include "SFML/Graphics.hpp"
#include "gameConstants.h"
#include "Support.h"
#include <SFML/Audio.hpp>

using namespace GameConstants;

struct Apple {
	int amount;
	int size;
	sf::Sprite shape;
};

int setApples(GameState& gameData);

void checkAppleCollision(GameState& gameData);
