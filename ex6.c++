#include <iostream>
#include <fstream>
#include "../include/AudioFile.h"
#include <vector>
#include <map>
#include <math.h>

using namespace std;


int main(int argc, char** argv) {

    if(argc != 2) {
        cerr << "./a audiofile.wave" << endl;
        return EXIT_FAILURE;
    }

    AudioFile<double> audioFile;
    audioFile.load(argv[1]);

    map<double, int> mapa;

    int sample = 0;
    double entropy;

    ofstream outfile(argv[2]);

    cout << "aqui" << endl;
    for(int i = 0; i < audioFile.getNumChannels(); i++) {
        for(int j = 0; j < audioFile.getNumSamplesPerChannel(); j++) {
            sample = audioFile.samples[i][j];

            mapa.count(sample) ? mapa[sample]++ : mapa[sample] = 1;
        }
    }


    /*calculates entropy*/
    for(auto it : mapa) {
        double p_x = (double)it.second/mapa.size();
        if(p_x > 0) entropy -= p_x * log(p_x)/log(2);
    }

    outfile << entropy << endl;
    for(auto i : mapa) {
        outfile <<  i.first << " : " << i.second << "\n";
    }  

    return EXIT_SUCCESS;
}