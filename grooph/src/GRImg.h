/*
 * =====================================================================================
 *
 *        Filename:  GRImg.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/14/2022 13:50:23
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  George Potoshin (GP), george.potoshin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef GRIMG_H
#define GRIMG_H

#include "../dep/libpng/include/png.h"

typedef struct {
	int filetype;
	FILE *filep;

	int colortype;
	int interlace;
	int compression;
	int filter;

	char *libver;
	
	int height;
	int width;

	byte_p *rows;

	void **data;
	int *partition;
} GRImg;


#endif /* GRIMG_H */
