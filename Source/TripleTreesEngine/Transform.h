#include <stdio.h>
#include "BaseComponent.h"
#include <SFML\Graphics.hpp>

#define X_AXIS sf::Vector3(1,0,0)
#define Y_AXIS sf::Vector3(0,1,0)

struct Vector2
{
public:
	Vector2(): x(0.0f), y(0.0f) {}
	Vector2(float _x, float _y) : x(_x), y(_y) {}

	float x, y;
};

class Transform : public BaseComponent {
public:
	Transform() : m_Position(), m_Rotation(), m_Scale(1, 1) {}

	void Awake();
	void Start();
	void Update();
	void LateUpdate();
	
	sf::Vector2f m_Position;
	float m_Rotation;
	sf::Vector2f m_Scale;


	sf::Transform transformMatrix;
	  
};