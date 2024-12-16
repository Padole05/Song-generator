#pragma once
#include"const.h"

//WAVE file header

class WaveFileHeader
{
protected:
	//1. main chuck
	uint8		chunkID[5]; //="RIFF"
	uint32		chunkSize; //=subChunk2Size+36
	uint8		format[5]; //="WAVE"

	//2. sub chunk 1 "fmt "
	//can be compressed
	int8		subChunk1ID[5];	//="fmt "
	uint32		subChunk1Size;	//=16
	uint16		audioFormat;	//=1
	uint16		numChannels;	//eg. 1:monophonic; 2:stereo; 4:4c; ...
	uint32		sampleRate;		//frequency (hertz): sampleFrame/s
	uint32		byteRate;		//=sampleRate*blockAlign;	bytes/s -> guess size RAM buffer <-> playback WAV
	uint16		blockAlign;		//=numChannels*bitsPerSample/8;		size sampleFrame(bytes)
	uint16		bitsPerSample;	//bit resolution/sample Point

	//3. sub chunk 2 "data" - actual wave form
	//uncompressed
	int8		subChunk2ID[5];	//="data"
	uint32		subChunk2Size;

	//then comes the data: smp frames -> quantity = subChunk2Size/blockAlign...

public:
	//auto fill header
	WaveFileHeader() :chunkID("RIFF"), format("WAVE"), subChunk1ID("fmt "), subChunk1Size(16), audioFormat(1), subChunk2ID("data") {};
	WaveFileHeader(int16 nNumChannels, int32 nSampleRate) :chunkID("RIFF"), format("WAVE"), subChunk1ID("fmt "), subChunk1Size(16), audioFormat(1), subChunk2ID("data"), numChannels(nNumChannels), sampleRate(nSampleRate) {};

	~WaveFileHeader(){};
};
