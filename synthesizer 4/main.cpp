#include"const.h"
#include"WaveFileHeader.h"
#include"AudioConverter.h"
#include"Oscillator.h"
#include"SineWaveGenerator.h"
#include"WaveFileWriter.h"






int main(int argc, char** argv) {
    int sampleRate = 44100;
    int numSeconds = 4;
    int numChannels = 1;
    Oscillator oscillator;
    float frequency = oscillator.calcFrequency(4, 3); // middle C

    SineWaveGenerator generator(sampleRate, numSeconds, numChannels, frequency);
    std::vector<float> data = generator.generate();

    WaveFileWriter<int16> writer("sinenaive.wav", data.size(), numChannels, sampleRate);
    writer.write(data);

    return 0;
}
