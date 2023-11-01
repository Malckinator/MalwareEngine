#include "Profile.h"

#include <iostream>

namespace Logger {
	Profile::Profile(std::string name, uint8 background) {
		this->name = name;
		this->background = Color::MakeColor(Color::None, background);
	}

	Profile::~Profile() {

	}

	void Profile::Print(std::string str, uint8 color) {
		SetConsoleColor(color + background);

		std::cout << str;

		SetConsoleColor(Color::MakeColor(Color::White, Color::Black));
	}
}