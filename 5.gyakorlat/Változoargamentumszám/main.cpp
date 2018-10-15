#include <iostream>
#include "mlp.hpp"
#include "png++/png.hpp"

int main(int argc, char** argv){

	png::image <png::rgb_pixel> png_image (argv[1]);
	png::image <png::rgb_pixel> result(png_image.get_width(),png_image.get_height());
	int size = png_image.get_width()*png_image.get_height();

	Perceptron* p = new Perceptron(3, size, 256, 3);

	double* imageR = new double[size];
	double* imageG = new double[size];
	double* imageB = new double[size];

	for(int i = 0; i < png_image.get_width(); i++)
		for(int j = 0; j < png_image.get_height(); j++) {
			imageR[i*png_image.get_width()+j] = png_image[i][j].red;
			result[i][j].red = imageR[i*png_image.get_width()+j];
			
			imageG[i*png_image.get_width()+j] = png_image[i][j].green;
			result[i][j].green = imageG[i*png_image.get_width()+j];
			
			imageB[i*png_image.get_width()+j] = png_image[i][j].blue;
			result[i][j].blue = imageB[i*png_image.get_width()+j];
		}

	double valueR = (*p) (imageR);
	double valueG = (*p) (imageG);
	double valueB = (*p) (imageB);
	
	std::cout << valueR << std::endl << valueG << std::endl << valueB << std::endl;
	
	result.write("rgb.png");
	std::cout << "The result image has been created." << std::endl;

	delete[] imageR, imageG, imageB;
	delete p;
	return 0;
}