#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <cmath>
using namespace cv;
using namespace std;

int main(int argc, char* argv[]){

    String imageIn = argv[1]; //imagem original
    String imageCopy = argv[2]; //imagem reduzida
    Mat matImageIn = imread(imageIn); //matriz da imagem original
    Mat matImageCopy = imread(imageCopy); //matriz da imagem reduzida

    int width = matImageIn.size().width; //columns
    int heigth = matImageIn.size().height; //rows
    int sumIn[3] = {0, 0, 0}; //soma dos pixels da imagem original
    int sumCopy[3] = {0, 0, 0}; //soma dos pixels da imagem reduzida

    for(int i=0; i<heigth; i++){ //cada linha

        for(int j=0; j<width; j++){ //cada coluna
            //soma dos quadrados de cada pixel da imagem original -> E[X]
            sumIn[0] += pow((matImageIn.at<Vec3b>(i,j)[0]),2); //vec3B sao 3 dimensoes (R,G,B), portanto tem tres posicoes: B
            sumIn[1] += pow((matImageIn.at<Vec3b>(i,j)[1]),2); //G
            sumIn[2] += pow((matImageIn.at<Vec3b>(i,j)[2]),2); //R 
            //soma do quadrado de (cada pixel da imagem original - valor de cada pixel da imagem reduzida) -> E[X']
            sumCopy[0] += pow(((matImageIn.at<Vec3b>(i,j)[0])-(matImageCopy.at<Vec3b>(i,j)[0])),2);
            sumCopy[1] += pow(((matImageIn.at<Vec3b>(i,j)[1])-(matImageCopy.at<Vec3b>(i,j)[1])),2);
            sumCopy[2] += pow(((matImageIn.at<Vec3b>(i,j)[2])-(matImageCopy.at<Vec3b>(i,j)[2])),2);
        }

    }

    int totalSumIn = sumIn[0] + sumIn[1] + sumIn[2]; //E[X] total
    int totalSumCopy = sumCopy[0] + sumCopy[1] + sumCopy[2]; //E[X'] total 

    float snr = 10*log(totalSumIn/totalSumCopy); //SNR entre as duas imagens
    cout << "SNR: " << snr << endl;

    return 0;
}

