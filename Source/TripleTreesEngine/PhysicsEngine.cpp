#include "PhysicsEngine.hpp"

void PhysicsEngine::AddRigidBody(PhysicsRBody* rigidBody)
{
	//rigidBodies.push_back(rigidBody);
}

void PhysicsEngine::IntegrateBodies(sf::Time time)
{
	for (std::vector<PhysicsRBody*>::iterator i = rigidBodies.begin(); i != rigidBodies.end(); ++i) {
		if (PhysicsRBody* r = dynamic_cast<PhysicsRBody*>((*i))) {
			//r->Integrate(time);
		}
	}

	for (PhysicsRBody* rb : rigidBodies) {
		rb->Integrate(time);
	}
}

bool PhysicsEngine::IsGrounded(PhysicsRBody* rigidBody)
{
	for (std::vector<PhysicsRBody*>::iterator i = rigidBodies.begin(); i != rigidBodies.end(); ++i) {
		if (dynamic_cast<PhysicsRBody*>((*i)) != rigidBody)
		{
			PhysicsRBody* TemprigBody = dynamic_cast<PhysicsRBody*>((*i));
			if (rigidBody->aabb.bLeft.x < TemprigBody->aabb.tRight.x
				&& rigidBody->aabb.tRight.x > TemprigBody->aabb.bLeft.x
				&& abs(rigidBody->aabb.bLeft.y - TemprigBody->aabb.tRight.y) <= groundedTol)
			{
				if (abs(rigidBody->currentVelocity.y) < groundedTol)
					return true;
			}
		}
	}
	return false;
}

void PhysicsEngine::CheckCollisions()
{
	for (std::vector<PhysicsRBody*>::iterator i = rigidBodies.begin(); i != rigidBodies.end(); ++i) {
		for (std::vector<PhysicsRBody*>::iterator j = i; j != rigidBodies.end(); ++j) {

		}
	}
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

// Update is called once per frame
void PhysicsEngine::FixedUpdate(sf::Time time)
{
	UpdatePhysics(time);
}

