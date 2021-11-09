#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;

int main(int argc, char* argv[]){

    String imageInput = argv[1]; //imagem a ser copiada
    String imageOutput = argv[2]; //imagem onde fica a cópia
    Mat imageIn = imread(imageInput, IMREAD_COLOR); 
    Mat imageOut = Mat::zeros(Size(imageIn.rows, imageIn.cols), imageIn.type()); //inicializaçao do objeto out (a zeros)

    int width = imageIn.size().width; //columns
    int heigth = imageIn.size().height; //rows

    for(int i=0; i<heigth; i++){

        for(int j=0; j<width; j++){
            imageOut.at<Vec3b>(i,j) = imageIn.at<Vec3b>(i,j); //copia cada pixel(i,j), de cada coluna j, de cada linha i, para o out
        }

    }

    imwrite(imageOutput, imageOut); //save
    imshow("image copy", imageOut); //show
    waitKey(0);
    
    return 0;
}

