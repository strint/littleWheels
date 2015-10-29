#include <iostream>
#include "FMRadio.h"
using namespace std;

int main() {
    FMRadio myRadio;
    myRadio.setFrequency(88.5);
    myRadio.setVolume(8);
    myRadio.setPreset(1, 90);

    cout << "Frequency:" << getFrequency() << endl;
    cout << "Volume:" << getVolume() << endl;
    cout << "Preset:" << getPreset(1) << endl;

    return 0;
}
