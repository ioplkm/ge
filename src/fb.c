#include "../inc/fb.h"

uint32_t* fbInit() {
  int fbfd = open("/dev/fb0", O_RDWR);
  ioctl(fbfd, FBIOGET_VSCREENINFO, &info);
  fbuffer = mmap(NULL, 4 * info.xres * info.yres, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
  for (uint32_t i = 0; i < info.xres; i++)
    for (uint32_t j = 0; j < info.yres; j++)
      fbuffer[j * info.xres + i] = black;
  return fbuffer;
}
