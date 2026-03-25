#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <windows.h>

const std::string RESOURCES_PATH = "Resources/";
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 1024;
float playerInitSpeed = 100.f; // amount of px
const int PLAYER_SIZE = 15;
const int APPLE_SIZE = 16;
const int STONE_SIZE = 25;
float acceleration = 1.f;
const int APPLES_AMOUNT = 15;
const int STONES_AMOUNT = 5;
bool playAgain = true;
float playerXCoordinate = SCREEN_WIDTH / 2.f;
float playerYCoordinate = SCREEN_HEIGHT / 2.f;
int applesConsumed = 0;

int getRandomNumber(int min, int max) {
	static std::mt19937 gen(std::random_device{}());
	return std::uniform_int_distribution<>{min, max}(gen);
}

void setPlayer(sf::RectangleShape& player, float playerX, float playerY) {
	player.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
	player.setFillColor(sf::Color::Blue);
	player.setOrigin(PLAYER_SIZE / 2.f, PLAYER_SIZE / 2.f);
	player.setPosition(playerX, playerY);
}

void checkhWallCollision(sf::Vector2f playerPosition, sf::RenderWindow& window) {
	if (playerPosition.x > SCREEN_WIDTH || playerPosition.x < 0 || playerPosition.y < 0 || playerPosition.y > SCREEN_HEIGHT) {
		window.close();
		Sleep(5000);
	}

}

void setStones(sf::CircleShape* stones, int STONES_AMOUNT) {
	for (int i = 0; i < STONES_AMOUNT; i++) {
		stones[i].setRadius(STONE_SIZE / 2);
		stones[i].setFillColor(sf::Color::Red);
		stones[i].setOrigin(STONE_SIZE / 2.f, STONE_SIZE / 2.f);
		stones[i].setPosition(getRandomNumber(0, SCREEN_WIDTH), getRandomNumber(0, SCREEN_HEIGHT));
	}
}

void setApples(sf::CircleShape* apples, int APPLES_AMOUNT) {
	for (int i = 0; i < APPLES_AMOUNT; i++) {
		apples[i].setRadius(APPLE_SIZE / 2);
		apples[i].setFillColor(sf::Color::Yellow);
		apples[i].setOrigin(APPLE_SIZE / 2.f, APPLE_SIZE / 2.f);
		apples[i].setPosition(getRandomNumber(0, SCREEN_WIDTH), getRandomNumber(0, SCREEN_HEIGHT));

		for (int c = 0; c < i; c++) {
			if (apples[i].getPosition() == apples[c].getPosition()) {
				apples[i].setPosition(getRandomNumber(0, SCREEN_WIDTH), getRandomNumber(0, SCREEN_HEIGHT));
				i--;
				break;
			}
		}
	}
}

struct AppleObject {
	sf::CircleShape apple;
	bool wasEaten = false;
};

void checkAppleCollision(sf::RectangleShape playerShape, std::vector<sf::CircleShape>& newApplesArray) {
	for (int i = 0; i < newApplesArray.size(); i++) {
		sf::FloatRect appleBounds = newApplesArray[i].getGlobalBounds();
		sf::FloatRect playerBounds = playerShape.getGlobalBounds();
		if (playerBounds.intersects(appleBounds)) {
			newApplesArray[i].setPosition(getRandomNumber(0, SCREEN_WIDTH), getRandomNumber(0, SCREEN_HEIGHT));
			i--;
			applesConsumed += 1;
		}
	}
}
void checkStoneCollision(sf::RectangleShape player, sf::CircleShape stone[], sf::RenderWindow& window) {
	for (int i = 0; i < STONES_AMOUNT; i++) {
		float xCalculation = (player.getPosition().x - stone[i].getPosition().x) * (player.getPosition().x - stone[i].getPosition().x);
		float yCalculation = (player.getPosition().y - stone[i].getPosition().y) * (player.getPosition().y - stone[i].getPosition().y);
		float radiusCalculation = ((player.getSize().x / 2) + stone[i].getRadius()) * ((player.getSize().x / 2) + stone[i].getRadius());
		if (xCalculation+yCalculation <= radiusCalculation) {
			window.close();
			playAgain = false;
		}
	}
}

void setText(sf::Text& text, float positionX, float postionY) {
	text.setFillColor(sf::Color::White);
	text.setPosition(positionX, postionY);
}


int main()
{
	while (playAgain) {
		int playerDirection = 0; // 0-right, 1-left, 2-up, 3-down
		sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tha Game of Apples");
		sf::RectangleShape playerShape;

		sf::CircleShape apples[APPLES_AMOUNT];
		sf::CircleShape stoneShape[STONES_AMOUNT];

		sf::Font font;
		font.loadFromFile("Resources\\Fonts\\Roboto-Black.ttf");

		sf::Text infoText("Press 'Esc' or 'c' to exit.", font, 15);

		char buffer[MAX_PATH];

		// Получаем текущую директорию
		DWORD length = GetCurrentDirectoryA(MAX_PATH, buffer);

		if (length > 0 && length < MAX_PATH) {
			std::string message = "Program started from: ";
			message += buffer;
			message += "\n";

			// Вывод в окно Output
			OutputDebugStringA(message.c_str());
		}
		else {
			OutputDebugStringA("Failed to get current directory\n");
		}

		setPlayer(playerShape, playerXCoordinate, playerYCoordinate);
		setText(infoText, 10, 10);
		setStones(stoneShape, STONES_AMOUNT);

		sf::Clock timer;
		setApples(apples, APPLES_AMOUNT);
		std::vector<sf::CircleShape> newApplesArray(apples, apples + APPLES_AMOUNT);


		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			float timeSinceLastMove = timer.restart().asSeconds(); // sec gone
			sf::Vector2f playerPosition = playerShape.getPosition();

			float shiftPlayerByY = 0;
			float shiftPlayerByX = 0;

			//acceleration *=timeSinceLastMove;
			playerInitSpeed += acceleration * timeSinceLastMove;

			switch (playerDirection) {
			case 1:
				shiftPlayerByX = (-playerInitSpeed * timeSinceLastMove); // px * second
				break;
			case 2:
				shiftPlayerByY = (-playerInitSpeed * timeSinceLastMove);
				break;
			case 3:
				shiftPlayerByY = (playerInitSpeed * timeSinceLastMove);
				break;
			case 0:
				shiftPlayerByX = (playerInitSpeed * timeSinceLastMove);
				break;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				playerDirection = 2;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				playerDirection = 3;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				playerDirection = 1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				playerDirection = 0;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				playAgain = false;
				window.close();
			}

			checkhWallCollision(playerPosition, window);
			checkStoneCollision(playerShape, stoneShape, window);

			checkAppleCollision(playerShape, newApplesArray);

			//win Condition
			if (applesConsumed == newApplesArray.size()) {
				window.close();
			}

			sf::Text scoreText("Score: " + std::to_string(applesConsumed), font, 40);
			setText(scoreText, 10, 30);

			window.clear();
			playerShape.move(shiftPlayerByX, shiftPlayerByY);//if replace with SetPosition ->need to change shift for  new exact XY positions
			window.draw(playerShape);
			window.draw(infoText);
			window.draw(scoreText); // is not working if move to line 205

			// draw all apples (taking into accout new places)
			for (int i = 0; i < newApplesArray.size(); i++) {
				window.draw(newApplesArray[i]);
			}
			//draw all stones
			for (int i = 0; i < STONES_AMOUNT; i++) {
				window.draw(stoneShape[i]);
			}

			window.display();
		}
	}
	return 0;
}
