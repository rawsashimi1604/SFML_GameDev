#include "Game.h"

// Static functions

// Initializer functions
void Game::initWindow()
{   
    /* Creates a SFML window using options from a window.ini file. */
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "C++ SFML RPG");
}

// Constructors / Destructors
Game::Game()
{
    this->initWindow();
}


// Destructors
Game::~Game()
{   
    /* Deallocate dynamic memory in heap */
	delete this->window;
}

void Game::updateDt()
{
    /* Updates the dt variable with the time it takes to update and render one frame. */
    this->dt = this->dtClock.restart().asSeconds();

    system("cls");
    std::cout << this->dt << std::endl;
}

// Functions 
void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent)) {

        if (this->sfEvent.type == sf::Event::Closed) {
            this->window->close();
        }

    }

}

void Game::update()
{
    this->updateSFMLEvents();

}

void Game::render()
{
    this->window->clear();

    // Render items

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
