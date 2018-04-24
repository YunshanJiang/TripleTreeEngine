#include "ScreenOne.h"
#include <iostream>

ScreenOne::ScreenOne(GameObjectManager* gameObjectManager, PhysicsEngine* physicsEngine)
{
	m_gameObjectManager = gameObjectManager;
	m_physicsEngine = physicsEngine;
}

void ScreenOne::Awake(Input* input) {
	baseinput = input;
	loadedscreen = false;
	block.clear();
	background.clear();
	thecolck.restart();
	spawnClock.restart();
	srand(time(0));
	for (std::map<int, GameObject*>::iterator i = m_gameObjectManager->m_Objects.begin(); i != m_gameObjectManager->m_Objects.end(); ++i) {
		//std::cout << i->second->Tag << std::endl;
		if (i->second->Tag == Default) {
			background.push_back(i->second);
			
		}
		if (i->second->Tag == Block)
		{
			block.push_back(i->second);
			i->second->transform.m_Position.x = rand() % 800 + 700;

		}
		if (i->second->Tag == Player)
		{
			player = i->second;
		}
		if (i->second->Tag == LifeText)
		{
			lifetext = i->second;
		}
		if (i->second->Tag == TimerText)
		{
			timertext = i->second;
		}
	
	}

}

void ScreenOne::Update(sf::Time  time) {
	if (loadedscreen == false) {
		
		timer = thecolck.getElapsedTime().asSeconds();  //update the timer
		lifetext->GetTextRenderComponent()->text.setString("life: " + std::to_string(player->health)); // life ui
		timertext->GetTextRenderComponent()->text.setString("Time: " + std::to_string(timer)); // timer ui
		//the background scroll
		for (std::vector<GameObject*>::iterator j = background.begin(); j != background.end(); ++j) {
			GameObject* temp = *j;
			temp->transform.m_Position.x -= 0.3f*time.asSeconds();
			if (temp->transform.m_Position.x < -699)
			{
				temp->transform.m_Position.x = 699;
			}
		}

		
		//the rock
		for (std::vector<GameObject*>::iterator j = block.begin(); j != block.end(); ++j) {
			GameObject* temp = *j;
			temp->transform.m_Position.x -= 0.5f*time.asSeconds();
			if (temp->transform.m_Position.x < -100 || temp->transform.m_Position.y < 0
				|| temp->transform.m_Position.y > 410)
			{
				temp->health--;
			}
			if (temp->GetRigidbodyComponent()->iscollide)
			{
				temp->health--;
			}
		}
		//if the player collide wit hthe rock destroy it
		for (int i = 0; i < block.size(); i++) {
			
			if (block[i]->isdead)
			{
				if (block[i]->GetRigidbodyComponent()->iscollide)
				{
					player->health--;
				}


				for (std::vector<BaseComponent*>::iterator j = block[i]->m_Components.begin(); j != block[i]->m_Components.end(); ++j) {
					if (RigidbodyComponent* r = dynamic_cast<RigidbodyComponent*>((*j))) {
						
						m_physicsEngine->RigidBodies.erase(std::remove(m_physicsEngine->RigidBodies.begin(), m_physicsEngine->RigidBodies.end(), r), m_physicsEngine->RigidBodies.end());

					}
				}
				block.erase(std::remove(block.begin(), block.end(), block[i]), block.end());
			}
		}

		if (player->transform.m_Position.y < -50 || player->transform.m_Position.y>500) {
			player->health = 0;
		}

		//if player dead go to death screen
		if (player->health <= 0 && loadedscreen == false)
		{
			
			loadedscreen = true;
		}


		//Game manager
		if (spawnClock.getElapsedTime().asSeconds() > spawnTime) {
			SpawnEnemy();
			spawnTime = rand() % (3) + 1;
			spawnClock.restart();
		}

	}
}

void ScreenOne::SpawnEnemy() {
	GameObject* enemy = m_gameObjectManager->CreateObject();
	enemy->transform.m_Position.x = 800;
	enemy->transform.m_Position.y = rand() % (400);
	enemy->Tag = Player;

	int id = rand() % 4;

	switch (id)
	{
	case 0:
		enemy->transform.m_Scale = sf::Vector2f(0.3f, 0.3f);
		enemy->AddComponent(new SpriteRenderComponent("../../Assets/enemy1.png"));
		break;
	case 1:
		enemy->transform.m_Scale = sf::Vector2f(0.1f, 0.1f);
		enemy->AddComponent(new SpriteRenderComponent("../../Assets/enemy2.png"));
		break;
	case 2:
		enemy->transform.m_Scale = sf::Vector2f(0.1f, 0.1f);
		enemy->AddComponent(new SpriteRenderComponent("../../Assets/enemy3.png"));
		break;
	case 3:
		enemy->transform.m_Scale = sf::Vector2f(0.03f, 0.03f);
		enemy->AddComponent(new SpriteRenderComponent("../../Assets/enemy4.png"));
		break;
	}


	RigidbodyComponent* enemy_rb = new RigidbodyComponent(enemy, m_physicsEngine);
	enemy_rb->bounciness = 0.2f;
	enemy_rb->obeysGravity = false;
	enemy->AddComponent(enemy_rb);

	enemy->Tag = Block;
	enemy->health = 1;
	block.push_back(enemy);
}