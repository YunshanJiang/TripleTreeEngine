#pragma once

#include <SFML/Graphics.hpp>
class Game : private sf::NonCopyable {
private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	void processEvents();
	void render();
public:
	Game();
	void run();
};