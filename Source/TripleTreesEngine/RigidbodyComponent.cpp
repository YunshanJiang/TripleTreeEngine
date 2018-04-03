#include "RigidbodyComponent.h"

RigidbodyComponent::RigidbodyComponent(GameObject* gameObject, PhysicsEngine* physicsEngine)
{
	m_gameObject = gameObject;
	m_physicsEngine = physicsEngine;
	SetAABB();
	physicsEngine->AddRigidBody(this);
}

void RigidbodyComponent::Awake()
{
}
void RigidbodyComponent::Start()
{
}
void RigidbodyComponent::Update()
{
}
void RigidbodyComponent::LateUpdate()
{
}

void RigidbodyComponent::AddForce(sf::Vector2f force)
{
	totalForces += force;
}

void RigidbodyComponent::Stop()
{
	currentVelocity = sf::Vector2f();
	totalForces = sf::Vector2f();
}
bool RigidbodyComponent::IsGrounded()
{
	grounded = m_physicsEngine->IsGrounded(this);
	return grounded;
}

void RigidbodyComponent::SetAABB()
{
	float width = 1;
	float height = 1;

	for (std::vector<BaseComponent*>::iterator j = m_gameObject->m_Components.begin(); j != m_gameObject->m_Components.end(); ++j) {
		if (SpriteRenderComponent* r = dynamic_cast<SpriteRenderComponent*>((*j))) {
			width = r->texture.getSize().x * m_gameObject->transform.m_Scale.x;
			height = r->texture.getSize().y * m_gameObject->transform.m_Scale.y;
		}
	}

	aabb.tLeft = m_gameObject->transform.m_Position;
	aabb.bRight = m_gameObject->transform.m_Position + sf::Vector2f(width, height);

	//std::cout << "Top left x: " << aabb.tLeft.x << " y: " << aabb.tLeft.y << std::endl;
	//std::cout << "bot right x: " << aabb.bRight.x << " y: " << aabb.bRight.y << std::endl;
}

void  RigidbodyComponent::Integrate(sf::Time time) {
	
	if (obeysGravity && !IsGrounded()) {
		AddForce(gravity);
	}
	else {

		if (abs(currentVelocity.y) < 0.05f) {
			currentVelocity.y = 0;
		}
	}

	sf::Vector2f acceleration = totalForces / mass;
	if (mass == 0) {
		acceleration = sf::Vector2f();
	}
	currentVelocity += acceleration * 0.003f; //* time.asSeconds();

	sf::Vector2f temp = m_gameObject->transform.m_Position;
	temp -= currentVelocity * 0.003f; //* time.asSeconds();
	m_gameObject->transform.m_Position = temp;
	//std::cout << m_gameObject->transform.m_Position.y << std::endl;

	SetAABB();

	totalForces = sf::Vector2f();
}