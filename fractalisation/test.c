/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/10/2022 18:55:18
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), george.potoshin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <complex.h>
#include <stdio.h>

int main () {
	double complex z = 1 + I*1;
	printf ("%lf + i%lf", z*z);
	return 0;
}
