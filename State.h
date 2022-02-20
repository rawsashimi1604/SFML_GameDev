#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class State
{

private:
	std::vector<sf::Texture> textures;


public:
	State();
	virtual ~State();

	/* Pure virtual function.. abstract functions.. */
	virtual void update() = 0;
	virtual void render() = 0;
};

#endif

