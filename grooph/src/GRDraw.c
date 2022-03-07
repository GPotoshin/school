/*
 * =====================================================================================
 *
 *       Filename:  GRDraw.c
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
#include <math.h>

#include "GRTypes.h"
#include "GRDraw.h"
#include "GRizmos.h"

int GRFullBackground (GRImg *img, void *color) {
	int retval = -1;
	if (!img->rows)
		goto _bailout;

	retval = -2;
	if (img->filetype == GR_PNG) {
		png_colorp cp = color;
		for (int j = 0; j < img->height; j++) {
			if (!img->rows[j])
				goto _bailout;
			for (int i = 0; i < img->width; i++) {
				GRBytep bp = img->rows[j] + i*3;
				bp[0] = cp->red;
				bp[1] = cp->green;
				bp[2] = cp->blue;
			}
		}
	}

	retval = 0;
_bailout:
	return retval;
}


int GRPutDot (GRImg *img, GRInt2 p, void *color, int r) {
	int retval = -1;
	if (!img->rows)
		goto _bailout;

	retval = -2;
	if (img->filetype == GR_PNG) {
		png_colorp cp = color;
		for (int j = y - r; j <= y + r; j++) {
			if (!img->rows[j])
				goto _bailout;

			for (int i = x - r; i <= x + r; i++) {
				if (j < img->height && i < img->width && ((i-x)*(i-x) + (j-y)*(j-y)\
							< r*r)) {
					GRBytep bp = img->rows[j] + i*3;
					bp[0] = (GRByte) fmax ((GRByte)(cp->red * 1.5 * r /
							(1.5*r + hypot (i-x, j-y))),
							(GRByte)(bp[0] + cp->red * 1.5 * r /
							(1.5*r + hypot (i-x, j-y))));
					bp[1] = (GRByte) fmax ((GRByte)(cp->green * 1.5 * r /
							(1.5*r + hypot (i-x, j-y))),
							(GRByte)(bp[1] + cp->green * 1.5 * r /
							(1.5*r + hypot (i-x, j-y))));
					bp[2] = (GRByte) fmax ((GRByte)(cp->blue * 1.5*r /
							(1.5*r + hypot (i-x, j-y))),
							(GRByte)(bp[2] + cp->blue * 1.5*r /
							(1.5*r + hypot (i-x, j-y))));
				}
			}
		}
	}

	retval = 0;
_bailout:
	return retval;
}


int GRDrawLine (GRImg *img, GRInt2 p1, GRInt2 p2, void *color, int w) {
	int retval = -1;

	if (x1 == x2) {
		for (int i = fmin (y2, y1); i <= fmax (y2, y1); i++) {
			GRPutDot (img, x1, i, color, w);
		}
	}
	if (y1 == y2) {
		for (int i = fmin (x2, x1); i <= fmax (x2, x1); i++) {
			GRPutDot (img, i, y1, color, w);
		}
	}

	if (y2 < y1) {
		int p = y1;
		y1 = y2;
		y2 = p
		p = x1;
		x1 = x2;
		x2 = p;
	}

	double k, m;

	int d;
	int x = x1, y = y1;
	if (k*k < 1) {
		k = (y2 - y1) / (x2 - x1);
		m = 0.5 * (y1 - k*x1 + y2 - k*x2);
		int d = sgn(k);

		while (y <= y2) {
			GRPutDot ();
			if ()
		}
	}
	else {

	}

_bailout:
	return retval;
}
