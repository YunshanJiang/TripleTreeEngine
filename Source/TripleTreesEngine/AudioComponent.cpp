#include "AudioComponent.h"

AudioComponent::AudioComponent(std::string path) {
	Music.openFromFile(path);
	
}
void AudioComponent::Awake() {

}

void AudioComponent::Start() {

}

void AudioComponent::Update() {

}

void AudioComponent::LateUpdate() {

}

void AudioComponent::PlaySound() {
	if (Sound.getBuffer())
		Sound.play();
	else {
		Music.play();
	}
}