#pragma once
class AudioConverter {
public:
    template <typename T>
    void convert(float fFloat, T& nOut) const;

private:
    void clamp(float& value, float min, float max) const;

    void clamp(double& value, double min, double max) const;
};