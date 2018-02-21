#include <stdio.h>
#include "BaseComponent.h"
#include <SFML\Graphics.hpp>

#define X_AXIS sf::Vector3(1,0,0)
#define Y_AXIS sf::Vector3(0,1,0)
#define Z_AXIS sf::Vector3(0,0,1)

struct Vector3
{
public:
	Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	float x, y, z;
};

class Transform : public BaseComponent {
public:
	Transform() : m_Position(), m_Rotation(), m_Scale(1, 1, 1) {}

	void Awake();
	void Start();
	void Update();
	void LateUpdate();

	Vector3 m_Position;
	Vector3 m_Rotation;
	Vector3 m_Scale;

	sf::Transform transformMatrix;
};