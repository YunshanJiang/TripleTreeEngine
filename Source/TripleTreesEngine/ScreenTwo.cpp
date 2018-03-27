#include "ScreenTwo.h"
#include <iostream>

ScreenTwo::ScreenTwo(GameObjectManager* gameObjectManager, PhysicsEngine* physicsEngine)
{
	m_gameObjectManager = gameObjectManager;
	m_physicsEngine = physicsEngine;
}

void ScreenTwo::Awake() {
	//Create background object
	GameObject* bg = m_gameObjectManager->CreateObject();
	SpriteRenderComponent* bgSpriteRenderer = new SpriteRenderComponent("../../Assets/Background_2.png");
	bgSpriteRenderer->sprite.setScale(700 / bgSpriteRenderer->sprite.getLocalBounds().width,
		500 / bgSpriteRenderer->sprite.getLocalBounds().height);
	bg->AddComponent(bgSpriteRenderer);



	//Create platform
	GameObject* platform = m_gameObjectManager->CreateObject();
	platform->transform.m_Position.x += 250;
	platform->transform.m_Position.y += 280;
	platform->transform.m_Scale = sf::Vector2f(0.2f, 0.2f);
	platform->AddComponent(new SpriteRenderComponent("../../Assets/Platform.png"));

	//Create doodle
	GameObject* doodle = m_gameObjectManager->CreateObject();
	platform->AddChild(doodle);
	doodle->Tag = Player;
	doodle->transform.m_Scale = sf::Vector2f(1.0f / 0.2f, 1.0f / 0.2f);
	doodle->transform.m_Position.x += 50 / 0.2f;
	doodle->transform.m_Position.y -= 80 / 0.2f;
	doodle->AddComponent(new SpriteRenderComponent("../../Assets/doodle.png"));
	AudioComponent* TestAudio = new AudioComponent("../../Assets/D.wav");
	TestAudio->PlaySound();
	doodle->AddComponent(TestAudio);

}