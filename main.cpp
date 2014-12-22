#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>

#include "Level.h"

using namespace sf;

int main()
{
    srand(time(NULL));
    // Create the main window
    RenderWindow app(VideoMode(800, 600), "SFML window");

    Vector2i sightPosition;

    Level aLevel;

    app.setMouseCursorVisible(false);
    app.setFramerateLimit(60);

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        Event event;
        while (app.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    app.close();
                    break;
                case Event::MouseButtonPressed:
                    aLevel.checkTheShot(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    break;
            }

            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                app.close();
            }

            aLevel.setSightPosition(Mouse::getPosition(app));

        }

        aLevel.runActions();

        aLevel.draw(app);
    }

    return EXIT_SUCCESS;
}
