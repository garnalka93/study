#include "gameConstants.h"
#include "Sounds.h"

namespace GameConstants {

bool playAgain = true;

int playerDirection = right;
float playerInitSpeed = 100.f;

float acceleration = 1.f;
int applesConsumed = 0;

std::string victoryState = "unknown";

worldPosition2d playerStartPosition = { SCREEN_WIDTH / 2.f ,SCREEN_HEIGHT / 2.f };

worldPosition2d playerShift = { 0,0 };

uint8_t easyMode = gameModeSettings::appleMode20;
uint8_t normalMode = gameModeSettings::appleMode20 | gameModeSettings::playerAccelerationEnabled;
uint8_t hardMode = gameModeSettings::appleMode50 | gameModeSettings::playerAccelerationEnabled | gameModeSettings::limitedApplesEnabled;

textData infoText = { sf::Text(), 20, "Press 'Esc' or 'c' to exit.", sf::Color(200, 200, 200), {10,10} };
textData scoreText = { sf::Text(), 45, "Score: 0", sf::Color(0, 255, 0), {10,60}};
textData controlInfoText = { sf::Text(), 15, "Use W/A/S/D to control player.", sf::Color(255, 255, 255), {1000,10}};
textData victoryText = { sf::Text(), 100, "You Won!", sf::Color(0, 255, 0), {(SCREEN_WIDTH / 2.f) - 200, (SCREEN_HEIGHT / 2.f) - 100 } };
textData gameOverText = { sf::Text(), 100, "You Lost!", sf::Color(255, 0, 0), {(SCREEN_WIDTH / 2.f) - 200, (SCREEN_HEIGHT / 2.f) - 100 } };
textData winInfoText = { sf::Text(), 20, "Gather " + std::to_string(APPLES_TO_WIN) + " apples to win.", sf::Color(65, 105, 225), {1000,35} };
textData gameModesText = { sf::Text(), 15, "Press 1/2/3 to change game mode.", sf::Color(200, 200, 200), {10,30} };
}