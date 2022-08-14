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

uint32_t *fbuffer;
struct fb_var_screeninfo info;

uint32_t* fbInit();

#endif
