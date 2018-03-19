#include "PhysicsRBody.hpp"



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
	grounded = engine->IsGrounded(this);
	return grounded;
}




/*
* ______________ <-What does this function do?
*
* Set the bounding box of the body depends on the mesh renderer.
*/
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
	//engine = GameObject.FindWithTag("PhysicsEngine").GetComponent<PhysicsEngine>();

	engine->AddRigidBody(this);
}



/*
* ______________ Describe how this function works
* Answer: 1. Check if the body is affected by the gravity. If it is, then apply a gravity force on the body.
*         2. If it's not affect by gravity or it's on ground, when it's speed on Y-axis is super small, then set it's speed on Y-axis to 0.
*         3. Use Newton's second law F = ma to calculate the acceleration. (Set acceleration to 0 if mass is 0)
*         4. Update the velocity depends on the acceleration.
*         5. Depends on the velocity, calculate the new position, and update the position in transform matrix.
*         6. Reset the AABB bounding box.
*         6. Clear the force.
*/
void  PhysicsRBody::Integrate(sf::Time time) {
	/// 
	/// ______________ What is the purpose of this part of code?
	/// 
	/// Answer: Check if the body is effected by gravity.
	///         If it's affected by gravity and it's not on the ground, then apply a gravity on it.
	///         Also, if the speed on Y-axis is less than 0.05, then set the velocity on Y-axis to 0.
	///         
	if (obeysGravity && !IsGrounded()) {
		AddForce(gravity);
	}
	else {
		if (abs(currentVelocity.y) < 0.05f) currentVelocity.y = 0;
	}
	///
	///
	///

	sf::Vector2f acceleration = totalForces / mass;
	if (mass == 0)
		acceleration = sf::Vector2f();

	currentVelocity += acceleration * time.asSeconds();

	//sf::Vector2f temp = transform.position;
	//temp += currentVelocity * time.asSeconds();
	//transform.position = temp;
	SetAABB();

	totalForces = sf::Vector2f();
}