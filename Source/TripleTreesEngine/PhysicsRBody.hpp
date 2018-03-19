#pragma once

#include "SFML/Window.hpp"
#include "PhysicsEngine.hpp"
#include <stdio.h>
#include <SFML\Graphics.hpp>
#include <iostream>
#include <list>
#include <vector>
#include <map>
class PhysicsEngine;
class PhysicsRBody {

public:
	struct AABB
	{
	public:
		sf::Vector2f bLeft;
		sf::Vector2f tRight;
	};

public:
		float mass = 1.0f;                             // Mass of the RigidBody
		float bounciness = 1;                        // The bounciness factor (value between 0 and 1, 0 being no bounce, and 1 being super bouncy!)
		bool obeysGravity = true;                    // Whether or not this body obeys gravity
		sf::Vector2f gravity = sf::Vector2f(0, -9.8f);     // The gravity vector applied to this body

		sf::Vector2f currentVelocity;                     // The current velocity the body is moving at
		sf::Vector2f maxVelocity = sf::Vector2f(10.0f, 10.0f); // The maximum allowed velocity for this object

		bool grounded;
		AABB aabb;

public:
	void AddForce(sf::Vector2f force);
	void Stop();
	bool IsGrounded();
	void SetAABB();
	void Start();

	void Integrate(sf::Time time);
private:
	sf::Vector2f totalForces;

	PhysicsEngine* engine;
};











