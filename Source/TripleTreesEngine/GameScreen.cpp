#include "GameScreen.h"
#include <iostream>

GameScreen::GameScreen(GameObjectManager* gameObjectManager)
{
	m_gameObjectManager = gameObjectManager;

	//Create background object
	GameObject* bg = m_gameObjectManager->CreateObject();
	SpriteRenderComponent* bgSpriteRenderer = new SpriteRenderComponent("../../Assets/background.jpg");
	bgSpriteRenderer->sprite.setScale(700 / bgSpriteRenderer->sprite.getLocalBounds().width,
		500 / bgSpriteRenderer->sprite.getLocalBounds().height);
	bg->AddComponent(bgSpriteRenderer);

	//Create doodle object
	GameObject* obj = m_gameObjectManager->CreateObject();
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
	window.clear();
	for (std::map<int, GameObject*>::iterator i = m_gameObjectManager->m_Objects.begin(); i != m_gameObjectManager->m_Objects.end(); ++i) {
		for (std::vector<BaseComponent*>::iterator j = (i->second)->m_Components.begin(); j != (i->second)->m_Components.end(); ++j) {
			if (SpriteRenderComponent* r = dynamic_cast<SpriteRenderComponent*>((*j))) {
				r->Render(window);
			}
		}
	}
	window.display();
}
