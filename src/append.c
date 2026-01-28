/* resize and append two images either horizontally or vertically */
#ifndef APPEND_C
#define APPEND_C

#include "base.c"
#include "stb/stb_image_resize2.h"

// resize width and height of an image by multiplying the dimensions
// on success returns 1, else 0. 
// -----------------------------------------------------------------
int mulDimensions(struct Image* img, int mul) {
  // sanitize
  if(INVALID_IMG(img)) return 0;

  // resize 
  return stbir_resize_uint8_linear(img->data, img->width, img->height, 0, img->data, img->width*mul, img->height*mul, 0, STBIR_RGBA) != NULL;
}


// resize two images to fit vertically or horizontally
// returns 0 on error and 1 on success
// -----------------------------------------------------------------
int fit(struct Image* ltop, struct Image* rbot, enum Method method) {
  // sanitize
  if(INVALID_IMG(ltop)) return 0;
  if(INVALID_IMG(rbot)) return 0;

  // get the two dimensions, by default assume vertical fit
  int ltopDim = ltop->height;
  int rbotDim = rbot->height;

  // but will be 50-50 horizontal
  if(method == Horizontal) {
    ltopDim = ltop->width;
    rbotDim = rbot->width;
  }

  // calculate a neat multiplication factor using LCM(A,B) = A*B/gcd(A,B)
  int factor = (ltopDim * rbotDim) / gcd(ltopDim, rbotDim);

  // TODO: resize the two images to be scaled up by LCM of necessary dimensions, so they match now
  return factor;
}

#endif 
