#pragma once
#include "BaseComponent.h"
#include "SFML/Window.hpp"
#include "GameObject.h"
#include <SFML\Graphics.hpp>
class GameObject;

class SpriteRenderComponent : public BaseComponent {
public:
	SpriteRenderComponent(std::string path);

	void Awake();
	void Start();
	void Update();
	void LateUpdate();

	void Render(sf::RenderWindow& window, GameObject* gameobject);
	
	sf::Texture texture;
	sf::Sprite sprite;
};