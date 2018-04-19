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

	void SetTexture(std::string path);
	void Render(sf::RenderWindow& window, GameObject* gameobject);
	
	sf::Texture texture;
	sf::Sprite sprite;
};


class TextRenderComponent : public BaseComponent {
public:
	TextRenderComponent(std::string path);

	void Awake();
	void Start();
	void Update();
	void LateUpdate();

	void Setfont(std::string path);
	void Render(sf::RenderWindow& window);

	sf::Text text;
	sf::Font font;
};