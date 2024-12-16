#include "SineWaveGenerator.h"

std::vector<float> SineWaveGenerator::generate() const
{
    int numSamples = sampleRate * numChannels * numSeconds;
    std::vector<float> data(numSamples);
    float phase = 0;

    for (int nIndex = 0; nIndex < numSamples; ++nIndex) {
        data[nIndex] = std::sin(static_cast<float>(nIndex) * 2 * static_cast<float>(M_PI) * frequency / static_cast<float>(sampleRate));
    }

    return data;
}
