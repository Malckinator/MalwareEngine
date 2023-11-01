#include "Printing.h"

namespace Logger {
	namespace Core {
		template<typename T>
		inline void ArgsToString(std::vector<std::string>& toReturn, T x) {
			toReturn.push_back(std::to_string(x));
		}

		template<typename T, typename... Args>
		inline void ArgsToString(std::vector<std::string>& toReturn, T x, Args... args) {
			toReturn.push_back(std::to_string(x));

			if (sizeof...(Args) > 0) {
				ArgsToString(toReturn, args...);
			}
		}
	}

	template<typename... Args>
	inline std::string Format(std::string format) {
		return format;
	}

	template<typename... Args>
	inline std::string Format(std::string format, Args... args) {
		std::vector<std::string> sArgs;
		Core::ArgsToString(sArgs, args...);

		return Core::StringFormat(format, sArgs, nullptr);
	}
}