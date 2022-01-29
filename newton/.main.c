/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/15/2021 10:47:46
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double f(double x){
	return log(x);
}

double der(double x){
	return (f(x+0.000001)-f(x))/0.000001;
}

int main(int argc, char* argv[])
{
	double x = 0;
	for(int i = 1; i < argc; i++){
		x = atof(argv[i]);
		for(int j = 0; (f(x) > 0.00001 || f(x) < -0.00001) && j < 200000000; j++){
			if(der(x) == 0)
				x += 0.00001*(rand()%50);
			x = x - f(x)/der(x);
		}
		if(f(x) > 0.0001 || f(x) < -0.0001)
			printf("Can't reach the answer\n");
		else
			printf("Answer is %lf\n", x);
	}
	return 0;
}

