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
	doodle->transform.m_Position.x += 100;
	doodle->transform.m_Position.y += 100;
	doodle->Tag = Player;
	doodle->AddComponent(new SpriteRenderComponent("../../Assets/doodle.png"));
	RigidbodyComponent* doodle_rb = new RigidbodyComponent(doodle,m_physicsEngine);
	doodle_rb->bounciness = 0.8f;
	doodle->AddComponent(doodle_rb);
	AudioComponent* TestAudio = new AudioComponent("../../Assets/D.wav");
	TestAudio->PlaySound();
	doodle->AddComponent(TestAudio);

	//Create platform
	GameObject* platform = m_gameObjectManager->CreateObject();
	platform->transform.m_Position.x += 50;
	platform->transform.m_Position.y += 400;
	platform->transform.m_Scale = sf::Vector2f(0.2f, 0.2f);

	platform->AddComponent(new SpriteRenderComponent("../../Assets/Platform.png"));
	RigidbodyComponent* platform_rb = new RigidbodyComponent(platform, m_physicsEngine);
	platform_rb->obeysGravity = false;
	platform_rb->mass = 0;
	platform_rb->bounciness = 1.0f;
	platform->AddComponent(platform_rb);


	/*
	//Create doodle 2&3
	GameObject* doodle2 = m_gameObjectManager->CreateObject();
	doodle2->transform.m_Position.x += 400;
	doodle2->transform.m_Position.y += 100;
	doodle2->AddComponent(new SpriteRenderComponent("../../Assets/doodle.png"));
	RigidbodyComponent* doodle_rb2 = new RigidbodyComponent(doodle2, m_physicsEngine);
	doodle_rb2->bounciness = 0.5f;
	doodle2->AddComponent(doodle_rb2);

	GameObject* doodle3 = m_gameObjectManager->CreateObject();
	doodle3->transform.m_Position.x += 400;
	doodle3->transform.m_Position.y += 300;
	doodle3->AddComponent(new SpriteRenderComponent("../../Assets/doodle.png"));
	RigidbodyComponent* doodle_rb3 = new RigidbodyComponent(doodle3, m_physicsEngine);
	doodle_rb3->bounciness = 0.5f;
	doodle3->AddComponent(doodle_rb2);

	//Create platform
	GameObject* platform2 = m_gameObjectManager->CreateObject();
	platform2->transform.m_Position.x += 350;
	platform2->transform.m_Position.y += 400;
	platform2->transform.m_Scale = sf::Vector2f(0.2f, 0.2f);

	platform2->AddComponent(new SpriteRenderComponent("../../Assets/Platform.png"));
	RigidbodyComponent* platform_rb2 = new RigidbodyComponent(platform2, m_physicsEngine);
	platform_rb2->obeysGravity = false;
	platform_rb2->mass = 0;
	platform_rb2->bounciness = 1.0f;
	platform2->AddComponent(platform_rb);
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
