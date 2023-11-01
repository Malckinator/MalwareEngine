#pragma once

#include "Vector.h"
#include "Matrix.h"

#include <string>

namespace std {
	template<typename T>
	inline std::string to_string(MWATH::Vec2<T>& x) {
		std::stringstream ss;

		ss << "[";
		ss << to_string(x.x);
		ss << ", ";
		ss << to_string(x.y);
		ss << "]";

		return ss.str();
	}

	template<typename T>
	inline std::string to_string(MWATH::Matrix4x4<T>& mat) {
		std::stringstream ss;

		for (uint8 y = 0; y < 4; y++) {
			ss << "[";

			for (uint8 x = 0; x < 4; x++) {
				ss << std::to_string(mat[x][y]);

				if (x != 3) {
					ss << ", ";
				}
			}

			ss << "]\n";
		}

		return ss.str();
	}
}