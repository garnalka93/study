#pragma once
#include "SFML/Graphics.hpp"
#include "gameConstants.h"
#include "Support.h"
#include <SFML/Audio.hpp>
#include "Sounds.h"

int setApples(GameState& gameData);

void checkAppleCollision(GameState& gameData);
