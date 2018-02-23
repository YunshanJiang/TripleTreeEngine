#include "GameObject.h"

void GameObject::Awake() {
	for (std::vector<BaseComponent*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->Awake();
	}
}

void GameObject::Start() {
	for (std::vector<BaseComponent*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->Start();
	}
}

void GameObject::Update(float msec) {
	if (m_Parent) {
		worldTransform = m_Parent->worldTransform * transform.transformMatrix;
	}
	else {
		worldTransform = transform.transformMatrix;
	}

	for (std::vector<BaseComponent*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->Update();
	}
}

void GameObject::LateUpdate(float msec) {
	for (std::vector<BaseComponent*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->LateUpdate();
	}
}

void GameObject::AddComponent(BaseComponent* component)
{
	m_Components.push_back(component);
}

void GameObject::AddChild(GameObject* child) {
	m_Children.push_back(child);
}

