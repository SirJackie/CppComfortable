#include "ThreeD.h"

float FPube(float x, float ar, float sw){
	return ((x + ar) / (2.0f * ar)) * sw;
}

float FPube(float y, float sh){
	return ((1-y) / 2.0f) * sh;
}

