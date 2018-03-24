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
	for (int i = 0; i < RigidBodies.size()-1; i++) {
		RigidbodyComponent* rb_A = RigidBodies[i];
		for (int j = i+1; j < RigidBodies.size(); j++) {
			RigidbodyComponent* rb_B = RigidBodies[j];
			if (rb_A != rb_B) {
				CollisionPair pair;
				CollisionInfo info;
				pair.rb_A = rb_A;
				pair.rb_B = rb_B;

				sf::Vector2f distance = rb_B->m_gameObject->transform.m_Position - rb_A->m_gameObject->transform.m_Position;

				sf::Vector2f halfSizeA = (rb_A->aabb.bRight - rb_A->aabb.tLeft) * 0.5f;
				sf::Vector2f halfSizeB = (rb_B->aabb.bRight - rb_B->aabb.tLeft) * 0.5f;
				sf::Vector2f gap = sf::Vector2f(abs(distance.x), abs(distance.y)) - (halfSizeA + halfSizeB);
				
				if (gap.x < 0 && gap.y < 0) {
					//Collide
					if (collisions.find(pair) != collisions.end()) {
						collisions.erase(pair);
					}

					if (gap.x > gap.y) {
						if (distance.x > 0) {
							info.collisionNormal = sf::Vector2f(1.0f, 0.0f);
						}
						else
						{
							info.collisionNormal = sf::Vector2f(-1.0f, 0.0f);

						}
						info.penetration = gap.x;
					}
					else {
						if (distance.y > 0) {
							info.collisionNormal = sf::Vector2f(0.0f, -1.0f);
						}
						else
						{
							info.collisionNormal = sf::Vector2f(0.0f, 1.0f);
						}
						info.penetration = gap.y;
					}
					collisions[pair] = info;
				}
				else if (collisions.find(pair) != collisions.end()) {
					collisions.erase(pair);
				}
			}
		}

	}
}

void PhysicsEngine::ResolveCollisions()
{
	for (std::map<CollisionPair, CollisionInfo>::iterator it = collisions.begin(); it != collisions.end(); ++it)
	{
		CollisionPair pair = it->first;

		float minBounce = std::min(pair.rb_A->bounciness, pair.rb_B->bounciness);

		sf::Vector2f v = pair.rb_B->currentVelocity - pair.rb_A->currentVelocity;
		float velAlongNormal = v.x*collisions[pair].collisionNormal.x + v.y*collisions[pair].collisionNormal.y;
		if (velAlongNormal > 0) continue;

		float j = -(1 + minBounce) * velAlongNormal;
		float invMassA, invMassB;
		if (pair.rb_A->mass == 0) {
			invMassA = 0;
		}
		else {
			invMassA = 1 / pair.rb_A->mass;
		}

		if (pair.rb_B->mass == 0) {
			invMassB = 0;
		}
		else {
			invMassB = 1 / pair.rb_B->mass;
		}
		j /= invMassA + invMassB;


		sf::Vector2f impulse = j * collisions[pair].collisionNormal;
		
		// ... update velocities
		pair.rb_A->AddForce(-impulse / 0.0003f);
		pair.rb_B->AddForce(impulse / 0.0003f);

		if (abs(collisions[pair].penetration) > 0.01f) {
			PositionalCorrection(pair);
		}
	}
}

void PhysicsEngine::PositionalCorrection(CollisionPair c)
{
	/*
	const float percent = 0.2f;

	float invMassA, invMassB;
	if (c.rigidBodyA.mass == 0)
		invMassA = 0;
	else
		invMassA = 1 / c.rigidBodyA.mass;

	if (c.rigidBodyB.mass == 0)
		invMassB = 0;
	else
		invMassB = 1 / c.rigidBodyB.mass;

	Vector2 correction = ((collisions[c].penetration / (invMassA + invMassB)) * percent) * -collisions[c].collisionNormal;

	Vector2 temp = c.rigidBodyA.transform.position;
	temp -= invMassA * correction;
	c.rigidBodyA.transform.position = temp;

	temp = c.rigidBodyB.transform.position;
	temp += invMassB * correction;
	c.rigidBodyB.transform.position = temp;
	*/
}

void PhysicsEngine::UpdatePhysics(sf::Time time)
{
	IntegrateBodies(time);
	CheckCollisions();
	ResolveCollisions();
}

