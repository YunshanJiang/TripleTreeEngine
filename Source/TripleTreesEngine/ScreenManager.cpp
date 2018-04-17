#include "ScreenManager.h"

ScreenManager::ScreenManager(GameObjectManager* gameObjManager, PhysicsEngine* physicsEngine)
{
	m_gameObjectManager = gameObjManager;
	m_physicsEngine = physicsEngine;
}

void ScreenManager::Load(const char* pFilename) {
	XMLDocument docs;
	docs.LoadFile(pFilename);

	if (docs.ErrorID() != tinyxml2::XMLError::XML_SUCCESS) {
		return;
	}

	//Read all object
	XMLElement* obj = docs.RootElement();
	while (obj != NULL)
	{
		//Create obj
		GameObject* gameObject = m_gameObjectManager->CreateObject();

		//Read all component
		XMLElement* comp = obj->FirstChildElement();
		while (comp != NULL)
		{
			//Create component
			CreateComponent(gameObject, comp);
			comp = comp->NextSiblingElement();
		}
		obj = obj->NextSiblingElement();
	}
}

void ScreenManager::CreateComponent(GameObject* gameObject, XMLElement* node) {
	if (node->Name() == TRANSFORM_COMPONENT) {
		
		//std::cout << node->FirstChild()->Value() << std::endl;
		if (node->FirstChildElement("Position") != NULL) {
			gameObject->transform.m_Position.x = atof(node->FirstChildElement("Position")->Attribute("x"));
			gameObject->transform.m_Position.y = atof(node->FirstChildElement("Position")->Attribute("y"));
		}
		if (node->FirstChildElement("Rotation") != NULL)
		{
			gameObject->transform.m_Rotation = atof(node->FirstChildElement("Rotation")->Attribute("z"));
		}
		if (node->FirstChildElement("Scale") != NULL)
		{
			gameObject->transform.m_Scale.x = atof(node->FirstChildElement("Scale")->Attribute("x"));
			gameObject->transform.m_Scale.y = atof(node->FirstChildElement("Scale")->Attribute("y"));
		}
	}
	else if (node->Name() == RENDER_COMPONENT)
	{
		SpriteRenderComponent* spRender = new SpriteRenderComponent(node->Attribute("src"));
		gameObject->AddComponent(spRender);

		if (node->FirstChildElement("Sprite") != NULL) {
			spRender->sprite.setScale(
				atof(node->FirstChildElement("Sprite")->Attribute("xScale")),
				atof(node->FirstChildElement("Sprite")->Attribute("yScale"))
			);
		}
	}
	else if (node->Name() == RIGIDBODY_COMPONENT) {
		RigidbodyComponent* rigidbody = new RigidbodyComponent(gameObject, m_physicsEngine);
		gameObject->AddComponent(rigidbody);
		
		if (node->FirstChildElement("gravity") != NULL) {
			rigidbody->gravity = sf::Vector2f(atof(node->FirstChildElement("gravity")->Attribute("x")),
				atof(node->FirstChildElement("gravity")->Attribute("y")));
			
		}
		if (node->FirstChildElement("mass") != NULL) {
			rigidbody->mass = atof(node->FirstChildElement("mass")->Attribute("m"));
			//std::cout << node->FirstChildElement("mass")->Value() << std::endl;
		}
		if (node->FirstChildElement("bounciness") != NULL) {
			rigidbody->bounciness = atof(node->FirstChildElement("bounciness")->Attribute("b"));
		}
		if (node->FirstChildElement("obeysGravity") != NULL) {
			std::string t = "true";
			rigidbody->obeysGravity = (node->FirstChildElement("obeysGravity")->GetText() == t)? true:false;
			
		}
	}
	else if (node->Name() == AUDIO_COMPONENT) {
		AudioComponent* audio = new AudioComponent(node->Attribute("src"));
		gameObject->AddComponent(audio);
		audio->PlaySound();
	}
}