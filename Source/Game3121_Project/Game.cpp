
#include "Game.hpp"

Game::Game() :
	mWindow(sf::VideoMode(200, 200), "SFML works!")
	, mPlayer()

{
	mPlayer.setFillColor(sf::Color::Green);
	mPlayer.setRadius(100.f);
	mPlayer.setPosition(0.f, 0.f);
}
void Game::processEvents() {

	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}
void Game::render() {
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}
void Game::run() {
	while (mWindow.isOpen()) {
		processEvents();
		render();
	}
}