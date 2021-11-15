#include <iostream>
#include <fstream>
#include "AudioFile/AudioFile.h"
#include <math.h>
using namespace std;

int main(int argc, char** argv){

    AudioFile<double> audioOrigin;
    AudioFile<double> audioNoise;
    audioOrigin.load(argv[1]);      //File without noise
    audioNoise.load(argv[2]);       //File with noise

    
    int numSamples = audioOrigin.getNumSamplesPerChannel();
    int numChannels = audioOrigin.getNumChannels();

    double energy = 0;
    double energyNoise = 0;

    for(int i=0; i<numChannels; i++){ 
        for(int j=0; j<numSamples; j++){ 
            energy += pow(audioOrigin.samples[i][j], 2);                                    //E[x] = Σ x(n)²
            energyNoise += pow (audioOrigin.samples[i][j]- audioNoise.samples[i][j], 2);    //E[r] = Σ(x(n)- Xnoise(n))²
        }
    }
    double snr = 10 * log10(energy/energyNoise);
    cout << "Signal-to-noise ratio equals: " << snr << " dB(decibel)" << endl;
    
    return 0;
}