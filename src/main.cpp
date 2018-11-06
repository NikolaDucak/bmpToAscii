#include <iostream>
#include "../inc/BMPFile.h"
#include <fstream>

std::string asciiPixels = "_.-+@#";



int main(){
    BMPFile* img = BMPFile::open("test.bmp");
    std::ofstream out;
    out.open("ascii.txt");

    int w = img->getWidth();
    int h = img->getHeight();
    int luma;
    char c;

    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            luma = 0.299 * img->pixel(x,y).r + 0.587 * img->pixel(x,y).g + 0.114 * img->pixel(x,y).b;
            c = asciiPixels[ (int) (luma/ 255.0 * 6.0)];
            out.put(c);
            std::cout << c;
            
        }
        out.put('\n');
        std::cout << std::endl;
    }

    img = BMPFile::newImage(10,10);
    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++){
            img->pixel(x,y).r = x * (255/10);
            img->pixel(x,y).g = y * (255/10);
            img->pixel(x,y).b = (x * (255/10))/2 + (y *(255/10))/2;
             if (x == y) img->pixel(x,y)= {0,0,0};
        }

    }

    img->writeToFile("test.bmp");

}