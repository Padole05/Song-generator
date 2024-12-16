#pragma once


template <typename T>
class WaveFileWriter {
public:
    WaveFileWriter(const std::string& fileName, int32 numSamples, int16 numChannels, int32 sampleRate)
        : fileName(fileName), numSamples(numSamples), numChannels(numChannels), sampleRate(sampleRate) {
    }

    bool write(const std::vector<float>& rawData) const {
        std::ofstream file(fileName, std::ios::binary);
        if (!file.is_open()) {
            return false;
        }

        int32 bitsPerSample = sizeof(T) * 8;
        int dataSize = numSamples * sizeof(T);
        WaveFileHeader waveHeader(dataSize, numChannels, sampleRate, bitsPerSample);
        waveHeader.writeToFile(file);

        std::vector<T> data(numSamples);
        AudioConverter converter;
        for (int nIndex = 0; nIndex < numSamples; ++nIndex) {
            converter.convert(rawData[nIndex], data[nIndex]);
        }

        file.write(reinterpret_cast<const char*>(data.data()), dataSize);
        file.close();
        return true;
    }

private:
    std::string fileName;
    int32 numSamples;
    int16 numChannels;
    int32 sampleRate;
};
