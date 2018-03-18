#include "GameScreen.h"
#include <iostream>
void GameScreen::Awake() {
	std::cout << "aaa";
}

void GameScreen::Start() {

}

void GameScreen::Update(float delta) {
	
}
void GameScreen::LateUpdate(float delta) {

}

void GameScreen::Render(sf::RenderWindow& window) {
	sf::Image image;
	sf::Texture texture;
	if (texture.loadFromFile("../../Assets/background.jpg") != true) {
		return;
	}

	sf::Sprite sprite(texture);
	sf::Vector2f targetSize = window.getView().getSize();
	sprite.setScale(targetSize.x / sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);
	window.clear();
	window.draw(sprite);
	window.display();
}
