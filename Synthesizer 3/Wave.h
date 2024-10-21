#pragma once
#include"const.h"

//define types
typedef int int32;
typedef unsigned int uint32;
typedef short int16;
typedef unsigned short uint16;
typedef signed char int8;
typedef unsigned char uint8;


//WAVE file header

class WaveFileHeader
{
	//1. main chuck
	uint8 chunkID[4]; //"RIFF"
	uint32 chunkSize; //subChunk2Size+36
	uint8 format[4]; //"WAVE"

};
