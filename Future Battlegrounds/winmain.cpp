#include<iostream>
#include<SFML/Graphics.hpp>
#include<GL/glew.h>
#include<string.h>
#include<sstream>
#include<fstream>

int main() {
	sf::ContextSettings settings;
	settings.majorVersion = 3;
	settings.minorVersion = 3;
	settings.depthBits = 24;

	sf::RenderWindow window(sf::VideoMode(800, 600), "This is a game in OpenGL", sf::Style::Default, settings);
	window.setActive(true);

	glewExperimental = true;
	GLenum result = glewInit();
	if (result != GLEW_OK) {
		std::cout << "Problem: " << glewGetErrorString(result) << std::endl;
	}

	while (window.isOpen()) {
		sf::Event ev;
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.display();
	}

	return 0;
}