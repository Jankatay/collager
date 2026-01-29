/* base functionalities and includes that rest of the source code will use */ 
#ifndef BASE_C 
#define BASE_C 

// std
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// unix
#include <unistd.h>

// stb
#include "stb/stb_image.h"
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


// the only crucial info about an image in the table 
// -----------------------------------------------------------------
struct ImageEntry {
  unsigned int width;
  unsigned int height;
};


// table for the image descriptors
// rest of program will uses it to access them
// the physical files will be in `path/0, path/1, ..., path/tableLen`
// path will be a temporary folder, in that sense descriptors let you find the file too
// -----------------------------------------------------------------
struct ImageTable {
  struct ImageEntry* entries; // array
  size_t tableLen;            // length
} GlobalTable = {};


// just initializes the GlobalTable, nothing more.
// -----------------------------------------------------------------
void freeTable(size_t len) {
  // set the values
  GlobalTable.entries = calloc(len, sizeof(struct ImageEntry));
  GlobalTable.tableLen = len;
};


// add an image to the table 
// -----------------------------------------------------------------
int openImage(char path[PATH_MAX]) {
  int width, height, componentsRatio;
  unsigned char* data = stbi_load(path, &width, &height, &componentsRatio, 0);
  return data == NULL;
}


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


// calculate least common multiple quickly using gcd 
// -----------------------------------------------------------------
#define LCM(a,b) (a*b/gcd(a,b))

#endif 
