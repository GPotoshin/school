/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/10/2022 18:43:44
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), george.potoshin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include "include/grooph.h"


double complex r[3] = {0 + I*0, 0 + I*0, 0 + I*0};
int size = 0;

int hieght = 8640;
int width = 15360;

double complex f(double complex x) {
	return x*x*x - 3*x*x + x - 7; 
}

double complex d(double complex x) {
	return 3*x*x - 6*x + 1;
}

GRColor GetColor (double complex z) {
	int j;
	for (j = 0; cabs(f(z)) > 0.0001 && j < 20000; j++) {
		if (d(z) == 0 + I*0)
			z += 0.00001*(rand()%50) + I*0.00001*(rand()%50);
		z -= f(z)/d(z);
	}
	if (cabs(f(z)) > 0.0001)
		return (GRColor){7, 8, 9}; 
	else {
		int i;
		for (i = 0; i < 3; i++) {
			if (cabs(z - r[i]) < 0.01) {
				break;
			}
		}
		if (i == 3) {
			if (size >= 3)
				return (GRColor){7, 8, 9}; 
			r[size] = z;
			i = size;
			size++;
		}
		if (i == 0)
			return (GRColor){89 - 2*j, 33 + 0.5*j, 42-0.1*j};
		if (i == 1)
			return (GRColor){42-0.2*j, 93 - 2*j, 55+ 0.3*j};
		if (i == 2)
			return (GRColor){54+0.5*j, 66-0.3*j, 88 - 2*j};
	}
	return (GRColor){7, 8, 9}; 
}

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

	if (GRSetSize (img, width, hieght)) {
		printf ("GRSetSize: Can't allocate memory!\n");
		return 0;
	}

	GRColor color = {30, 30, 33};
	GRFullBackground (img, color);

	double complex z;
	for (int i = 0; i < hieght; i++) {
		for (int j = 0; j < width; j++) {
			GRByte *bp = img->rows[i] + 3*j;
			z = (i-hieght/2.)/40 + I*(j-width/2.)/40;
			GRColor c = GetColor(z);
			bp[0] = c.red;
			bp[1] = c.green;
			bp[2] = c.blue;
		}
	}
	GRWriteImg (img, fp);
	GRDestroyImg (img);
	fclose (fp);
	return 0;
}

