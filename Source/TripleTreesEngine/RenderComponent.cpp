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

void SpriteRenderComponent::Render(sf::RenderWindow& window, GameObject* gameobject) {
	//sprite.setPosition(gameobject->getPosition());
	//sprite.setRotation(gameobject->transform.m_Rotation);
	//sprite.setScale(gameobject->transform.m_Scale.x, gameobject->transform.m_Scale.y);
	
	window.draw(sprite, gameobject->worldTransform);
}

