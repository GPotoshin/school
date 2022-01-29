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
#include <math.h>

int main (int argc, char *argv[]) {
	
	double a1 = atof (argv[9]);
	double a2 = atof (argv[21]);

	double x = atof (argv[25]);
	double v = atof (argv[26]);
	double t = atof (argv[27]);
	double y = x + v*t - 5*t*t;
	printf ("method (dt = 0.01):\n" \
			"y = %lf\n" \
			"method (dt = 0.00001):\n" \
			"y = %lf\n" \
			"real:\n" \
			"y = %lf\n" \
			"power:\n" \
			"n = 1000*dy2/dy1 = %lf\n" \
			, a1, a2, y, fdim (0, 1000*(y-a2)/(y-a1)));

	return 0;
}
