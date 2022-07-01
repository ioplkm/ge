#ifndef CAM_H
#define CAM_H

#include <stdint.h>

#include <pe/vector.h>
#include <pe/matrix.h>

typedef struct {
  Vector p;
  double d;
  Quaternion o;

  Matrix34 transform;
} Camera;

typedef struct {int x, y;} Pixel;

Pixel worldToScreen(Camera *pCam, Vector p);

#endif
