#ifndef GAME_H
#define GAME_H

#include "State.h"

class Game
{
private:
	// Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	/* Delta time => Determines how long each frame took to render (One update() and one render() method call) */
	sf::Clock dtClock;
	float dt;

	// Initialization
	void initWindow();


public:
	// Constructors / Destructors
	Game();
	virtual ~Game();

	// Functions
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif