#include <SFML\Graphics.hpp> // Include libriary SFML here.

// Realization Scral Display here:

sf::View view; // Announced SFML object view (it is a camera) OBJECT.

sf::View GetPlayerCordinate(float x, float y)
{
  // Function for reading player coordinates:

	view.setCenter(x + 100, y); // Follow the player passing his coordinates.
	return view; // Return our camera if PLayer changed the X and Y coordinate
}
