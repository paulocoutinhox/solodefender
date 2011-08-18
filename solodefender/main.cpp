#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "ResourcePath.hpp"

int main (int argc, const char * argv[])
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.LoadFromFile(ResourcePath() + "cute_image.jpg"))
    	return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // Create a graphical text to display
    sf::Font font;
    if (!font.LoadFromFile(ResourcePath() + "sansation.ttf"))
    	return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);
    text.SetColor(sf::Color::Black);

    // Load a music to play
    sf::Music music;
    if (!music.OpenFromFile(ResourcePath() + "nice_music.ogg"))
    	return EXIT_FAILURE;

    // Play the music
    music.Play();
        

    // Start the game loop
    while (window.IsOpened())
    {
    	// Process events
    	sf::Event event;
    	while (window.PollEvent(event))
    	{
    		// Close window : exit
    		if (event.Type == sf::Event::Closed)
    			window.Close();
            
    		// Escape pressed : exit
    		if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Keyboard::Escape)
    			window.Close();
    	}

    	// Clear screen
    	window.Clear();
    	
    	// Draw the sprite
    	window.Draw(sprite);
    	
    	// Draw the string
    	window.Draw(text);

    	// Update the window
    	window.Display();
    }

	return EXIT_SUCCESS;
}
