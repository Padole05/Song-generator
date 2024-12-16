#pragma once
#include"WaveGenerator.h"

class SineWaveGenerator : public WaveGenerator {
public:
    SineWaveGenerator(int sampleRate, int numSeconds, int numChannels, float frequency)
        : WaveGenerator(sampleRate, numSeconds, numChannels), frequency(frequency) {
    }

    std::vector<float> generate() const override;

private:
    float frequency;
};