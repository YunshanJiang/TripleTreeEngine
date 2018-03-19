#pragma once

#include "PhysicsRBody.hpp"
#include "SFML/Window.hpp"

#include <stdio.h>
#include <SFML\Graphics.hpp>
#include <iostream>
#include <list>
#include <vector>
#include <map>
class PhysicsRBody;
class PhysicsEngine {
	

public:
	struct CollisionPair
	{
	public:
		PhysicsRBody* rigidBodyA;
		PhysicsRBody* rigidBodyB;
	};

public:
	struct CollisionInfo
	{
	public:
		sf::Vector2f collisionNormal;
	    float penetration;
	};

public:
	float groundedTol = 0.1f;
	std::vector<PhysicsRBody*> rigidBodies;
	void AddRigidBody(PhysicsRBody* rigidBody);
	bool IsGrounded(PhysicsRBody* rigidBody);
	void CheckCollisions();
	void ResolveCollisions();
	void PositionalCorrection(CollisionPair c);
	void IntegrateBodies(sf::Time time);


	void UpdatePhysics();
	void FixedUpdate();
private:
	std::map<CollisionPair, CollisionInfo> collisions;
	
};










