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

#include <stdio.h>

#define GR_PNG 0x000001
#define GR_JPG 0x000002

#define GR_PARTITION_END 0x000000

typedef struct s_GRImg GRImg;

GRImg *GRInitImg (int filetype, FILE *filep, int colortype, 
			   int intarelace, int compression, int filter, char *libver);

GRImg *GRInitDefaultPngImg (FILE *filep);

#endif /* GROOPH_H */
