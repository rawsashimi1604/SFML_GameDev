#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class State
{

private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;


public:
	State(sf::RenderWindow* window);
	virtual ~State();

	/* Pure virtual functions.. abstract functions.. */
	virtual void endState() = 0;
	virtual void update(const float &dt) = 0;

	/* If nothing is given, render to window. Else, render to specific target.*/
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif