/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/04/2022 11:44:26
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), george.potoshin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "include/grooph.h"

int main () {
	FILE *fp = fopen ("test.png", "wb");
	if (!fp) {
		printf ("Can't open file!\n");
		return 0;
	}

	GRImg *img = GRInitDefaultImg (GR_PNG);
	if (!img) {
		printf ("Can't init image\n");
		return 0;
	}

	if (GRSetSize (img, 3000, 2400)) {
		printf ("GRSetSize: Can't allocate memory!\n");
		return 0;
	}

	png_color color;

	color.red = 5;
	color.green = 5;
	color.blue = 5;

	if (GRFullBackground (img, &color)) {
		printf ("GRFullBackground: missing pointer!\n");
		return 0;
	}

	color.red = 50;
	color.green = 75;
	color.blue = 25;

	if (GRPutDot (img, 1500, 1200, &color, 1000)) {
		printf ("GRPutDot: missing pointer!\n");
		return 0;
	}

	GRWriteImg (img, fp);
	fclose (fp);
	return 0;
}
