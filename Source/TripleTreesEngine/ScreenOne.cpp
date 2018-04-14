#include "ScreenOne.h"
#include <iostream>

ScreenOne::ScreenOne(GameObjectManager* gameObjectManager, PhysicsEngine* physicsEngine)
{
	m_gameObjectManager = gameObjectManager;
	m_physicsEngine = physicsEngine;
}

void ScreenOne::Awake() {
	//Create background object
	GameObject* bg = m_gameObjectManager->CreateObject();
	SpriteRenderComponent* bgSpriteRenderer = new SpriteRenderComponent("../../Assets/Background_2.png");
	bgSpriteRenderer->sprite.setScale(700 / bgSpriteRenderer->sprite.getLocalBounds().width,
		500 / bgSpriteRenderer->sprite.getLocalBounds().height);
	bg->AddComponent(bgSpriteRenderer);


	XMLDocument doc;
	 doc.LoadFile("../../Assets/player.xml");
	
		const char* textxml = doc.FirstChildElement("player")->GetText();

		std::cout << textxml << std::endl;
	
	
	
	//Create platform
	GameObject* platform = m_gameObjectManager->CreateObject();
	platform->Tag = Player;
	platform->transform.m_Position.x += 250;
	platform->transform.m_Position.y += 280;
	platform->transform.m_Scale = sf::Vector2f(0.2f, 0.2f);
	platform->AddComponent(new SpriteRenderComponent("../../Assets/Platform.png"));

	//Create doodle
	GameObject* doodle = m_gameObjectManager->CreateObject();
	platform->AddChild(doodle);
	doodle->transform.m_Scale = sf::Vector2f(1.0f / 0.2f, 1.0f / 0.2f);
	doodle->transform.m_Position.x += 50/0.2f;
	doodle->transform.m_Position.y -= 80/0.2f;
	doodle->AddComponent(new SpriteRenderComponent("../../Assets/doodle.png"));
	AudioComponent* TestAudio = new AudioComponent("../../Assets/D.wav");
	TestAudio->PlaySound();
	doodle->AddComponent(TestAudio);

}