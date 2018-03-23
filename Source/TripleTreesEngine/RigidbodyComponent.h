#pragma once
#ifndef RigidbodyComponent_h
#define RigidbodyComponent_h

#include "BaseComponent.h"
#include "PhysicsEngine.h"
#include "GameObject.h"
#include "SFML\Graphics.hpp"

class RigidbodyComponent : public BaseComponent
{
public:
	RigidbodyComponent(GameObject* gameObject,PhysicsEngine* physicsEngine);

	void Awake();
	void Start();
	void Update();
	void LateUpdate();

	void AddForce(sf::Vector2f force);
	void Stop();
	bool IsGrounded();
	void SetAABB();
	void Integrate(sf::Time time);

	struct AABB
	{
	public:
		sf::Vector2f tLeft;
		sf::Vector2f bRight;
	};
	AABB aabb;

	sf::Vector2f gravity = sf::Vector2f(0, -9.8f);          // The gravity vector applied to this body
	float mass = 1.0f;                                      // Mass of the RigidBody
	float bounciness = 1;                                   // The bounciness factor (value between 0 and 1, 0 being no bounce, and 1 being super bouncy!)
	bool obeysGravity = true;                               // Whether or not this body obeys gravity
	bool grounded;
	sf::Vector2f currentVelocity;                           // The current velocity the body is moving at
	sf::Vector2f maxVelocity = sf::Vector2f(10.0f, 10.0f);  // The maximum allowed velocity for this object

private:
	PhysicsEngine* m_physicsEngine;
	GameObject* m_gameObject;
	sf::Vector2f totalForces;
};
#endif // !RigidbodyComponent
