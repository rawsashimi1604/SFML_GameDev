#include "Game.h"

// Static functions

// Initializer functions
void Game::initWindow()
{   
    /* Creates a SFML window using options from a window.ini file. */
    std::ifstream ifs("Config/window.ini"); // infile stream

    /* Default settings ... */
    std::string title = "None";
    sf::VideoMode window_bounds(800, 600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    /* If file is open, read from window.ini file instead... */
    if (ifs.is_open()) {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
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

    
    system("cls"); // Clears the screen.
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
