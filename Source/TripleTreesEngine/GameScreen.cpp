#include "GameScreen.h"
#include <iostream>
#include "PhysicsRBody.hpp"

GameScreen::GameScreen(GameObjectManager* gameObjectManager, PhysicsEngine* physicsEngine)
{
	m_gameObjectManager = gameObjectManager;
	m_physicsEngine = physicsEngine;
}

void GameScreen::Awake() {
	//Create background object
	GameObject* bg = m_gameObjectManager->CreateObject();
	SpriteRenderComponent* bgSpriteRenderer = new SpriteRenderComponent("../../Assets/background.jpg");
	bgSpriteRenderer->sprite.setScale(700 / bgSpriteRenderer->sprite.getLocalBounds().width,
		500 / bgSpriteRenderer->sprite.getLocalBounds().height);
	bg->AddComponent(bgSpriteRenderer);

	//Create doodle
	GameObject* obj = m_gameObjectManager->CreateObject();
	obj->AddComponent(new SpriteRenderComponent("../../Assets/doodle.png"));
	PhysicsRBody* obj_Rb = new PhysicsRBody(obj,m_physicsEngine);
	obj->AddComponent(obj_Rb);
	
	/*
	GameObject* child = m_gameObjectManager->CreateObject();
	child->AddComponent(new SpriteRenderComponent("../../Assets/doodle.png"));
	child->transform.m_Position.y = 100;
	obj->AddChild(child);
	obj->transform.m_Position.x = 300;
	obj->transform.m_Position.y = 100;
	*/

}










/*
void GameScreen::Start() {

}

void GameScreen::Update(sf::Time time) {
	a += 0.01 * time.asSeconds();
	obj->transform.m_Position.x = 100;
	obj->transform.m_Position.y = 100;
	followobj->transform.m_Position.x = 0;
	followobj->transform.m_Position.y = 0;
	followobj->transform.m_Position.x += sin(a) * 20;
	followobj->transform.m_Position.y += cos(a) * 20;
	followobjs->transform.m_Position.x = 0;
	followobjs->transform.m_Position.y = 0;
	followobjs->transform.m_Position.x += cos(a) * 20;
	followobjs->transform.m_Position.y += sin(a) * 20;
}
void GameScreen::LateUpdate(sf::Time time) {
	
}

void GameScreen::Render(sf::RenderWindow& window) {
	window.clear();
	for (std::map<int, GameObject*>::iterator i = m_gameObjectManager->m_Objects.begin(); i != m_gameObjectManager->m_Objects.end(); ++i) {
		for (std::vector<BaseComponent*>::iterator j = (i->second)->m_Components.begin(); j != (i->second)->m_Components.end(); ++j) {
			if (SpriteRenderComponent* r = dynamic_cast<SpriteRenderComponent*>((*j))) {
				
				r->Render(window, i->second);
				
			}
		}
	}
	window.display();
}
*/
