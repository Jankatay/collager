/* base functionalities and includes that rest of the source code will use */ 
#ifndef BASE_C 
#define BASE_C 


#include "stb/stb_image_resize2.h"


// Horizontal means left and right, vertical means top and bottom
// -----------------------------------------------------------------
enum Method {
  Horizontal,
  Vertical
};


// data required for all images when processing
// stbi_load should give all necessary parts
// -----------------------------------------------------------------
struct Image {
  int width;
  int height;
  int numComponents;
  unsigned char* data;
};


// evaluates to 1 if an image is not valid to operate on, 0 otherwise
// -----------------------------------------------------------------
#define INVALID_IMG(img) ((!img) || (img->numComponents <= 0) || (img->width <= 0) || (img->height <= 0) || (!img->data))


// table for the image descriptors
// rest of program will uses it to access them
// -----------------------------------------------------------------
struct ImageTable {
  struct Image* images; // array
  size_t tableLen;      // length
};


// initialize a table for given length
// 
// -----------------------------------------------------------------
struct ImageTable freeTable(size_t len) {
  (void)len;
  return (struct ImageTable){};
};


// greatest common denominator of two variables
// simply using the euclids algorithm
// -----------------------------------------------------------------
int gcd(size_t a, size_t b) {
  while(b) {
    size_t rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}


// least common multiple using gcd 
// -----------------------------------------------------------------
#define LCM(a,b) (a*b/gcd(a,b))

#endif 
