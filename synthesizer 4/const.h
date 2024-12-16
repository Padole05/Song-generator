#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstring>
#define M_PI 3.14159265358979323846

#define CLAMP(value, min, max) { if (value < min) { value = min; } else if (value > max) { value = max; } }
using namespace std;

typedef int int32;
typedef unsigned int uint32;
typedef short int16;
typedef unsigned short uint16;
typedef signed char int8;
typedef unsigned char uint8;