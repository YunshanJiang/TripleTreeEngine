#include "SplashScreen.hpp"

void SplashScreen::Show(sf::RenderWindow & renderWindow) {
	sf::Image image;
	sf::Texture texture;
	if (texture.loadFromFile("../../Assets/SplashScreen.jpg") != true) {
		return;
	}

	sf::Sprite sprite(texture);
	sf::Vector2f targetSize = renderWindow.getView().getSize();
	sprite.setScale(targetSize.x/sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);
	renderWindow.draw(sprite);
	renderWindow.display();
}