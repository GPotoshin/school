/*
 * =====================================================================================
 *
 *       Filename:  GR3dTypes.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/13/2022 11:31:39
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), george.potoshin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef GR3D_TYPES_H
#define GR3D_TYPES_H

#include "GRTypes.h"

typedef struct {
	double x;
	double y;
	double z;
} GRDouble3;

typedef struct {
	int n;
	GRColor c;
} GRSegment;

typedef struct {
	GRDouble3 *vertex;
	GRSegment **adj;
} GRFigure;

typedef struct {
	int n;
	GRFigure *fig;
	int l;
	int hieght;
	int width;
} GRScene;

#endif /* GR3D_TYPES_H */
