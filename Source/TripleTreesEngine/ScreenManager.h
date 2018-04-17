#pragma once
#ifndef ScreenManager_h
#define ScreenManager_h
#include "GameObjectManager.h"
#include "tinyxml2.h"
#include "PhysicsEngine.h"
#include "RigidbodyComponent.h"
#include "AudioComponent.h"

using namespace tinyxml2;

class ScreenManager
{
public:
	ScreenManager(GameObjectManager* gameObjManager, PhysicsEngine* physicsEngine);
	void Load(const char* pFilename);

private:
	GameObjectManager * m_gameObjectManager;
	PhysicsEngine* m_physicsEngine;

	const std::string TRANSFORM_COMPONENT = "Transform";
	const std::string RENDER_COMPONENT = "Render";
	const std::string RIGIDBODY_COMPONENT = "Rigidbody";
	const std::string AUDIO_COMPONENT = "Audio";

	void CreateComponent(GameObject* gameObject, XMLElement* node);
};


#endif // SCREEN_MANAGER
