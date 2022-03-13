/*
 * =====================================================================================
 *
 *       Filename:  GR3d.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/11/2022 23:34:31
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

#include "GR3d.h"
#include "GREssence.h"

GRScene *GRInitScene (int l, int hieght, int width) {
	GRScene *scene = malloc (sizeof(GRScene));
	if (!scene)
		goto _bailout;

	scene->n = 0;
	scene->l = l;
	scene->hieght = hieght;
	scene->width = width;
_bailout:
	return retval;
}

GRImg *GRInitDefaultScreen (GRScene *scene) {
	GRImg *img = GRInitDefaultImg (GR_PNG);
	if (!img)
		goto _bailout;

	GRSetSize (img, scene->width, scene->hight);
_bailout:
	return img;
}

int GRAddFigure (GRScene *scene, GRFigure *fig, int n) {
	int retval = -1;
	void *p = realloc (scene->fig, (scene->n+n)*sizeof(GRFigure));
	if (!p) {
		printf ("Can't add figure!\n");
		goto _bailout;
	}
	
	scene->fig = p;
	for (int i = 0; i < n; i++)
		scene->fig[i+scene->n] = fig[i];

	retval = 0;
_bailout:
	return retval;
}

GRFigure *GRGetFigure (FILE *filep) {
		
};
