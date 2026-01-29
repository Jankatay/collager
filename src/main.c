#include "stb/stb_image.h"
#include "stb/stb_image_resize2.h"
#include "stb/stb_image_write.h"
#include "append.c"

int main() {
  freeTable(1);
  printf("%s\n", GlobalTable.path);
  return 0;
}
