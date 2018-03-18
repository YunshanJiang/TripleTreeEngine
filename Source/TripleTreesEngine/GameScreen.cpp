#include "GameScreen.h"
#include <iostream>

GameScreen::GameScreen()
{
	GameObject* obj = m_gameObjectManager.CreateObject();
	obj->AddComponent(new SpriteRenderComponent("../../Assets/doodle.png"));
}

void GameScreen::Awake() {
	
}

void GameScreen::Start() {

}

void GameScreen::Update(float delta) {
	
}
void GameScreen::LateUpdate(float delta) {

}

void GameScreen::Render(sf::RenderWindow& window) {
	//Background
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

	for (std::map<int, GameObject*>::iterator i = m_gameObjectManager.m_Objects.begin(); i != m_gameObjectManager.m_Objects.end(); ++i) {
		for (std::vector<BaseComponent*>::iterator j = (i->second)->m_Components.begin(); j != (i->second)->m_Components.end(); ++j) {
			if (SpriteRenderComponent* r = dynamic_cast<SpriteRenderComponent*>((*j))) {
				r->Render(window);
			}
		}
	}

	window.display();
}
