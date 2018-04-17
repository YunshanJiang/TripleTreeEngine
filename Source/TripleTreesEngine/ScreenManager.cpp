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

		if (node->FirstChildElement("Position") != NULL) {
			gameObject->transform.m_Position.x = atof(node->FirstChildElement("Position")->Attribute("x"));
			gameObject->transform.m_Position.y = atof(node->FirstChildElement("Position")->Attribute("y"));
		}
		else if (node->FirstChildElement("Rotation") != NULL)
		{
			gameObject->transform.m_Rotation = atof(node->FirstChildElement("Rotation")->Attribute("z"));
		}
		else if (node->FirstChildElement("Scale") != NULL)
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
}