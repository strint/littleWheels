#ifndef FMRadio_Included
#define FMRadio_Included

class FMRadio
{
public:
    FMRadio();
    FMRadio(double freq, int vol);
    double getFrequency();
    void   setFrequency(double newFreq);

    int    getVolume();
    void   setVolume(int newVolume);

    double setPreset(int index, double freq);
    bool   presetExists(int index);
    double getPreset(int index);
private:
    void   checkFrequency(double freq);
    void   checkPreset(int index);
    void   initialize(double freq, int vol);
    double frequency;
    int    volume;
    double presets[6];
};

#endif
