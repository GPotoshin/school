/*
 * =====================================================================================
 *
 *       Filename:  compare.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/30/2021 22:16:28
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
	
	double a1 = atof (argv[9]);
	double a2 = atof (argv[21]);

	double b1 = atof (argv[33]);
	double b2 = atof (argv[45]);

	
	printf ("Comparison of 1st & 2nd methods with dt = {0.01, 0.0001} in time 10\n"\
			"1st method:\n" \
			"y(0.01) = %lf\n" \
			"y(0.0001) = %lf\n" \
			"2nd method:\n" \
			"y(0.01) = %lf\n" \
			"y(0.0001) = %lf\n\n" \
			"comparison:\n" \
			"dy1/dy2 = %lf\n" \
			, a1, b1, a2, b2, (b2 - a2)/(b1 - a1));

	return 0;
}
