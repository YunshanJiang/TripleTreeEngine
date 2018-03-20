#include "Transform.h"

void Transform::Awake() {
	sf::Transform Model;
	Model = Model.Identity;
	Model = Model.translate(m_Position.x, m_Position.y);
	Model = Model.rotate(m_Rotation);
	Model = Model.scale(m_Scale.x, m_Scale.y);
	transformMatrix = Model;
}

void Transform::Start() {

}

void Transform::Update() {
	sf::Transform Model;
	Model = Model.Identity;
	Model = Model.translate(m_Position.x, m_Position.y);
	Model = Model.rotate(m_Rotation);
	Model = Model.scale(m_Scale.x, m_Scale.y);
	transformMatrix = Model;
}

void Transform::LateUpdate() {

}

