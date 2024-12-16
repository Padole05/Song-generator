#pragma once
#include<stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <memory>

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define CLAMP(value,min,max) {if(value < min) { value = min; } else if(value > max) { value = max; }}

using namespace std;

typedef int int32;
typedef unsigned int uint32;
typedef short int16;
typedef unsigned short uint16;
typedef signed char int8;
typedef unsigned char uint8;
