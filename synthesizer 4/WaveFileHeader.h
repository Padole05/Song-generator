#pragma once

class WaveFileHeader {
public:
    WaveFileHeader(int32 dataSize, int16 numChannels, int32 sampleRate, int32 bitsPerSample);

    void writeToFile(std::ofstream& file) const;

private:
    unsigned char chunkID[4];
    uint32 chunkSize;
    unsigned char format[4];

    unsigned char subChunk1ID[4];
    uint32 subChunk1Size;
    uint16 audioFormat;
    uint16 numChannels;
    uint32 sampleRate;
    uint32 byteRate;
    uint16 blockAlign;
    uint16 bitsPerSample;

    unsigned char subChunk2ID[4];
    uint32 subChunk2Size;
};