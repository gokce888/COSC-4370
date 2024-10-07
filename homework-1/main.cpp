// COSC 4370 - Graphic Processing Assignment 1

/*
#include "BMP.h"
#include <cmath>
#include <iostream>
using namespace std;

//duplicates arc using symetry
void writeEllipse(int x, int y, int xc, int yc, struct BMP *bmpNew) {

}
//calculates ellipse
void midpointEllipse(int a, int b, struct BMP *bmpNew) {

}


int main() {
    int a = 800;
    int b = 800;
    BMP bmpNew(a,b,false);
    bmpNew.fill_region(0, 0, a, b, 0, 0, 0, 0);
    for(int i=0;i<bmpNew.bmp_info_header.width;i++)
    {
        bmpNew.set_pixel(i, b/2+1, 255, 255, 255, 0);
    }

    //midpointEllipse(a, b, &bmpNew);

    bmpNew.write("output.bmp");


}

*/

#include "BMP.h"
#include <cmath>
#include <iostream>
using namespace std;

// Function to plot a pixel in the lower half of the ellipse (y <= 0)
void writeEllipse(int x, int y, int xc, int yc, struct BMP *bmpNew) {

  bmpNew->set_pixel(xc + x, yc - y, 255, 255, 255, 0); // 3rd quadrant
  bmpNew->set_pixel(xc - x, yc - y, 255, 255, 255, 0); // 4rth quadrant
}
// The semi-major axis a controls how wide the ellipse is horizontally, while b
// controls the height vertically.
//  Midpoint Ellipse Algorithm (adjusted to draw only y <= 0)
void midpointEllipse(float a, float b, float xc, float yc, struct BMP *bmpNew) {

  float dx, dy, d1, d2, x, y; // Decision parameter
  x = 0;                      // Initial value of x
  y = b;                      // Initial value of y

  // Decision parameters for region
  d1 = (b * b) - (a * a * b) + (a * a * 0.25); // Initial decision parameter.

  dx = 2 * b * b * x; // Initial slope parameter
  dy = 2 * a * a * y; // Initial slope parameter

  // Region 1
  while (dx < dy) {                     // Loop until slope is less than 1.
    writeEllipse(x, y, xc, yc, bmpNew); // Draw only lower half
    // Checking and updating value of
    // decision parameter based on algorithm
    if (d1 < 0) {
      x++;
      dx = dx + (2 * b * b);
      d1 = d1 + (dx + b * b);
    } else {
      x++;
      y--;
      dx = dx + (2 * b * b);
      dy = dy - (2 * a * a);
      d1 = d1 + dx - dy + (b * b);
    }
  }

  // Decision parameters for region 2
  d2 = ((b * b) * ((x + 0.5) * (x + 0.5))) + ((a * a) * ((y - 1) * (y - 1))) -
       (a * a * b * b);

  // Region 2
  while (y >= 0) { // Loop until y is less than or equal to 0.
    writeEllipse(x, y, xc, yc, bmpNew); // Draw only lower half
    // Checking and updating value of
    // decision parameter based on algorithm
    if (d2 > 0) {
      y--;
      dy = dy - (2 * a * a);
      d2 = d2 + (a * a) - dy;
    } else {
      y--;
      x++;
      dx = dx + (2 * b * b);
      dy = dy - (2 * a * a);
      d2 = d2 + dx - dy + (a * a);
    }
  }
}

int main() {

  int a = 800; // Semi-major axis
  int b = 800; // Semi-minor axis

  // Create an 800x800 image
  BMP bmpNew(a, b, false);
  bmpNew.fill_region(0, 0, a, b, 0, 0, 0, 0); // Black background

  int xc = b / 2;                             // Center x-coordinate
  int yc = a / 2;                             // Center y-coordinate
  bmpNew.fill_region(0, 0, a, b, 0, 0, 0, 0); // Black background

  /*
  for(int i=0;i<bmpNew.bmp_info_header.width;i++)
  {
      bmpNew.set_pixel(i, b/2+1, 255, 255, 255, 0);
  }
  */
  //  Draw an ellipse using the midpoint algorithm (only the lower half)
  // midpointEllipse(9 * 24, 16 * 24, xc, yc, bmpNew);
  midpointEllipse(9 * 24, 16 * 24, xc, yc, &bmpNew);

  // Write the image to a BMP file
  bmpNew.write("output.bmp");

  return 0;
}

// source: https://www.geeksforgeeks.org/midpoint-ellipse-drawing-algorithm/
