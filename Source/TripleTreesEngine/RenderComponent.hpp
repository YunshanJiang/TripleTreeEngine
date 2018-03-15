#pragma once
#include "BaseComponent.h"
#include "SFML/Window.hpp"

#include <SFML\Graphics.hpp>

class SpriteRenderComponent : public BaseComponent {
public:

	void Awake();
	void Start();
	void Update();
	void LateUpdate();

	
	sf::Texture texture;
	sf::Sprite sprite;
private:
protected:

};