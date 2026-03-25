#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <iostream>
#include <windows.h>
#include "Player.h"
#include "Apple.h"
#include "Stone.h"
#include "gameConstants.h"
#include "Support.h"
#include "Texts.h"
#include "Conditions.h"

using namespace GameConstants;

int main()
{
	while (playAgain) {
		GameState gameData;
		sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tha Game of Apples");

		configureGame(gameData);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			changeGameMode(gameData);

			playerMovement(gameData);

			checkCollistions(gameData, window);

			winCondition(gameData, window);

			manualExitCondition(window);

			setText(gameData, infoText);
			setText(gameData, scoreText);
			setText(gameData, controlInfoText);
			setText(gameData, winInfoText);
			setText(gameData, gameModesText);

			drawGame(gameData, window);
		}
	}

	return 0;
}
