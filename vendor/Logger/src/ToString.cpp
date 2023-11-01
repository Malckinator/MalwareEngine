#include "ToString.h"

namespace std {
	std::string to_string(std::string x) {
		return x;
	}

	std::string to_string(const char* x) {
		return std::string(x);
	}
}