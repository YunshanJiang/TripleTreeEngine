#include "GameScreen.h"
#include <iostream>

GameScreen::GameScreen(GameObjectManager* gameObjectManager, PhysicsEngine* physicsEngine)
{
	m_gameObjectManager = gameObjectManager;
	m_physicsEngine = physicsEngine;
}

void GameScreen::Awake() {
	//Create background object
	GameObject* bg = m_gameObjectManager->CreateObject();
	SpriteRenderComponent* bgSpriteRenderer = new SpriteRenderComponent("../../Assets/Background_2.png");
	bgSpriteRenderer->sprite.setScale(700 / bgSpriteRenderer->sprite.getLocalBounds().width,
		500 / bgSpriteRenderer->sprite.getLocalBounds().height);
	bg->AddComponent(bgSpriteRenderer);
	

	//Create doodle
	GameObject* doodle = m_gameObjectManager->CreateObject();
	doodle->transform.m_Position.x += 300;
	doodle->transform.m_Position.y += 100;

	doodle->AddComponent(new SpriteRenderComponent("../../Assets/doodle.png"));
	RigidbodyComponent* doodle_rb = new RigidbodyComponent(doodle,m_physicsEngine);
	doodle->AddComponent(doodle_rb);

	//Create platform
	GameObject* platform = m_gameObjectManager->CreateObject();
	platform->transform.m_Position.x += 250;
	platform->transform.m_Position.y += 400;
	platform->transform.m_Scale = sf::Vector2f(0.2f, 0.2f);

	platform->AddComponent(new SpriteRenderComponent("../../Assets/Platform.png"));
	RigidbodyComponent* platform_rb = new RigidbodyComponent(platform, m_physicsEngine);
	platform_rb->obeysGravity = false;
	platform->AddComponent(platform_rb);
	






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
