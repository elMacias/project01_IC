#include    <iostream>
#include    <string>
#include    <map>
#include    <fstream>
#include    <math.h>
#include    <vector>

using namespace std;

int main(int argc, char** argv) {

    if (argc != 3) {
        cout << "./aout input_file output_file" << endl;
        return 1;
    }

    map<string, int> mapa;
    vector<string> words;

    double entropy = 0;

    ifstream input(argv[1]);
    ofstream outfile(argv[2]);

    string word;
    while(input >> word)  {

        // erases any ponctuation 
        for (int i = 0, len = word.size(); i < len; i++)
        {
            if (ispunct(word[i]) || isdigit(word[i])) 
            {
                word.erase(i--, 1);
                len = word.size();
            }
        }
        mapa.count(word) ? mapa[word]++ : mapa[word] = 1;
    }
    mapa.erase("");


    /*calculates entropy*/
    for(auto it : mapa) {
        double p_x = (double)it.second/mapa.size();
        if(p_x > 0) entropy -= p_x * log(p_x)/log(2);
    }

    outfile << entropy << endl;
    for(auto i : mapa) {
        outfile <<  i.first << " : " << i.second << "\n";
    }  

    input.close();
    outfile.close();

    return 0;
}