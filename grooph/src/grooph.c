/*
 * =====================================================================================
 *
 *       Filename:  grooph.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/14/2022 13:52:16
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  George Potoshin (GP), george.potoshin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "GRImg.h"
#include "grooph.h"
#include "gizmos.h"

GRImg *GRInitImg (int filetype, FILE *filep, int colortype, 
			   int interlace, int compression, int filter, char *libver) {
	void *retval = 0;

	GRImg *img = malloc(sizeof(GRImg));
	if (!img)
		goto bailout;

	if (filetype == GR_PNG) {
		img->colortype = colortype;
		img->interlace = interlace;
		img->compresion = compression;
		img->filter = filter;

		img->partition = malloc(sizeof(int)*4);
		if (!img->partition)
			goto _bailout;
		img->partition[0] = 2;
		img->partition[1] = sizeof(png_structp);
		img->partition[2] = sizeof(png_infop);
		img->partition[3] = GR_PARTITION_END;

		img->libver = cstr(libver);
		if (!img->libver)
			goto _bailout;

		img->data = malloc (img->partition[1] + img->partition[2]);
		if (!img->data)
			goto _bailout;

		img->data + img->partition[1] = NULL;
		img->data + img->partition[2] = NULL;

		*img->data = png_create_write_struct (img->libver, NULL, 
				NULL, NULL);
		if(!img->data)
			goto _bailout;

		*(img->data + img->partion[1]) = png_create_info_struct (img->data + 
				img->partion[1]);
		if (!(img->data + img->partion[1]))
			goto _bailout;

		png_init_io (*img->data, filep);
	}

	retval = img;
	return retval;

bailout:
	free(*img->data);
	for (int i = 1; i < img->partition[0]; i++)
		free (*(img->data + img->partition[i]));

	free (img->partition);
	free (img->libver);
	free (img->data);
	free (img);
	return retval;
}

GRImg GRInitDefaultPngImg (FILE *filep) {
	return GRInitImg (GR_PNG, file, PNG_COLOR_TYPE_PNG, PNG_INTERLACE_NONE,
					  PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE, 
					  PNG_LIBPNG_VER_STRING);
}

int GRSetSize (GRImg *imgp, int height, int width) {
	int retval = -1;
	size_t row_bytes = height * sizeof (byte_p);
	size_t col_bytes = width * 3 * sizeof (byte);

	img->rows = malloc (row_bytes);
	if (!img->rows)
		goto _bailout;
	
	bzero (img->rows, row_bytes);
	for (int i = 0; i < height; i++) {
		img->rows[i] = malloc (col_bytes);
		if (!img->rows[i])
			goto _bailout;
	}
	return retval;
_bailout:
	if (img->rows)
		free (img);
	return retval;
}

void GRResetSize (GRImg *imgp, int height, int width) {

}
