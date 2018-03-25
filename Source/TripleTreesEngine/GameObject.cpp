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

void GameObject::Update(sf::Time time) {
	transform.Update();
	if (m_Parent) {
		
		worldTransform = m_Parent->worldTransform * transform.transformMatrix;
		
		//this->setPosition((m_Parent->getTransform())*sf::Vector2f());
		//this->move(transform.m_Position);
	}
	else {
		worldTransform = transform.transformMatrix;
		//this->setPosition(transform.m_Position);
		
	}
	
	for (std::vector<BaseComponent*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->Update();
	}
}

void GameObject::LateUpdate(sf::Time time) {
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
	child->m_Parent = this;
}

