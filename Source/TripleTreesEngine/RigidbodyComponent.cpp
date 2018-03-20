#include "RigidbodyComponent.h"

RigidbodyComponent::RigidbodyComponent(GameObject* gameObject, PhysicsEngine* physicsEngine)
{
	m_gameObject = gameObject;
	m_physicsEngine = physicsEngine;

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
	//Bounds bound = new Bounds(new Vector2(0, 0), new Vector2(1, 1));
	//Renderer renderer = GetComponent<Renderer>();

	//if (renderer)
	//{
	//	bound = renderer.bounds;
	//}

	//.bLeft = new Vector2(bound.center.x - bound.extents.x, bound.center.y - bound.extents.y);
	//aabb.tRight = new Vector2(bound.center.x + bound.extents.x, bound.center.y + bound.extents.y);
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
	currentVelocity += acceleration*0.001f; //* time.asSeconds();

	sf::Vector2f temp = m_gameObject->transform.m_Position;
	temp -= currentVelocity * 0.001f; //* time.asSeconds();
	m_gameObject->transform.m_Position = temp;
	std::cout << m_gameObject->transform.m_Position.y << std::endl;

	SetAABB();

	totalForces = sf::Vector2f();
}