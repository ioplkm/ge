#ifndef FB_H
#define FB_H

#include <stdint.h>
#include <stddef.h>

#include <linux/fb.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#define    red 0x00FF0000
#define yellow 0x00FFFF00
#define  green 0x0000FF00
#define   blue 0x000000FF
#define  white 0x00FFFFFF
#define  black 0x00000000

uint32_t *buffer;
struct fb_var_screeninfo info;

void drawPoint(uint32_t x, uint32_t y, uint32_t color);
void drawLine(int x1, int y1, int x2, int y2, uint32_t color);
void fbInit();

#endif
