#pragma once
#ifndef PhysicsEngine_h
#define PhysicsEngine_h
#include "SFML\Graphics.hpp"
class RigidbodyComponent;

class PhysicsEngine
{
public:
	PhysicsEngine();
	struct CollisionPair
	{
		RigidbodyComponent* rb_A;
		RigidbodyComponent* rb_B;
	};

	struct CollisionInfo
	{
		sf::Vector2f collisionNormal;
		float penetration;
	};

	void UpdatePhysics(sf::Time time);
	void AddRigidBody(RigidbodyComponent* rigidBody);
	bool IsGrounded(RigidbodyComponent* rigidBody);
	void CheckCollisions();
	void ResolveCollisions();
	void PositionalCorrection(CollisionPair c);
	void IntegrateBodies(sf::Time time);
	
private:
	std::vector<RigidbodyComponent*> RigidBodies;
	std::map<CollisionPair, CollisionInfo> collisions;
	float groundedTol = 0.1f;
};





#endif // !PhysicsEngine_h
