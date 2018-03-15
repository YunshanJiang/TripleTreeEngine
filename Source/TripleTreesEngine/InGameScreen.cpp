#include "InGameScreen.hpp"

void InGameScreen::Show(sf::RenderWindow & renderWindow) {
	sf::Image image;
	sf::Texture texture;
	if (texture.loadFromFile("../../Assets/background.jpg") != true) {
		return;
	}

	sf::Sprite sprite(texture);
	sf::Vector2f targetSize = renderWindow.getView().getSize();
	sprite.setScale(targetSize.x / sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);
	renderWindow.clear();
	renderWindow.draw(sprite);
	renderWindow.display();
}