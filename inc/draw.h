#ifndef DRAW_H
#define DRAW_H

#include <pe/narrowcollision.h>
#include <pe/collision.h>

#include "cam.h"

void drawPoint(uint32_t *b, Pixel p, uint32_t color);
void drawLine(uint32_t *b, Pixel p1, Pixel p2, uint32_t color);
void drawBox(uint32_t *b, Camera *pCam, CollisionBox *pCB, uint32_t color);
void drawPolyhedra(uint32_t *b, Camera *pCam, ConvexPolyhedra *pP, uint32_t color);

#endif
