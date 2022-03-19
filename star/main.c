/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/10/2022 09:50:27
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
#include <math.h>
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

	if (GRSetSize (img, 1440, 1156)) {
		printf ("GRSetSize: Can't allocate memory!\n");
		return 0;
	}

	GRColor color = {30, 30, 33};
	GRFullBackground (img, color);

	int step;
	printf ("Enter step:\n> ");
	scanf ("%d", &step);


	int size = 4;
	GRDouble2 *p = malloc (size*sizeof(GRInt2));
	if (!p) {
		printf ("Can't allocate p\n");
	}
	p[0] = (GRDouble2){258, 850};
	p[1] = (GRDouble2){720, 50};
	p[2] = (GRDouble2){1182, 850};
	p[3] = (GRDouble2){258, 850};
	GRDouble2 *buf;
	for (int i = 0; i < step; i++) {
		size = 4*size-3;
		buf = malloc (size*sizeof(GRDouble2));
		if (!buf) {
			printf ("Not enough memory!\n");
			break;
		}
		for (int i = 0; i < size-1; i += 4) {
			buf[i] = p[i/4];
			buf[i+1] = (GRDouble2){0.66666*buf[i].x + 0.33333*p[i/4+1].x,
				0.66666*buf[i].y + 0.33333*p[i/4+1].y};
			buf[i+2] = (GRDouble2){(buf[i+1].x - buf[i].x)*0.5 + 
				sqrt(3)/2*(buf[i+1].y - buf[i].y) + buf[i+1].x,
				-(buf[i+1].x - buf[i].x)*sqrt(3)/2 +
				0.5*(buf[i+1].y - buf[i].y) + buf[i+1].y};
			buf[i+3] = (GRDouble2){0.33333*buf[i].x + 0.66666*p[i/4+1].x,
				0.33333*buf[i].y + 0.66666*p[i/4+1].y};
		}
		buf[size-1] = p[(size-1)/4];
		free(p);
		p = buf;
	}
	
	
	for (int i = 0; i < size - 1; i++) {
		GRDrawLine (img, (GRInt2){(int) p[i].x, (int) p[i].y}, (GRInt2){(int) p[i+1].x, (int) p[i+1].y}, color, 2);
	}
	GRDrawLine (img, (GRInt2){(int) p[size-1].x, (int) p[size-1].y}, (GRInt2){(int) p[0].x, (int) p[0].y}, color, 2);
	free(p);
	GRWriteImg (img, fp);
	GRDestroyImg (img);
	fclose (fp);
	return 0;
}
