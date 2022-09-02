#ifndef GROOPH_ESSENCE_H
#define GROOPH_ESSENCE_H

#include "grooph_core.h"

GrImg *grInitImg (int filetype, int colortype, int intarelace, int compression, int filter, char *libver);
void grDestroyImg (GrImg *img);
void grWriteImg (GrImg *img, FILE *fp);

GrImg *GrInitDefaultImg (int filetype);

int grSetSize (GrImg *img, int width, int height);
int grResetSize (GrImg *img, int width, int height);

#endif /* GROOPH_ESSENCE_H */
