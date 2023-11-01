#include "Printing.h"

#ifdef PLATFORM_WINDOWS

#include "Platform/Windows/WindowsPrinting.h"

#endif

namespace Logger {
	namespace Color {
		uint8 MakeColor(uint8 foreground, uint8 background) {
			return foreground + (background << 4);
		}

		uint8 GetForeground(uint8 color) {
			return color << 4 >> 4;
		}

		uint8 GetBackground(uint8 color) {
			return color >> 4;
		}
	}

	void SetConsoleColor(uint8 color) {
		#ifdef PLATFORM_WINDOWS

		Windows::SetConsoleColor(color);

		#endif
	}

	std::string Core::StringFormat(std::string format, const std::vector<std::string>& args, bool* error) {
		std::stringstream ss;
		bool bracket = false;
		std::stringstream inside;

		for (char c : format) {
			if (c == '{') {
				if (bracket) {
					if (error != nullptr)
						*error = true;

					return "Format: Can't nest brackets inside format.";
				}

				bracket = true;
			} else if (c == '}') {
				if (!bracket) {
					if (error != nullptr)
						*error = true;

					return "Format: Can't have close bracket without open bracket.";
				}

				bracket = false;
				std::string insideStr = inside.str();

				if (insideStr == "{" || insideStr == "}") {
					ss << insideStr;
					continue;
				}

				int num = strtol(inside.str().c_str(), nullptr, 10);
				if (num >= 0 && num < args.size()) {
					ss << args[num];
				} else {
					if (error != nullptr)
						*error = true;

					return StringFormat("Format: No argument with number '{0}'.", { std::to_string(num) }, nullptr);
				}

				inside = std::stringstream();
			} else {
				if (bracket) {
					inside << c;
					continue;
				}

				ss << c;
			}
		}

		return ss.str();
	}
}