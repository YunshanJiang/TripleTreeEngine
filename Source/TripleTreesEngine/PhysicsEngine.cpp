#include "PhysicsEngine.h"
#include "RigidbodyComponent.h"
#include <iostream>

PhysicsEngine::PhysicsEngine()
{
}

void PhysicsEngine::AddRigidBody(RigidbodyComponent* rigidBody)
{
	RigidBodies.push_back(rigidBody);
}

void PhysicsEngine::IntegrateBodies(sf::Time time)
{
	for (RigidbodyComponent* rb : RigidBodies) {
		rb->Integrate(time);
	}
}

bool PhysicsEngine::IsGrounded(RigidbodyComponent* rigidBody)
{
	return false;
}

void PhysicsEngine::CheckCollisions()
{

}

void PhysicsEngine::ResolveCollisions()
{

}

void PhysicsEngine::PositionalCorrection(CollisionPair c)
{

}

void PhysicsEngine::UpdatePhysics(sf::Time time)
{
	IntegrateBodies(time);
	//CheckCollisions();
	//ResolveCollisions();
}

