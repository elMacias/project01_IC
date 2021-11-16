#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;

int main(int argc, char* argv[]){

    String imageIn = argv[1]; //imagem a ser alterada
    String imageOut = argv[2]; //imagem alterada
    Mat matImageIn = imread(imageIn); //le a imagem e guarda-a num objeto MAT (matrix n-dimensional)
    Mat matImageOut = Mat::zeros(Size(matImageIn.rows, matImageIn.cols), matImageIn.type()); //inicializaçao do objeto out (Mat é inicializada a zeros)
    int width = matImageIn.size().width; //columns
    int heigth = matImageIn.size().height; //rows

    for(int i=0; i<heigth; i++){ //cada linha

        for(int j=0; j<width; j++){ //cada coluna
            matImageOut.at<Vec3b>(i,j)[0] = matImageIn.at<Vec3b>(i,j)[0] >> 2; //vec3B sao 3 dimensoes (R,G,B), portanto tem tres posicoes: B
            matImageOut.at<Vec3b>(i,j)[1] = matImageIn.at<Vec3b>(i,j)[1] >> 2; //G
            matImageOut.at<Vec3b>(i,j)[2] = matImageIn.at<Vec3b>(i,j)[2] >> 2; //R
        }

    }

    imwrite(imageOut, matImageOut); //save
    imshow("original", matImageIn); //show original
    imshow("image copy", matImageOut); //show copy
    waitKey(0);

    return 0;
}