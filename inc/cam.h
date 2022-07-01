#ifndef CAM_H
#define CAM_H

#include <pe/vector.h>
#include <pe/matrix.h>

typedef struct {
  Vector p;
  double d;
  Quaternion o;
} Camera;

#endif
