#pragma once
class Oscillator {
public:
    float calcFrequency(float fOctave, float fNote) const;

    float advanceSine(float& fPhase, float fFrequency, float fSampleRate) const;
};