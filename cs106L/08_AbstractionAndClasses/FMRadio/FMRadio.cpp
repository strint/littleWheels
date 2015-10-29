#include "FMRadio.h"

FMRadio::FMRadio() {
    initialize(87.5, 5);
}
FMRadio::FMRadio(double freq, int vol) {
    initialize(freq, vol);
}
void FMRadio::initialize(double freq, int vol) {
    for(size_t i = 0; i < 6; ++i)
        presets[i] = 0.0;
    frequency = freq;
    volume    = vol;
}
void FMRadio::checkFrequency(double freq) {
    assert(freq >= 87.5 && freq <= 108.8);
}

void FMRadio::checkPreset(int index) {
    assert(index >= 1 && index <= 6);
}
double FMRadio::getFrequency() {
    return frequency;
}
void FMRadio::setFrequency(double newFreq) {
    checkFrequency(newFreq);
    frequency = newFreq;
}

void FMRadio::setPreset(int index, double freq) {
    checkPreset(index);
    checkFrequency(freq);
    presets[index - 1] = freq;
}

bool FMRadio::presetExists(int index) {
    checkPreset(index);
    return presets[index - 1] == 0.0;
}
double FMRadio::getPreset(int index) {
    checkPreset(index);
    return presets[index – 1];
}
