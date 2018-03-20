#include "PhysicsRBody.hpp"

PhysicsRBody::PhysicsRBody(GameObject* gameObject, PhysicsEngine* engine) {
	m_gameObject = gameObject;
	//SetAABB();
	engine->AddRigidBody(this);
}

void PhysicsRBody::AddForce(sf::Vector2f force)
{
	totalForces += force;
}

void PhysicsRBody::Stop()
{
	currentVelocity = sf::Vector2f();
	totalForces = sf::Vector2f();
}
bool PhysicsRBody::IsGrounded()
{
	grounded = physicsEngine->IsGrounded(this);
	return grounded;
}

void PhysicsRBody::SetAABB()
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


void PhysicsRBody::Start() {
	SetAABB();
	physicsEngine->AddRigidBody(this);
}

void  PhysicsRBody::Integrate(sf::Time time) {
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
	currentVelocity += acceleration * time.asSeconds();

	sf::Vector2f temp = m_gameObject->transform.m_Position;
	temp += currentVelocity * time.asSeconds();
	m_gameObject->transform.m_Position = temp;
	
	SetAABB();

	totalForces = sf::Vector2f();
}