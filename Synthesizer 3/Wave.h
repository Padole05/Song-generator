#pragma once
#include"const.h"
#include"WaveFileHeader.h"

template<typename T>
class Wave: public WaveFileHeader
{
protected:
	WaveFileHeader header;
	T* pData;
public:
	Wave() :WaveFileHeader() 
	{
		header.bitsPerSample = sizeof(T) * 8; 
		int nDataSize = 1 * sizeof(T);
		header.chunkSize = nDataSize + 36;
		header.subChunk2Size = nDataSize;
	};
	Wave(float* pRawData, int32 nNumSamples, int16 nNumChannels, int32 nSampleRate) :WaveFileHeader(nNumChannels, nSampleRate)
	{
		pData= new T[nNumSamples];
		for (int nIndex = 0; nIndex < nNumSamples; ++nIndex)
			ConvertFloatToAudioSample(pRawData[nIndex], pData[nIndex]);
		header.bitsPerSample = sizeof(T) * 8;
		int nDataSize = nNumSamples * sizeof(T);
		header.chunkSize = nDataSize + 36;
		header.subChunk2Size = nDataSize;
	};
	Wave(T* pDat, WaveFileHeader& head) :pData(pDat), header(head) {};

	~Wave() { delete pData; };


};

//0 to 255
void ConvertFloatToAudioSample(float fFloat, uint8& nOut);

//-32,768 to 32,767
void ConvertFloatToAudioSample(float fFloat, int16& nOut);

//-2,147,483,648 to 2,147,483,647
void ConvertFloatToAudioSample(float fFloat, int32& nOut);

//calculate the frequency of the specified note.
//fractional notes allowed!
/*
	frequency = 440(2^(n/12))
	N=0 is A4
	N=1 is A#4
	0  = A
	1  = A#
	2  = B
	3  = C
	4  = C#
	5  = D
	6  = D#
	7  = E
	8  = F
	9  = F#
	10 = G
	11 = G#
*/
float CalcFrequency(float fOctave, float fNote);


template<typename T>
//write .WAV file
bool WriteWaveFile(const char* szFileName,  Wave<T>& wave);


//pass in the current phase, frequency, and sample rate, and these tone generation functions
//will advance the phase and return the sample for that phase
float AdvanceOscilator_Sine(float& fPhase, float fFrequency, float fSampleRate);

float* createWave(int nNumSamples, float fFrequency, int nSampleRate, float fPhase)
{
	float* pData = new float[nNumSamples];
	for (int nIndex = 0; nIndex < nNumSamples; ++nIndex)
	{
		pData[nIndex] = AdvanceOscilator_Sine(fPhase, fFrequency, (float)nSampleRate);
	}
	return pData;
}

