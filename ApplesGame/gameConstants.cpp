#include "gameConstants.h"
#include "Sounds.h"

bool playAgain = true;

int playerDirection = right;
float playerInitSpeed = 100.f;

float acceleration = 1.f;
int applesConsumed = 0;

std::vector<playerScore> leaderBoard = {
	{"Sam Altman", 12},
	{"John Romero", 30},
	{"Phil Spencer", 3},
	{"Ben Brode", 1},
	{"Sven Vinckie", 42},
	{"Bobbie K-tick", 4},
	{"D Vavra", 7},
	{ "!ItsMe!", 0 }
};

std::string victoryState = "unknown";

worldPosition2d playerStartPosition = { SCREEN_WIDTH / 2.f ,SCREEN_HEIGHT / 2.f };

worldPosition2d playerShift = { 0,0 };
worldPosition2d screenCenter = { (SCREEN_WIDTH / 2.f) - 200, (SCREEN_HEIGHT / 2.f) - 100 };

uint8_t easyMode = gameModeSettings::appleMode20;
uint8_t normalMode = gameModeSettings::appleMode20 | gameModeSettings::playerAccelerationEnabled;
uint8_t hardMode = gameModeSettings::appleMode50 | gameModeSettings::playerAccelerationEnabled | gameModeSettings::limitedApplesEnabled;

textData infoText = { sf::Text(), 20, "Press 'Esc' or 'c' to exit.", sf::Color(200, 200, 200), {10,10} };
textData scoreText = { sf::Text(), 45, "Score: 0", sf::Color(0, 255, 0), {10,60} };
textData controlInfoText = { sf::Text(), 15, "Use W/A/S/D to control player.", sf::Color(255, 255, 255), {1000,10} };
textData victoryText = { sf::Text(), 100, "You Won!", sf::Color(0, 255, 0), {screenCenter.x - 50, screenCenter.y - 200 } };
textData playAgainText = { sf::Text(), 35, "Press 'Y' to play again or 'N' to exit the game!",sf::Color(255, 255, 0),{screenCenter.x - 160, screenCenter.y - 80 } };
textData gameOverText = { sf::Text(), 100, "You Lost!", sf::Color(255, 0, 0), {screenCenter.x - 50, screenCenter.y - 200 } };
textData winInfoText = { sf::Text(), 20, "Gather " + std::to_string(APPLES_TO_WIN) + " apples to win.", sf::Color(65, 105, 225), {1000,35} };
textData gameModesHeaderText = { sf::Text(), 50, "Select game mode. (Use 1,2,3 buttons)", sf::Color(200, 200, 200), {screenCenter.x - 200, screenCenter.y - 200} };
textData gameModesInfoText = { sf::Text(), 20, " 1. 20 apples\n 2. 20 apples and player acceleration enabled\n 3. 50 apples, player acceleration enabled and apples are limited.", sf::Color(200, 200, 200), {screenCenter.x - 50, screenCenter.y - 100} };
textData leaderBoardHeaderText = { sf::Text(), 40, "*** Leader Board ***" , sf::Color(200, 200, 200) , {400, 400} };
