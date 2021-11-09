#include <iostream>
#include <fstream>
#include "/home/henrique/Desktop/uni2122/IC/pratica/aula1/libs/AudioFile/AudioFile.h"
using namespace std;

int main(int argc, char* argv[]){

    AudioFile<double> audioFile; //objeto
    audioFile.load(argv[1]); //para onde é carregado o audio original

    AudioFile<double> copyAudioFile; //objeto onde será guardada a cópia

    int numChannels = audioFile.getNumChannels(); //numero de canais do audio original
    int numSamples = audioFile.getNumSamplesPerChannel(); //numero de samples por canal do audio original
    copyAudioFile.setNumChannels(numChannels); //define o numero de canais da cópia com a variavel numChannels
    copyAudioFile.setNumSamplesPerChannel(numSamples); //define o numero de samples da copia com a variavel numSamples
    cout <<"Numero de channels: " << audioFile.getNumChannels() << endl;
    cout <<"Numero de samples: " << audioFile.getNumSamplesPerChannel() << endl;

    for(int i=0; i<numChannels; i++){ 
        for(int j=0; j<numSamples; j++){ //para cada sample de cada canal
            copyAudioFile.samples[i][j] = audioFile.samples[i][j]; //coloca no audio de cópia, o valor das samples correspondentes a cada canal
        }
    }

    copyAudioFile.save(argv[2]);

    return 0;
}