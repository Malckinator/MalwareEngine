#include "WindowsPrinting.h"

namespace Logger::Windows {
	void Logger::Windows::SetConsoleColor(uint8 color) {
		SetConsoleTextAttribute(
			GetStdHandle(STD_OUTPUT_HANDLE),
			color
		);
	}
}