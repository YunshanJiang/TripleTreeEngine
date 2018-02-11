#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class TripleTreeEngine
{
public:
	static void Start();
	static void Initialize();
private:
	static sf::RenderWindow m_mainWindow;
};