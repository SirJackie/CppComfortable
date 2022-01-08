#ifndef __CppComfortable_MathTools_H__
#define __CppComfortable_MathTools_H__

#include <cmath>

using std::cos;
using std::sin;
using std::tan;

using std::asin;
using std::acos;
using std::atan;

#define clamp(min, x, max) (x < min ? min : x >= max ? max - 1 : x)

#define DEG2RAD (PI / 180.0f)
#define RAD2DEG (180.0f / PI)

// sin, cos, tan, asin, acos, atan using degree

#define sind(x) (sin(x * DEG2RAD))
#define cosd(x) (cos(x * DEG2RAD))
#define tand(x) (tan(x * DEG2RAD))

#define asind(x) (asin(x) * RAD2DEG)
#define acosd(x) (acos(x) * RAD2DEG)
#define atand(x) (atan(x) * RAD2DEG)

#endif

