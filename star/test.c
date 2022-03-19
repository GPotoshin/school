/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/11/2022 16:26:12
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

typedef struct {
	int x1;
	int x2;
} i2;

typedef struct {
	double x1;
	double x2;
} d2;

int main () {
	i2 p = {12, 13};
	d2 d = (d2)p;

	printf ("%g, %g\n", d);
	return 0;
}
