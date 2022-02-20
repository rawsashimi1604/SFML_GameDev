#ifndef GAME_H
#define GAME_H

#include "GameState.h"

class Game
{
private:
	// Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	/* Delta time => Determines how long each frame took to render (One update() and one render() method call) */
	sf::Clock dtClock;
	float dt;

	/* State is pointer because it is an abstract class... */
	std::stack<State*> states;

	// Initialization
	void initWindow();
	void initStates();

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