#include "Profile.h"
#include <stdexcept>

#ifndef LOGGER_EXIT

#define LOGGER_EXIT(x) throw std::runtime_error(x)

#endif

#ifndef LOG_COLOR
#define LOG_COLOR Logger::Color::Green
#endif

#ifndef TRACE_COLOR
#define TRACE_COLOR Logger::Color::White
#endif

#ifndef WARN_COLOR
#define WARN_COLOR Logger::Color::Yellow
#endif

#ifndef ERROR_COLOR
#define ERROR_COLOR Logger::Color::Red
#endif

namespace Logger {
	template<typename... Args>
	inline void Profile::Log(std::string format, Args... args) {
		InternalPrint("Log", LOG_COLOR, format, args...);
	}

	template<typename... Args>
	inline void Profile::Trace(std::string format, Args... args) {
		InternalPrint("Trace", TRACE_COLOR, format, args...);
	}

	template<typename... Args>
	inline void Profile::Warn(std::string format, Args... args) {
		InternalPrint("Warn", WARN_COLOR, format, args...);
	}

	template<typename... Args>
	inline void Profile::Error(std::string format, Args... args) {
		std::string message = Format(format, args...);

		InternalPrint("Error", ERROR_COLOR, message);

		LOGGER_EXIT(message);
	}

	template<typename... Args>
	inline void Profile::Assert(bool condition, std::string format, Args... args) {
		if (!condition) {
			Error(format, args...);
		}
	}

	template<typename... Args>
	inline void Profile::WarnAssert(bool condition, std::string format, Args... args) {
		if (!condition) {
			Warn(format, args...);
		}
	}

	// No Args

	inline void Profile::Log(std::string format) {
		InternalPrint("Log", LOG_COLOR, format);
	}

	inline void Profile::Trace(std::string format) {
		InternalPrint("Trace", TRACE_COLOR, format);
	}

	inline void Profile::Warn(std::string format) {
		InternalPrint("Warn", WARN_COLOR, format);
	}

	inline void Profile::Error(std::string format) {
		InternalPrint("Error", ERROR_COLOR, format);

		LOGGER_EXIT(format);
	}

	inline void Profile::Assert(bool condition, std::string format) {
		if (!condition) {
			Error(format);
		}
	}

	inline void Profile::WarnAssert(bool condition, std::string format) {
		if (!condition) {
			Warn(format);
		}
	}

	template<typename... Args>
	inline void Profile::InternalPrint(std::string type, uint8 foreground, std::string format, Args... args) {
		InternalPrint(type, foreground, Format(format, args...));
	}

	inline void Profile::InternalPrint(std::string type, uint8 foreground, std::string format) {
		std::stringstream message;

		if (name.size() != 0) {
			message << "[" << name << "]";
		}

		message << "[" << type << "]: ";
		uint8 spaceCount = (uint32) message.str().size();

		for (uint32 i = 0; i < format.size(); i++) {
			if (format[i] == '\n') {
				message << '\n';

				for (uint8 u = 0; u < spaceCount; u++) {
					message << ' ';
				}
			} else {
				message << format[i];
			}
		}

		message << '\n';

		Print(message.str(), foreground);
	}
}