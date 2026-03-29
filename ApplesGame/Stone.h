#pragma once
#include <SFML/Graphics.hpp>
#include "Windows.h"
#include "gameConstants.h"
#include "Support.h"
#include "Sounds.h"
#include "Texts.h"
#include "Conditions.h"

int setStones(sf::Sprite* stoneSprite, int STONES_AMOUNT, sf::Texture& stoneTexture);

void checkStoneCollision(GameState& gameData, sf::RenderWindow& window);