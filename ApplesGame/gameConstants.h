#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Windows.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 1024;
const int PLAYER_SIZE = 15;
const int APPLE_SIZE = 16;
const int STONE_SIZE = 25;
const int STONES_AMOUNT = 10;
const int APPLES_TO_WIN = 5;

extern bool playAgain;
extern std::string victoryState;

enum directions { // numbers hidden behind the names
	right = 0,
	left = 1,
	up,
	down
};

extern struct worldPosition2d {
	float x;
	float y;
};
extern worldPosition2d playerStartPosition;
extern worldPosition2d playerShift;
extern worldPosition2d screenCenter;

extern uint8_t easyMode;
extern uint8_t normalMode;
extern uint8_t hardMode;

enum gameModeSettings : uint8_t {
	playerAccelerationEnabled = 1 << 0,
	limitedApplesEnabled = 1 << 1,
	appleMode20 = 1 << 2,
	appleMode50 = 1 << 3,
	stoneMode10 = 1 << 4,
	stoneMode5 = 1 << 5
};

struct playerScore {
	std::string playerName;
	int score;
};

extern std::vector<playerScore> leaderBoard;

//namespace Sounds { // not working
//	extern sf::SoundBuffer bufferForAppleSound;
//	extern sf::Sound appleEatSound;

//	extern sf::SoundBuffer bufferForDeathSound;
//	extern sf::Sound deathSound;
//}

struct GameState {
	std::vector<sf::Sprite> apples;
	sf::Sprite stoneShape[STONES_AMOUNT];

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	sf::Texture appleTexture;

	sf::Texture stoneTexture;
	sf::Sprite stoneSprite;

	sf::Clock timer;

	std::vector<sf::Sprite> applesShape;

	sf::Font font;
	std::string textString;
	uint8_t gameMode;


	sf::SoundBuffer bufferForAppleSound;
	sf::Sound appleEatSound;

	sf::SoundBuffer bufferForDeathSound;
	sf::Sound deathSound;

	int APPLES_AMOUNT = 10;
	bool endlessApples = true;
	bool gameModeSelected = false;
	bool leaderBoardOpen = false;
};

extern struct textData {
	sf::Text text;
	int size;
	std::string textString;
	sf::Color color;
	worldPosition2d worldPosition;
};

extern textData infoText;
extern textData scoreText;
extern textData controlInfoText;
extern textData victoryText;
extern textData gameOverText;
extern textData winInfoText;
extern textData playAgainText;
extern textData gameModesHeaderText;
extern textData gameModesInfoText;
extern textData leaderBoardHeaderText;

extern int playerDirection;
extern float playerInitSpeed;

extern float acceleration;

extern int applesConsumed;
