#pragma once

#include "Core.h"
#include "Printing.h"

#include <string>

namespace Logger {
	class Profile {
	public:
		Profile(std::string name, uint8 background);
		~Profile();

		void Print(std::string str, uint8 color = Color::White);
		
		template<typename... Args>
		inline void Log(std::string format, Args... args);

		template<typename... Args>
		inline void Trace(std::string format, Args... args);

		template<typename... Args>
		inline void Warn(std::string format, Args... args);

		template<typename... Args>
		inline void Error(std::string format, Args... args);

		template<typename... Args>
		inline void Assert(bool condition, std::string format, Args... args);

		template<typename... Args>
		inline void WarnAssert(bool condition, std::string format, Args... args);

		inline void Log(std::string format);
		inline void Trace(std::string format);
		inline void Warn(std::string format);
		inline void Error(std::string format);
		inline void Assert(bool condition, std::string format);
		inline void WarnAssert(bool condition, std::string format);
	private:
		template<typename... Args>
		inline void InternalPrint(std::string type, uint8 foregorund, std::string format, Args... args);
		inline void InternalPrint(std::string type, uint8 foregorund, std::string format);

		std::string name;
		uint8 background;
	};
}

#include "Profile.ipp"