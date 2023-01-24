/*
 * Visual Computing
 * University of Konstanz
 * 2020
 *
 * main.cpp
 */

#define _USE_MATH_DEFINES
#include <cg/config.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

using std::cout;
using std::endl;

class color {
public:
    color() {
        R = 0;
        G = 0;
        B = 0;
    }
    color(unsigned char nR, unsigned char nG, unsigned char nB)
    : R(nR), G(nG), B(nB) {}
    unsigned char R, G, B;
};

void writeToPBM(color* array, unsigned int width, unsigned int height,
                std::string filename) {
    std::ofstream outfile(filename, std::ofstream::out);
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

int main(int argc, char* argv[]) {
    cg::set_working_directory();

    int width = 500;
    int height = 500;

    color sinusImage[width * height];

    for (size_t y = 0; y < width; y++)
    {       
        for (size_t x = 0; x < height; x++)
        {
            // The x^2 + y^2 function as well as adjusted to be accurate to example image.
            float t = (pow(x, 2.0) + (pow(y, 2.0))) / (width / 1.8);
            
            // Maps the sinus from the function from -1 - 1 to 0 - 255.
            int mapped_value = std::round(((sin(t) + 1) / 2) * 255);

            // Applies the value to R, G and B to get greyscale color.
            sinusImage[x + y * width].R = mapped_value;
            sinusImage[x + y * width].G = mapped_value;
            sinusImage[x + y * width].B = mapped_value;
        }
    }

    // Writes the Moiré-Artifacts array to exercise_02_a.ppm file.
    writeToPBM(sinusImage, width, height, "exercise_02_a.ppm");

    color sinusNoisyImage[width * height];

    // Random number generator initialization for noise. Random number distribution is from -1 to 1.
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);
    std::default_random_engine generator;

    for (size_t y = 0; y < width; y++)
    {       
        for (size_t x = 0; x < height; x++)
        {
            // Calculates the X and Y distance from starting point sum.
            // Is mapped to a value from 0 to 1 and then reversed so randomness is the least intense in the beginning.
            // This is done to gradually increase randomness instead of having the entire picture noise be equally random
            // Dividing by 1.25 was the best noise to signal ratio after some experimenting.
            float distanceSum = ((1 - ((float) y / 500)) + (1 - ((float) x / 500))) / 1.25;

            const double random_value = distribution(generator);

            // The x^2 + y^2 function + the added randomness compared to how far the pixel is located in the image.
            float t = ((pow(x, 2.0) + (pow(y, 2.0))) / (width / 1.8)) + (random_value / distanceSum);

            // Maps the sin(x^2 + y^2) and added randomness value to 0 to 255 for RGB.
            int mapped_value = std::round((((sin(t) + 1)) / 2) * 255);

            // To get the appropriate grey value, red, green and blue have to be set the same.
            sinusNoisyImage[x + y * width].R = mapped_value;
            sinusNoisyImage[x + y * width].G = mapped_value;
            sinusNoisyImage[x + y * width].B = mapped_value;

            // I understand the jittering was supposed to be achieved another way, but after 8 hours, this is the best I got.
        }
    }

    // Writes the noisy image attempt array to exercise_02_b.ppm file.
    writeToPBM(sinusNoisyImage, width, height, "exercise_02_b.ppm");

    return 0;
}
