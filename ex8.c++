#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <math.h>
#include "../include/AudioFile.h"


using namespace std;

#define BIT_DEPTH 8

double quantization(double sample, int rate);

int main(int argc, char** argv) {


    if(argc != 3) {
        cerr << "./a intAudio.wav outAudio.wav" << endl;
        return EXIT_FAILURE;
    }    


    AudioFile<double> audioFile;
    AudioFile<double> outAudioFile;
    audioFile.load(argv[1]);

    int numChannels = audioFile.getNumChannels(); 
    int numSamples = audioFile.getNumSamplesPerChannel(); 

    outAudioFile.setNumChannels(numChannels); 
    outAudioFile.setNumSamplesPerChannel(numSamples); 
    outAudioFile.setBitDepth(BIT_DEPTH);


    audioFile.printSummary();
    int r = audioFile.getSampleRate();
        
    for(int i = 0; i < numChannels; i++) {
        for(int j = 0; j < numSamples; j++) {

            outAudioFile.samples[i][j] = quantization(audioFile.samples[i][j], r);;

        }
    }

    outAudioFile.save(argv[2]);

    return 0;
}


double quantization(double sample, int rate) {


    double s = 1;
    int sample_max = pow(2, BIT_DEPTH-1) - 1;
    double outSample;
    for (int i = 0; i < rate * s; i++)
        outSample = floor(sample * sample_max);

    //cout << "Out Sample: " << outSample << "\nSample" << sample << endl;
    return outSample;
}
