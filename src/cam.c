#include "../inc/cam.h"

Pixel worldToScreen(Camera *pCam, Vector p) {
  Pixel ret;
  p = worldToLocal(p, pCam->transform); 
  ret.x = (int)(p.x * (pCam->d / p.z));
  ret.y = (int)(p.y * (pCam->d / p.z));
  ret.x += 960;
  ret.y = -ret.y + 540;
  return ret;
}
