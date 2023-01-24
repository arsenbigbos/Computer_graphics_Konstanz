/*
 * Visual Computing
 * University of Konstanz
 * 2020
 *
 * main.cpp
 */

#define _USE_MATH_DEFINES
// Removed temporarily cause of environment setup issues.
// #include <cg/config.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

struct color {
    unsigned char R, G, B;
};

void writeToPBM(color* array, unsigned int width, unsigned int height,
                std::string filename) {
    std::ofstream outfile(filename);
    // https://de.wikipedia.org/wiki/Portable_Anymap

    outfile << "P3\n";
    outfile << width << " " << height << "\n";
    outfile << "255\n";

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            color C = array[x + width * y];
            outfile << (int) C.R << " " << (int) C.G << " " << (int) C.B
                    << "\n";
        }
        outfile << "\n";
    }

    outfile.close();
}

// Author: Mārtiņš Dāvis Jembergs
int main(int argc, char* argv[]) {

    // 2.3.1. Task.
    std::cout << "Hello World!" << std::endl;

    // Creation and filling of array with 10 ints from 9 to 0.
    int *numbers = new int[10];
    std::cout << "Array with numbers 9 to 0:" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        numbers[i] = 9 - i;
        std::cout << "Array[" << i << "]: " << numbers[i] << std::endl;
    }

    // Outputting the even numbers of the array created previously.
    std::cout << "Outputting all even numbers from array:" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        if (numbers[i] % 2 == 0)
        {
            std::cout << "Array[" << i << "]: " << numbers[i] << std::endl;
        }
    }
    
    // Deleting array.
    std::cout << "Deleting array." << std::endl;
    delete [] numbers;

    // 2.3.2. Task.
    int width = 500;
    int height = 500;

    color sinusImage[500 * 500];

    // Filling in everything white (255, 255, 255).
    for (size_t x = 0; x < 500; x++)
    {
        for (size_t y = 0; y < 500; y++)
        {
            sinusImage[x + y * width].R = 255;
            sinusImage[x + y * width].G = 255;
            sinusImage[x + y * width].B = 255;

        }
    }

    // Filling in the axis with black. (0, 0, 0)
    for (size_t y = 0; y < 500; y++)
    {
        sinusImage[width / 2 + y * width].R = 0;
        sinusImage[width / 2 + y * width].G = 0;
        sinusImage[width / 2 + y * width].B = 0;
    }

    for (size_t x = 0; x < 500; x++)
    {
        sinusImage[x + width / 2 * width].R = 0;
        sinusImage[x + width / 2 * width].G = 0;
        sinusImage[x + width / 2 * width].B = 0;
    }

    // Generating sinus function in red. (255, 0, 0)
    for (size_t x = 0; x < 500; x++)
    {
        float t = x / (width / (M_PI * 2));
        int y = sin(t) * (width / 4.0) + (height / 2.0); 

        sinusImage[x + y * width].R = 255;
        sinusImage[x + y * width].G = 0;
        sinusImage[x + y * width].B = 0;
    }

    writeToPBM(sinusImage, 500, 500, "generatedImage.ppm");
    return 0;
}
