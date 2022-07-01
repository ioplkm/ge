#include "../inc/fb.h"
#include <stdio.h> //temporary
void drawPoint(uint32_t x, uint32_t y, uint32_t color) {
  buffer[y * info.xres + x] = color;
}

void drawLine(int x1, int y1, int x2, int y2, uint32_t color) {
  for (int i = 0; i < 100; i++) {
    drawPoint((int)((x2 - x1) * i / 100.0f) + x1,
              (int)((y2 - y1) * i / 100.0f) + y1, 
                                    color);
  }
}

void fbInit() {
  int fbfd = open("/dev/fb0", O_RDWR);
  ioctl(fbfd, FBIOGET_VSCREENINFO, &info);
  buffer = mmap(NULL, 4 * info.xres * info.yres, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
  for (uint32_t i = 0; i < info.xres; i++)
    for (uint32_t j = 0; j < info.yres; j++)
      buffer[j * info.xres + i] = black;
}
