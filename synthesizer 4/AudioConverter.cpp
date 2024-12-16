#include "AudioConverter.h"
#include"const.h"

void AudioConverter::clamp(float& value, float min, float max) const
{
    if (value < min) { value = min; }
    else if (value > max) { value = max; }
}

void AudioConverter::clamp(double& value, double min, double max) const
{
    if (value < min) { value = min; }
    else if (value > max) { value = max; }
}


template <>
void AudioConverter::convert(float fFloat, uint8& nOut) const {
    fFloat = (fFloat + 1.0f) * 127.5f;
    clamp(fFloat, 0.0f, 255.0f);
    nOut = static_cast<uint8>(fFloat);
}

template <>
void AudioConverter::convert(float fFloat, int16& nOut) const {
    fFloat *= 32767.0f;
    clamp(fFloat, -32768.0f, 32767.0f);
    nOut = static_cast<int16>(fFloat);
}

template <>
void AudioConverter::convert(float fFloat, int32& nOut) const {
    double dDouble = static_cast<double>(fFloat);
    dDouble *= 2147483647.0;
    clamp(dDouble, -2147483648.0, 2147483647.0);
    nOut = static_cast<int32>(dDouble);
}
