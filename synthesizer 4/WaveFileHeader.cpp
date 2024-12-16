#include"const.h"
#include "WaveFileHeader.h"

WaveFileHeader::WaveFileHeader(int32 dataSize, int16 numChannels, int32 sampleRate, int32 bitsPerSample)
{
    std::memcpy(chunkID, "RIFF", 4);
    chunkSize = dataSize + 36;
    std::memcpy(format, "WAVE", 4);
    std::memcpy(subChunk1ID, "fmt ", 4);
    subChunk1Size = 16;
    audioFormat = 1;
    this->numChannels = numChannels;
    this->sampleRate = sampleRate;
    byteRate = sampleRate * numChannels * bitsPerSample / 8;
    blockAlign = numChannels * bitsPerSample / 8;
    this->bitsPerSample = bitsPerSample;
    std::memcpy(subChunk2ID, "data", 4);
    subChunk2Size = dataSize;
}

void WaveFileHeader::writeToFile(std::ofstream& file) const
{
    file.write(reinterpret_cast<const char*>(this), sizeof(WaveFileHeader));
}
