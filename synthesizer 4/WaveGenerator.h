#pragma once
#include"const.h"
class WaveGenerator {
public:
    WaveGenerator(int sampleRate, int numSeconds, int numChannels)
        : sampleRate(sampleRate), numSeconds(numSeconds), numChannels(numChannels) {
    }

    virtual std::vector<float> generate() const = 0;

protected:
    int sampleRate;
    int numSeconds;
    int numChannels;
};