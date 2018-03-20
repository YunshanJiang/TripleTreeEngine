#pragma once

#include "SFML/Window.hpp"
#include "BaseComponent.h"
#include "GameObject.h"
#include "PhysicsEngine.hpp"
#include <stdio.h>
#include <SFML\Graphics.hpp>
#include <iostream>
#include <list>
#include <vector>
#include <map>
class PhysicsEngine;

class PhysicsRBody : public BaseComponent {

public:
	PhysicsRBody(GameObject* gameObject, PhysicsEngine* engine);

	struct AABB
	{
	public:
		sf::Vector2f bLeft;
		sf::Vector2f tRight;
	};
	AABB aabb;

	float mass = 1.0f;                                      // Mass of the RigidBody
	float bounciness = 1;                                   // The bounciness factor (value between 0 and 1, 0 being no bounce, and 1 being super bouncy!)
	bool obeysGravity = true;                               // Whether or not this body obeys gravity
	sf::Vector2f gravity = sf::Vector2f(0, -9.8f);          // The gravity vector applied to this body
	bool grounded;

	sf::Vector2f currentVelocity;                           // The current velocity the body is moving at
	sf::Vector2f maxVelocity = sf::Vector2f(10.0f, 10.0f);  // The maximum allowed velocity for this object

public:
	void Awake() {};
	void Start();
	void Update() {};
	void LateUpdate() {};

	void AddForce(sf::Vector2f force);
	void Stop();
	bool IsGrounded();
	void SetAABB();
	void Integrate(sf::Time time);

private:
	GameObject* m_gameObject;
	PhysicsEngine* physicsEngine;
	sf::Vector2f totalForces;
};











