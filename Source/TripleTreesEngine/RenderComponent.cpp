#include "RenderComponent.hpp"

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

void SpriteRenderComponent::Render(sf::RenderWindow& window) {
	window.draw(sprite);
}

