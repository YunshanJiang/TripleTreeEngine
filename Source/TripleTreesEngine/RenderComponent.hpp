#pragma once
#include "BaseComponent.h"
#include "SFML/Window.hpp"

#include <SFML\Graphics.hpp>

class SpriteRenderComponent : public BaseComponent {
public:
	SpriteRenderComponent(std::string path);

	void Awake();
	void Start();
	void Update();
	void LateUpdate();

	void Render(sf::RenderWindow& window);
	
	sf::Texture texture;
	sf::Sprite sprite;
};