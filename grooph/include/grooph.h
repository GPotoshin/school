/*
 * =====================================================================================
 *
 *       Filename:  grooph.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/18/2022 20:42:04
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), george.potoshin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef GROOPH_H
#define GROOPH_H

#include "GRImg.h"
#include <png.h>
#define GR_PNG 0x000001
#define GR_JPG 0x000002

GRImg *GRInitImg (int filetype, int colortype, 
			   int intarelace, int compression, int filter, char *libver);
void GRDestroyImg (GRImg *img);
void GRWriteImg (GRImg *img, FILE *filep);

GRImg *GRInitDefaultImg (int filetype);

int GRSetSize (GRImg *img, int width, int height);
int GRResetSize (GRImg *img, int width, int height);

int GRFullBackground (GRImg *img, void *color); 
int GRPutDot (GRImg *img, int x, int y, void *color, int r);

#endif /* GROOPH_H */
