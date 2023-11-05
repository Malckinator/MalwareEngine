#pragma once

#include "Core.h"
#include "Utils.h"

#define VEC2_OPERATOR(op) inline Vec2<T>& operator op(Vec2<T>& other) { other.x op= this->x; other.y op= this->y; return other; }
#define VEC3_OPERATOR(op) inline Vec3<T>& operator op(Vec3<T>& other) { other.x op= this->x; other.y op= this->y; other.z op= this->z; return other; }
#define VEC4_OPERATOR(op) inline Vec4<T>& operator op(Vec4<T>& other) { other.x op= this->x; other.y op= this->y; other.z op= this->z; other.w op= this->w; return other; }

#define VEC2_SINGLE_OPERATOR(op) inline Vec2<T>& operator op(T other) { return Vec2<T>(this->x op other, this->y op other); }
#define VEC3_SINGLE_OPERATOR(op) inline Vec3<T>& operator op(T other) { return Vec3<T>(this->x op other, this->y op other, this->z op other); }
#define VEC4_SINGLE_OPERATOR(op) inline Vec4<T>& operator op(T other) { return Vec4<T>(this->x op other, this->y op other, this->z op other, this->w op other); }

namespace MWATH {
	template<typename T>
	class Vec2 {
	public:
		inline Vec2() {
			x = 0;
			y = 0;
		}

		inline Vec2(T _x) {
			x = _x;
			y = _x;
		}

		inline Vec2(T _x, T _y) {
			x = _x;
			y = _y;
		}

		union {
			T x;
			T u;
		};

		union {
			T y;
			T v;
		};

		inline T Sum() {
			return x + y;
		}

		inline T Length() {
			return Sqrt(Pow(x, 2) + Pow(y, 2));
		}

		inline Vec2<T> Normalize() {
			return this / Length();
		}

		VEC2_OPERATOR(+);
		VEC2_OPERATOR(-);
		VEC2_OPERATOR(*);
		VEC2_OPERATOR(/);

		VEC2_SINGLE_OPERATOR(+);
		VEC2_SINGLE_OPERATOR(-);
		VEC2_SINGLE_OPERATOR(*);
		VEC2_SINGLE_OPERATOR(/);
	};

	template<typename T>
	class Vec3 {
	public:
		inline Vec3() {
			x = 0;
			y = 0;
			z = 0;
		}

		inline Vec3(T _x) {
			x = _x;
			y = _x;
			z = _x;
		}

		inline Vec3(T _x, T _y, T _z) {
			x = _x;
			y = _y;
			z = _z;
		}

		inline Vec3(Vec2<T> _x, T _z) {
			x = _x.x;
			y = _x.y;
			z = _z;
		}

		union {
			T x;
			T u;
		};

		union {
			T y;
			T v;
		};

		T z;

		inline T Sum() {
			return x + y + z;
		}

		inline T Length() {
			return Sqrt(Pow(x, (T) 2) + Pow(y, (T) 2) + Pow(z, (T) 2));
		}

		inline Vec3<T> Normalize() {
			return *this / Length();
		}

		VEC3_OPERATOR(+);
		VEC3_OPERATOR(-);
		VEC3_OPERATOR(*);
		VEC3_OPERATOR(/);

		VEC3_SINGLE_OPERATOR(+);
		VEC3_SINGLE_OPERATOR(-);
		VEC3_SINGLE_OPERATOR(*);
		VEC3_SINGLE_OPERATOR(/);
	};

	template<typename T>
	class Vec4 {
	public:
		inline Vec4() {
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}

		inline Vec4(T _x) {
			x = _x;
			y = _x;
			z = _x;
			w = _x;
		}

		inline Vec4(T _x, T _y, T _z, T _w) {
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}

		inline Vec4(T* array) {
			x = array[0];
			y = array[1];
			z = array[2];
			w = array[3];
		}

		inline Vec4(Vec2<T> _x, T _z, T _w) {
			x = _x.x;
			y = _x.y;
			z = _z;
			w = _w;
		}

		inline Vec4(T _x, T _y, Vec2<T> _z) {
			x = _x;
			y = _y;
			z = _z.x;
			w = _z.y;
		}

		inline Vec4(T _x, Vec2<T> _y, T _w) {
			x = _x;
			y = _y.x;
			z = _y.y;
			w = _w;
		}

		inline Vec4(Vec3<T>& _x, T _w) {
			x = _x.x;
			y = _x.y;
			z = _x.z;
			w = _w;
		}

		inline Vec4(T _x, Vec3<T>& _y) {
			x = _x;
			y = _y.x;
			z = _y.y;
			w = _y.z;
		}

		union {
			T x;
			T u;
		};

		union {
			T y;
			T v;
		};

		T z;
		T w;

		inline T Sum() {
			return x + y + z + w;
		}

		inline T Length() {
			return Sqrt(Pow(x, 2) + Pow(y, 2) + Pow(z, 2));
		}

		inline Vec4<T> Normalize() {
			return this / Length();
		}

		VEC4_OPERATOR(+);
		VEC4_OPERATOR(-);
		VEC4_OPERATOR(*);
		VEC4_OPERATOR(/);

		VEC4_SINGLE_OPERATOR(+);
		VEC4_SINGLE_OPERATOR(-);
		VEC4_SINGLE_OPERATOR(*);
		VEC4_SINGLE_OPERATOR(/);
	};

	template<typename T>
	T Dot(Vec2<T>& a, Vec2<T>& b) {
		return (a * b).Sum();
	}

	template<typename T>
	T Dot(Vec3<T>& a, Vec3<T>& b) {
		return (a * b).Sum();
	}

	template<typename T>
	T Dot(Vec4<T>& a, Vec4<T>& b) {
		return (a * b).Sum();
	}

	template<typename T>
	inline Vec3<T> Cross(Vec3<T>& x, Vec3<T>& y) {
		return Vec3<T>(
			x.y * y.z - y.y * x.z,
			x.z * y.x - y.z * x.x,
			x.x * y.y - y.x * x.y
		);
	}
	
	typedef Vec2<float> Float2;
	typedef Vec3<float> Float3;
	typedef Vec4<float> Float4;

	typedef Vec2<int32> Int2;
	typedef Vec3<int32> Int3;
	typedef Vec4<int32> Int4;
}

#undef VEC2_OPERATOR
#undef VEC3_OPERATOR
#undef VEC4_OPERATOR

#undef VEC2_SINGLE_OPERATOR
#undef VEC3_SINGLE_OPERATOR
#undef VEC4_SINGLE_OPERATOR