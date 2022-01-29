/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/18/2021 11:08:45
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

double dt;
double t = 0;

typedef struct {
	double x1;
	double x2;
	double x3;
	double x4;
}  phase;

phase primeOfPhase (phase p) {
	phase out;
	out.x1 = p.x2;
	out.x2 = 0;
	out.x3 = p.x4;
	out.x4 = -10;

	return out;
}

phase nextPhase (phase *pp, int acc) {
	phase p;
	double *dp = (double *)&p;
	double *dpp = (double *)pp;

	double dprime[4 * sizeof (phase) / sizeof (double)];

	for (int i = 0; i < sizeof (phase) / sizeof (double); i++) {
		*(dp + i) = 0;
	}

	for (int i = 0; i < 4; i++) {
		*((phase *)(dprime + i * sizeof (phase) / sizeof (double))) = 
			primeOfPhase (pp[i]);
	}
	
	for (int param = 0; param < sizeof (phase) / sizeof (double); param++) {
		switch (acc) {
			case 1:
				*(dp + param) = *(dpp + param) + *(dprime + param) * dt;
				break;
			case 2:
				*(dp + param) = *(dpp + param + sizeof (phase) / sizeof (double)) 
				  + (*(dprime + sizeof (phase) / sizeof (double) + param) * 3/2
				  - *(dprime + param) * 1/2) * dt;
				break;
			case 3:
				*(dp + param) = *(dpp + param + 2 * sizeof (phase) / sizeof (double))
				  + (*(dprime + 2 * sizeof (phase) / sizeof (double) + param) * 23/12
				  - *(dprime + sizeof (phase) / sizeof (double) + param) * 4/3
				  + *(dprime + param) * 5/12) * dt;
				break;
			case 4:
				*(dp + param) = *(dpp + param + 3 * sizeof (phase) / sizeof (double))
				  + (*(dprime + 3 * sizeof (phase) / sizeof (double) + param) * 55/24
				  - *(dprime + 2 * sizeof (phase) / sizeof (double) + param) * 59/24
				  + *(dprime + sizeof (phase) / sizeof (double) + param) * 37/24
				  - *(dprime + param) * 3/8) * dt;
		}
	}

	return p;
}

void shift (phase *pp, int acc) {
	for (int i = 0; i < acc; i++)
		pp[i] = pp[i+1];
}

//  dt, accuracy, endtime, x0, vx0, y0, vy0
int main (int argc, char *argv[]) {
	if (argc != 8) {
		printf ("There must be six arguments:\ndt, number of values to approximate next phase (available only 1, 2, 3), endtime, x0, vx0, y0, vy0\n");
		return 0;
	}

	dt = atof (argv[1]);
	int acc   = atoi (argv[2]);
	if (acc != 1 && acc != 2 && acc !=3 && acc != 4) {
		printf ("Number of values to approximate next phase should lay in [1; 4]\n");
		return 0;
	}
	double et = atof (argv[3]);

	phase phase0;
	{
		double *d = (double *)&phase0;
		for (int i = 4; i < argc; i++)
			*(d + i - 3) = atof (argv[i]);
	}

	phase buf[5];
	buf[0] = phase0;
	for (int i = 1; i < acc; i++) {
		buf[i] = nextPhase (buf, i);
		t += dt;
	}

	for (; t < et; t += dt) {
		buf[acc] = nextPhase (buf, acc);
		shift (buf, acc);
	}

	printf ("x(%lf)  = %lf\nvx(%lf) = %lf\ny(%lf)  = %lf\nvy(%lf) = %lf\n", 
			et, buf[acc].x1, et, buf[acc].x2, et, buf[acc].x3, et, buf[acc].x4);

	return 0;
}
