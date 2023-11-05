#pragma once

#include "Core.h"
#include "Vector.h"

namespace MWATH {
	template<typename T>
	class Matrix4x4 {
	public:
		inline Matrix4x4() {
			for (uint8 x = 0; x < 4; x++) {
				for (uint8 y = 0; y < 4; y++) {
					data[x][y] = static_cast<T>(1);
				}
			}
		}

		inline Matrix4x4(T d) {
			for (uint8 x = 0; x < 4; x++) {
				for (uint8 y = 0; y < 4; y++) {
					data[x][y] = d;
				}
			}
		}

		inline Vec4<T>& GetRow(uint8 index) {
			return Vec4<T>(data[index]);
		}

		inline Vec4<T>& GetColumn(uint8 index) {
			Vec4<T> result(static_cast<T>(0));

			result.x = data[index][0];
			result.y = data[index][1];
			result.z = data[index][2];
			result.w = data[index][3];

			return result;
		}

		inline T* operator [](uint8 x) {
			return data[x];
		}

		inline Matrix4x4<T> operator*(T scaler) {
			Matrix4x4<T> result(static_cast<T>(0));

			for (uint8 x = 0; x < 4; x++) {
				for (uint8 y = 0; y < 4; y++) {
					result[x][y] = data[x][y] * scaler;
				}
			}

			return result;
		}

		inline Matrix4x4<T> operator*(Matrix4x4<T>& other) {
			Matrix4x4<T> result(0);

			for (uint8 x = 0; x < 4; x++) {
				for (uint8 y = 0; y < 4; y++) {
					Vec4<T> row = GetRow(x);
					Vec4<T> column = other.GetColumn(y);

					result[x][y] = Dot(row, column);
				}
			}

			return result;
		}
	private:
		T data[4][4];
	};

	template<typename T>
	inline Matrix4x4<T> Translate(Vec3<T>& vector) {
		Matrix4x4<T> result(0);

		result[0][0] = 1;
		result[1][1] = 1;
		result[2][2] = 1;
		result[3][3] = 1;
		result[3][0] = vector.x;
		result[3][1] = vector.y;
		result[3][2] = vector.z;

		return result;
	}

	template<typename T>
	inline Matrix4x4<T> Scale(Vec3<T>& vector) {
		Matrix4x4<T> result(0);

		result[0][0] = vector.x;
		result[1][1] = vector.y;
		result[2][2] = vector.z;
		result[3][3] = 1;

		return result;
	}

	template<typename T>
	inline Matrix4x4<T> RotateX(T angle) {
		Matrix4x4<T> result(0);

		T cosTheta = cos((long double) angle);
		T sinTheta = sin((long double) angle);

		result[0][0] = 1;
		result[3][3] = 1;
		result[1][1] = cosTheta;
		result[2][1] = -sinTheta;
		result[1][2] = sinTheta;
		result[2][2] = cosTheta;

		return result;
	}

	template<typename T>
	inline Matrix4x4<T> RotateY(T angle) {
		Matrix4x4<T> result(0);

		T cosTheta = cos((long double) angle);
		T sinTheta = sin((long double) angle);

		result[0][0] = cosTheta;
		result[2][0] = sinTheta;
		result[1][1] = 1;
		result[0][2] = -sinTheta;
		result[2][2] = cosTheta;

		return result;
	}

	template<typename T>
	inline Matrix4x4<T> RotateZ(T angle) {
		Matrix4x4<T> result(0);

		T cosTheta = cos((long double) angle);
		T sinTheta = sin((long double) angle);

		result[0][0] = cosTheta;
		result[1][0] = -sinTheta;
		result[0][1] = sinTheta;
		result[1][1] = cosTheta;
		result[2][2] = 1;
		result[3][3] = 1;

		return result;
	}

	template<typename T>
	inline Matrix4x4<T> RotateXYZ(Vec3<T> vector) {
		Matrix4x4<T> result = RotateX(vector.x);
		result = result * RotateY(vector.y);
		result = result * RotateZ(vector.z);

		return result;
	}

	template<typename T>
	inline Matrix4x4<T> Orthographic(T left, T right, T bottom, T top, T zNear, T zFar) {
		Matrix4x4<T> Result(1);

		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = -static_cast<T>(2) / (zFar - zNear);
		Result[3][0] = -(right + left) / (right - left);
		Result[3][1] = -(top + bottom) / (top - bottom);
		Result[3][2] = -(zFar + zNear) / (zFar - zNear);

		return Result;
	}

	template<typename T>
	inline Matrix4x4<T> Perspective(T fov, T aspectRatio, T near, T far) {
		T tanHalfFov = tan(fov / static_cast<T>(2));

		Matrix4x4<T> result(static_cast<T>(0));
		result[0][0] = static_cast<T>(1) / (aspectRatio * tanHalfFov);
		result[1][1] = static_cast<T>(-1) / (tanHalfFov);
		result[2][2] = -(far + near) / (far - near);
		result[2][3] = -static_cast<T>(1);
		result[3][2] = -(static_cast<T>(2) * far * near) / (far - near);

		return result;
	}

	template<typename T>
	inline Matrix4x4<T> LookAt(Vec3<T>& eye, Vec3<T>& center, Vec3<T>& up) {
		Vec3<T> f = (center - eye).Normalize();
		Vec3<T> s = Cross(f, up).Normalize();
		Vec3<T> u = Cross(s, f);

		Matrix4x4<T> result(1);
		result[0][0] = s.x;
		result[1][0] = s.y;
		result[2][0] = s.z;
		result[0][1] = u.x;
		result[1][1] = u.y;
		result[2][1] = u.z;
		result[0][2] = -f.x;
		result[1][2] = -f.y;
		result[2][2] = -f.z;
		result[3][0] = -Dot(s, eye);
		result[3][1] = -Dot(u, eye);
		result[3][2] = Dot(f, eye);
		return result;
	}

	typedef Matrix4x4<float> Float4x4;
}