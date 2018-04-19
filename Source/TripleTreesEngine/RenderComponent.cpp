#include "RenderComponent.hpp"
#include <exception>
SpriteRenderComponent::SpriteRenderComponent(std::string path) {
	if (texture.loadFromFile(path) != true) {
		return;
	}
	sprite.setTexture(texture);
}

void SpriteRenderComponent::Awake() {

}

void SpriteRenderComponent::Start() {

}

void SpriteRenderComponent::Update() {
	
}

void SpriteRenderComponent::LateUpdate() {

}

void SpriteRenderComponent::SetTexture(std::string path) {
	if (texture.loadFromFile(path) != true) {
		return;
	}
	sprite.setTexture(texture);
}
void SpriteRenderComponent::Render(sf::RenderWindow& window, GameObject* gameobject) {
	//sprite.setPosition(gameobject->getPosition());
	//sprite.setRotation(gameobject->transform.m_Rotation);
	//sprite.setScale(gameobject->transform.m_Scale.x, gameobject->transform.m_Scale.y);
	
	window.draw(sprite, gameobject->worldTransform);
}








TextRenderComponent::TextRenderComponent(std::string path) {
	if (font.loadFromFile(path) != true) {
		return;
	}
	text.setFont(font);
}

void TextRenderComponent::Awake() {

}

void TextRenderComponent::Start() {

}

void TextRenderComponent::Update() {

}

void TextRenderComponent::LateUpdate() {

}

void TextRenderComponent::Setfont(std::string path) {
	if (font.loadFromFile(path) != true) {
		return;
	}
	text.setFont(font);
}
void TextRenderComponent::Render(sf::RenderWindow& window) {
	//sprite.setPosition(gameobject->getPosition());
	//sprite.setRotation(gameobject->transform.m_Rotation);
	//sprite.setScale(gameobject->transform.m_Scale.x, gameobject->transform.m_Scale.y);

	window.draw(text);
}
