#include <stdio.h>

int main(void){
	printf("char\t\t\t|\t%lu\n", sizeof(char));
	printf("char *\t\t\t|\t%lu\n", sizeof(char *));
        printf("short\t\t\t|\t\%lu\n", sizeof(short));
	printf("short *\t\t\t|\t\%lu\n", sizeof(short *));
	printf("int\t\t\t|\t\%lu\n", sizeof(int));
	printf("int *\t\t\t|\t\%lu\n", sizeof(int *));
	printf("long\t\t\t|\t\%lu\n", sizeof(long));
	printf("long *\t\t\t|\t\%lu\n", sizeof(long *));
	printf("long long\t\t|\t\%lu\n", sizeof(long long));
	printf("long long *\t\t|\t\%lu\n", sizeof(long long *));
	printf("float\t\t\t|\t\%lu\n", sizeof(float));
	printf("float *\t\t\t|\t\%lu\n", sizeof(float *));
	printf("double\t\t\t|\t\%lu\n", sizeof(double));
	printf("double *\t\t|\t\%lu\n", sizeof(double *));
	printf("long double\t\t|\t\%lu\n", sizeof(long double));
	printf("long double *\t\t|\t\%lu\n", sizeof(long double *));
	return 0;
}
