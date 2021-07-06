#include <iostream>
#include <fstream>
using namespace std;

struct Image {
	int mx;
	int my;
	int* points;
};

void showImage(Image* img) {
	for (int y = 0; y < img->my; y++) {
		for (int x = 0; x < img->mx; x++) {
			cout << img -> points[y * img->mx + x] << " ";
		}
		cout << endl;
	}
}

void createImage(Image* img, int tmx, int tmy) {
	img -> mx = tmx;
	img -> my = tmy;
	img -> points = new int[tmx * tmy]{ 0 };
}



void setPointImage(Image* img, int x, int y, int color) {
	img->points[y * img->mx + x] = color;
}


int getPointImage(Image* img, int x, int y, int color) {
	return img->points[y * img->mx + x] = color;
}


void saveToPnmFile(Image* img, string fileName) {
	fstream file(fileName);
	file << "P1" << endl;
	file << img->mx << " " << img->my << endl;
	for (int y = 0; y < img->my; y++) {
		for (int x = 0; x < img->mx; x++) {
			file << img->points[y * img->mx + x] << " ";
		}
		file << endl;
	}
	file.close();
}


int main() {
	Image* img = new Image();
	createImage(img, 6, 10);
	setPointImage(img, 5, 9, 1);
	showImage(img);
	saveToPnmFile(img, "pic1.pnm");
}
