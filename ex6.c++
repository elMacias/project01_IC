#include <iostream>
#include <fstream>
#include "../include/AudioFile.h"
#include <vector>

using namespace std;


int main(int argc, char** argv) {

    if(argc != 2) {
        cerr << "./a audiofile.wave" << endl;
        return EXIT_FAILURE;
    }

    AudioFile<double> audioFile;
    audioFile.load(argv[1]);

    vector<double> allSamples;


    cout << "aqui" << endl;
    for(int i = 0; i < audioFile.getNumChannels(); i++) {
        for(int j = 0; j < audioFile.getNumSamplesPerChannel(); j++) {
            allSamples.push_back(audioFile.samples[i][j]);
        }
    }

    ofstream out("samples.txt");
    for(auto sample : allSamples) {
        cout << sample << endl;
        out << sample << endl;
    }
    out.close();

    return EXIT_SUCCESS;
}