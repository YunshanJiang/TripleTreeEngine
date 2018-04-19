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
		audio->Music.setLoop(true);
	}
	else if (node->Name() == TEXTRENDER_COMPONENT) {
		TextRenderComponent* thetext = new TextRenderComponent(node->Attribute("src"));
		gameObject->AddComponent(thetext);
		thetext->text.setFillColor(sf::Color::Red);
		if (node->FirstChildElement("size") != NULL) {
			thetext->text.setCharacterSize(atof(node->FirstChildElement("size")->Attribute("ss")));
			
		}
		if (node->FirstChildElement("string") != NULL) {
			thetext->text.setString(node->FirstChildElement("string")->Attribute("s"));
		}
		if (node->FirstChildElement("Position") != NULL) {
			thetext->text.setPosition(atof(node->FirstChildElement("Position")->Attribute("x")),
				atof(node->FirstChildElement("Position")->Attribute("y")));
		}
		if (node->FirstChildElement("Scale") != NULL) {
			thetext->text.setScale(atof(node->FirstChildElement("Scale")->Attribute("x")),
				atof(node->FirstChildElement("Scale")->Attribute("y")));
		}
	}
	else if (node->Name() == Tag) {
		
		if (node->Attribute("t","Player"))
		{
			gameObject->Tag = Player;
			gameObject->health = 3;
		}
		else if (node->Attribute("t", "Default"))
		{
			gameObject->Tag = Default;
			gameObject->health = 3;
		}
		else if (node->Attribute("t", "TimerText"))
		{
			gameObject->Tag = TimerText;
			gameObject->health = 3;
		}
		else if (node->Attribute("t", "LifeText"))
		{
			gameObject->Tag = LifeText;
			gameObject->health = 3;

		}
		else if (node->Attribute("t", "Block"))
		{
			gameObject->Tag = Block;
			gameObject->health = 1;
		}
		else if (node->Attribute("t", "StartButton"))
		{
			
			gameObject->Tag = StartButton;
			gameObject->health = 3;
		}
		else if (node->Attribute("t", "RestartButton"))
		{

			gameObject->Tag = RestartButton;
			gameObject->health = 3;
		}
		else if (node->Attribute("t", "MainMenuButton"))
		{

			gameObject->Tag = MainMenuButton;
			gameObject->health = 3;
		}
		else if (node->Attribute("t", "ExitButton"))
		{
			gameObject->Tag = ExitButton;
			gameObject->health = 3;
		}

	}
}