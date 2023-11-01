#pragma once

#include "Core.h"

#include <cmath>

namespace MWATH {
	template<typename T>
	inline T Pi() {
		return static_cast<T>(3.141592653589793238462643383279502884197);
	}

	template<typename T>
	inline T Tau() {
		return static_cast<T>(Pi<T>() * 2);
	}

	template<typename T>
	inline T Sqrt(T x) {
		if (typeid(x) == typeid(float)) {
			return static_cast<T>(std::sqrtf(x));
		}

		return static_cast<T>(std::sqrt(static_cast<double>(x)));
	}

	template<typename T>
	inline T Pow(T x, T exponent) {
		if (typeid(x) == typeid(float) && typeid(exponent) == typeid(float)) {
			return static_cast<T>(std::powf(x, exponent));
		}

		return static_cast<T>(std::pow(static_cast<double>(x), static_cast<double>(exponent)));
	}

	template<typename T>
	inline T Sin(T x) {
		return static_cast<T>(std::sin(static_cast<float>(x)));
	}

	template<typename T>
	inline T Cos(T x) {
		return static_cast<T>(std::cos(static_cast<float>(x)));
	}

	template<typename T>
	inline T Tan(T x) {
		return static_cast<T>(std::tan(static_cast<float>(x)));
	}

	template<typename T>
	inline T Asin(T x) {
		return static_cast<T>(std::asin(static_cast<float>(x)));
	}

	template<typename T>
	inline T Atan(T x) {
		return static_cast<T>(std::asin(static_cast<float>(x)));
	}

	template<typename T>
	inline T Acos(T x) {
		return static_cast<T>(std::acos(static_cast<float>(x)));
	}	
}