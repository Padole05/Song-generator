
#include"Wave.h"

template<typename T>
int main()
{
	int nSampleRate = 44100;
	int nNumSeconds = 4;
	int nNumChannels = 1;
	float fFrequency = CalcFrequency(3, 3); // middle C

	//make our buffer to hold the samples
	int nNumSamples = nSampleRate * nNumChannels * nNumSeconds;
	float fPhase = 0;


	float* pData = createWave(nNumSamples,fFrequency,nSampleRate,fPhase);
	WaveFileHeader header();
	Wave<T> wave(pData, header);

	WriteWaveFile("try.wav", wave);
	return 0;
}