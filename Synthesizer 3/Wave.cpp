#include"Wave.h"
#include <math.h>


void ConvertFloatToAudioSample(float fFloat, uint8& nOut)
{
	fFloat = (fFloat + 1.0f) * 127.5f;
	CLAMP(fFloat, 0.0f, 255.0f);
	nOut = (uint8)fFloat;
}

void ConvertFloatToAudioSample(float fFloat, int16& nOut)
{
	fFloat *= 32767.0f;
	CLAMP(fFloat, -32768.0f, 32767.0f);
	nOut = (int16)fFloat;
}

void ConvertFloatToAudioSample(float fFloat, int32& nOut)
{
	double dDouble = (double)fFloat;
	dDouble *= 2147483647.0;
	CLAMP(dDouble, -2147483648.0, 2147483647.0);
	nOut = (int32)dDouble;
}



float CalcFrequency(float fOctave, float fNote)
{
	return (float)(440 * pow(2.0, ((double)((fOctave - 4) * 12 + fNote)) / 12.0));
}


template<typename T>
inline bool WriteWaveFile(const char* szFileName, Wave<T>& wave)
{
	FILE* File = fopen(szFileName, "w+b");
	if (!File)
	{
		return false;
	}

	//write header
	fwrite(&wave.header, sizeof(WaveFileHeader), 1, File);
	//write wave data
	fwrite(wave.pData, wave.header.subChunk2Size, 1, File);

	fclose(File);
	return true;
}





float AdvanceOscilator_Sine(float& fPhase, float fFrequency, float fSampleRate)
{
	fPhase += 2 * (float)M_PI * fFrequency / fSampleRate;

	while (fPhase >= 2 * (float)M_PI)
		fPhase -= 2 * (float)M_PI;

	while (fPhase < 0)
		fPhase += 2 * (float)M_PI;

	return sin(fPhase);
}




