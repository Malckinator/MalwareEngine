#pragma once

#include "Core.h"
#include "ToString.h"

#include <sstream>
#include <vector>

namespace Logger {
	namespace Color {
		enum Type : uint8 {
			Black			= 0x0,
			Blue			= 0x1,
			Green			= 0x2,
			Aqua			= 0x3,
			Red				= 0x4,
			Purple			= 0x5,
			Yellow			= 0x6,
			White			= 0x7,
			Gray			= 0x8,
			LightBlue		= 0x9,
			LightGreen		= 0xA,
			LightAqua		= 0xB,
			LightRed		= 0xC,
			LightPurple		= 0xD,
			LightYellow		= 0xE,
			BrightWhite		= 0xF,
			None = Black
		};

		uint8 MakeColor(uint8 foreground, uint8 background);
		uint8 GetForeground(uint8 color);
		uint8 GetBackground(uint8 color);
	}

	void SetConsoleColor(uint8 color);

	namespace Core {
		std::string StringFormat(std::string format, const std::vector<std::string>& args, bool* error);

		template<typename T>
		inline void ArgsToString(std::vector<std::string>& toReturn, T x);

		template<typename T, typename... Args>
		inline void ArgsToString(std::vector<std::string>& toReturn, T x, Args... args);
	}

	template<typename... Args>
	inline std::string Format(std::string format);

	template<typename... Args>
	inline std::string Format(std::string format, Args... args);
}

#include "Printing.ipp"