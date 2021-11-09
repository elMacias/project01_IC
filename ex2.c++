#include <iostream>
#include <map>
#include <fstream>

using namespace std;


int main(int argc, char** argv) {

    if (argc != 3) {
        cout << "./aout input_file output_file" << endl;
        return 1;
    }

    map<string, int> mapa;

    ifstream input(argv[1]);
    ofstream outfile(argv[2]);

    string word;
    while(input >> word) 
        mapa.count(word) ? mapa[word]++ : mapa[word] = 1;

    for(auto i : mapa) 
        outfile <<  i.first << " : " << i.second << "\n";

    input.close();
    outfile.close();

    return 0;
}