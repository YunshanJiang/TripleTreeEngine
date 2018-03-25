#pragma once
#include "BaseComponent.h"
#include "SFML/Window.hpp"
#include "GameObject.h"
#include <SFML\Audio.hpp>
class AudioComponent : public BaseComponent {
public:
	AudioComponent(std::string path);
	void Awake();
	void Start();
	void Update();
	void LateUpdate();
	sf::SoundBuffer Soundbuffer;
	sf::Sound Sound;
	sf::Music Music;

	void PlaySound();
};