#include"const.h"
#include "Oscillator.h"

float Oscillator::calcFrequency(float fOctave, float fNote) const
{
    return static_cast<float>(440 * std::pow(2.0, ((fOctave - 4) * 12 + fNote) / 12.0));
}

float Oscillator::advanceSine(float& fPhase, float fFrequency, float fSampleRate) const
{
    fPhase += 2 * static_cast<float>(M_PI) * fFrequency / fSampleRate;
    while (fPhase >= 2 * static_cast<float>(M_PI))
        fPhase -= 2 * static_cast<float>(M_PI);
    while (fPhase < 0)
        fPhase += 2 * static_cast<float>(M_PI);
    return std::sin(fPhase);
}
