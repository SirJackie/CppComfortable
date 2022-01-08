#ifndef __CppComfortable_ThreeD_H__
#define __CppComfortable_ThreeD_H__

#include "MathTools.h"

// ar for Aspect Ratio
// sw for Screen Width
// sh for Screen Height

float FPubeX(float x, float ar, float sw);
float FPubeY(float y, float sh);
float FExpandX(float x, float fovY);
float FExpandY(float y, float fovY);

#endif

