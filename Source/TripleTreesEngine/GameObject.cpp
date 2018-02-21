/*
#include "GameObject.hpp"

GameObject::~GameObject(void) {
	for (unsigned int i = 0; i < children.size(); i++) {
		delete children[i];
	}
}

void GameObject::AddChild(GameObject* s) {
	children.push_back(s);
	s->parent = this;
}

void GameObject::Update(float msec) {
	if (parent) {
		worldTransform = parent->worldTransform*transform;
	}
	else {
		worldTransform = transform;
	}

	for (std::vector<GameObject*>::iterator i = children.begin(); i != children.end(); ++i)
	{
		(*i)->Update(msec);
	}
}
*/

#include "GameObject.hpp"

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
		//worldTransform = m_Parent->worldTransform * transform.transformMatrix;
	}
	else {
		//worldTransform = glm::mat4(1.0f) * transform.transformMatrix;
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