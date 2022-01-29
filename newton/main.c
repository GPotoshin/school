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

double f1 (double x)
{
	return log(x);
}

double f2 (double x) 
{
	return x*x + 2*x + 1;
}

double f3 (double x)
{
	return 2*x*x*x*x - 3*x*x*x + 12*x*x - 10*x + 3;
}

double der (double x, double (*f) (double))
{
	return ((*f) (x + 0.000001) - (*f) (x)) / 0.000001;
}

double d1 (double x)
{
	return 1/x;
}

double d2 (double x)
{
	return 2*x + 2;
}

double d3 (double x)
{
	return 8*x*x*x - 9*x*x + 24*x - 10;
}

int main (int argc, char* argv[])
{
	double x = 0;
	for (int i = 1; i < argc; i++) {

		x = atof (argv[i]);
		double (*f) (double);
		double (*d) (double);

		if (atoi (argv[++i]) == 1){
			f = &f1;
			d = &d1;
		}
		else if (atoi (argv[i]) == 2){
			f = &f2;
			d = &d2;
		}
		else{
			f = &f3;
			d = &d3;
		}

		for (int j = 0; (f(x) > 0.00001 || f(x) < -0.00001) && j < 200000000; j++){
			if(der(x, f) == 0)
				x += 0.00001*(rand()%50);
			x = x - (*f) (x)/(*d) (x);
		}
		if((*f) (x) > 0.0001 || (*f) (x) < -0.0001)
			printf("Can't reach the answer\n");
		else
			printf("Answer is %lf\n", x);
	}
	return 0;
}

