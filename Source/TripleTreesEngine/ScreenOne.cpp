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
			if (temp->transform.m_Position.x < -100 || temp->transform.m_Position.y < 100
				|| temp->transform.m_Position.y > 500)
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
				block.erase(std::remove(block.begin(), block.end(), block[i]), block.end());

			}
		}
		//if player dead go to death screen
		if (player->health <= 0 && loadedscreen == false)
		{
			
			loadedscreen = true;
		}
	}
	
}