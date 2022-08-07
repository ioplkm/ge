#include "../inc/draw.h"

void drawPoint(uint32_t *b, Pixel p, uint32_t color) {
  int pos = p.y * 1920 + p.x;
  if (pos < 0 || pos > 1920 * 1080) return;
  b[p.y * 1920 + p.x] = color;
}

void drawLine(uint32_t *b, Pixel p1, Pixel p2, uint32_t color) {
  for (int i = 0; i < 100; i++) {
    drawPoint(b, (Pixel){(int)((p2.x - p1.x) * i / 100.0f) + p1.x,
                         (int)((p2.y - p1.y) * i / 100.0f) + p1.y}, color);
  }
}

void drawBox(uint32_t *b, Camera *pCam, CollisionBox *pCB, uint32_t color) {
  Vector v[8]; //vertices of collisionBox
  for (int i = 0; i < 8; i++) {
    v[i] = pCB->halfSize;
    if (i & 1) v[i] = (Vector){v[i].x, v[i].y, -v[i].z};
    if (i & 2) v[i] = (Vector){v[i].x, -v[i].y, v[i].z};
    if (i & 4) v[i] = (Vector){-v[i].x, v[i].y, v[i].z};
    v[i] = m34vMult(pCB->pRB->transform, v[i]);
  }

  Pixel p[8];
  for (int i = 0; i < 8; i++)
    p[i] = worldToScreen(pCam, v[i]);
  drawLine(b, p[0], p[1], color);
  drawLine(b, p[0], p[2], color);
  drawLine(b, p[0], p[4], color);
  drawLine(b, p[6], p[2], color);
  drawLine(b, p[6], p[4], color);
  drawLine(b, p[6], p[7], color);
  drawLine(b, p[5], p[1], color);
  drawLine(b, p[5], p[4], color);
  drawLine(b, p[5], p[7], color);
  drawLine(b, p[3], p[1], color);
  drawLine(b, p[3], p[2], color);
  drawLine(b, p[3], p[7], color);
}

void drawPolyhedra(uint32_t *b, Camera *pCam, ConvexPolyhedra *pCB, uint32_t color) {
  Vector v[8]; //vertices of collisionBox
  for (int i = 0; i < 8; i++) {
    v[i] = pCB->halfSize;
    if (i & 1) v[i] = (Vector){v[i].x, v[i].y, -v[i].z};
    if (i & 2) v[i] = (Vector){v[i].x, -v[i].y, v[i].z};
    if (i & 4) v[i] = (Vector){-v[i].x, v[i].y, v[i].z};
    v[i] = m34vMult(pCB->pRB->transform, v[i]);
  }

  Pixel p[8];
  for (int i = 0; i < 8; i++)
    p[i] = worldToScreen(pCam, v[i]);
  drawLine(b, p[0], p[1], color);
  drawLine(b, p[0], p[2], color);
  drawLine(b, p[0], p[4], color);
  drawLine(b, p[6], p[2], color);
  drawLine(b, p[6], p[4], color);
  drawLine(b, p[6], p[7], color);
  drawLine(b, p[5], p[1], color);
  drawLine(b, p[5], p[4], color);
  drawLine(b, p[5], p[7], color);
  drawLine(b, p[3], p[1], color);
  drawLine(b, p[3], p[2], color);
  drawLine(b, p[3], p[7], color);
}
