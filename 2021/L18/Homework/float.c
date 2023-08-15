#include <stdio.h>
#include <stdlib.h>

#define FLOAT 0
#define DOUBLE 1
#define LONG 2
#define INT 3

void printBitesOfl(long n){
	char c;
	for(int i = 8 * sizeof(long); i-- != 0;){
		if((n & (1UL << i)) != 0)
			c = '1';
		else
			c = '0';
		printf("%c", c);
	}
}

void printBitesOfi(int n){
	char c;
	for(int i = 8 * sizeof(int); i-- != 0;){
		if((n & (1U << i)) != 0)
			c = '1';
		else
			c = '0';
		printf("%c", c);
	}
}



int main(){
	
	int cursorPosision = 13;
	char inputString[20];
	int type = FLOAT;
	float f;
	int *u = (int *)(&f);
	double d;
	long *l = (long *)(&d);
	for(;;){	/* main cycle */
		for(;;){	/* cycle of choosing type */
			system("clear");
			printf("Choose type: float, double, long, int\n");
			for(int i = 0; i < cursorPosision; i++)
				printf(" ");
			printf("^\n");
			printf(":");
			scanf("%s", inputString);

			if(inputString[0] == 'd')
				type = (type + 1)%4;	/* cursor shoud move right */
			else if(inputString[0] == 'a')
				type = ((type - 1)%4 + 4)%4;	/* cursor shoud move left */
			else if(inputString[0] == 'e')
				return 0;
			else if(inputString[0] == 'y')
				break;

			if(type == FLOAT)
				cursorPosision = 13;
			else if(type == DOUBLE)
				cursorPosision = 20;
			else if(type == LONG)
				cursorPosision = 28;
			else if(type = INT)
				cursorPosision = 34;
		}
	
		if(type == FLOAT){
			cursorPosision = 0;
			f = 0;
			for(;;){ 
				system("clear");
				printf("FLOAT: %.6f\n", f);
				printBitesOfi(*u);
				printf("\n");
				for(int i = 0; i < cursorPosision; i++)
					printf(" ");
				printf("^\n");
				printf(":");
				scanf("%s", inputString);

				if(inputString[0] == 'd')
					cursorPosision = (cursorPosision + 1)%(sizeof(float)*8);
				else if(inputString[0] == 'a')
					cursorPosision = ((cursorPosision - 1)%(sizeof(float)*8) + sizeof(float)*8)%(sizeof(float)*8);
				else if(inputString[0] == '0')
					*u = *u &(0xFFFFFFFF - (1U << sizeof(float)*8 - cursorPosision - 1));
				else if(inputString[0] == '1')
					*u = *u |(1U << sizeof(float)*8 - cursorPosision - 1);
				else if(inputString[0] == 'c')
					*u = *u ^(1U << sizeof(float)*8 - cursorPosision - 1);
				else if(inputString[0] == 'e')
					return 0;
				else if(inputString[0] == 's')
					break;
			}
		}
		else if(type == DOUBLE){
			cursorPosision = 0;
			d = 0;
			for(;;){
				system("clear");
				printf("DOUBLE: %.12lf\n", d);
				printBitesOfl(*l);
				printf("\n");
				for(int i = 0; i < cursorPosision; i++)
					printf(" ");
				printf("^\n");
				printf(":");
				scanf("%s", inputString);

				if(inputString[0] == 'd')
					cursorPosision = (cursorPosision + 1)%(sizeof(double)*8);
				else if(inputString[0] == 'a')
					cursorPosision = ((cursorPosision - 1)%(sizeof(double)*8) + sizeof(double)*8)%(sizeof(double)*8);
				else if(inputString[0] == '0')
					*l = *l &(0xFFFFFFFFFFFFFFFF - (1UL << sizeof(double)*8 - cursorPosision - 1));
				else if(inputString[0] == '1')
					*l = *l |(1UL << sizeof(double)*8 - cursorPosision - 1);
				else if(inputString[0] == 'c')
					*l = *l ^(1UL << sizeof(double)*8 - cursorPosision - 1);
				else if(inputString[0] == 'e')
					return 0;
				else if(inputString[0] == 's')
					break;
			}
		}
		else if(type == LONG){
			cursorPosision = 0;
			*l = 0;
			for(;;){
				system("clear");
				printf("LONG: %ld", *l);
				printBitesOfl(*l);
				printf("\n");
				for(int i = 0; i < cursorPosision; i++)
					printf(" ");
				printf("^\n");
				printf(":");
				scanf("%s", inputString);
				if(inputString[0] == 'd')
					cursorPosision = (cursorPosision + 1)%(sizeof(double)*8);
				else if(inputString[0] == 'a')
					cursorPosision = ((cursorPosision - 1)%(sizeof(double)*8) + sizeof(double)*8)%(sizeof(double)*8);
				else if(inputString[0] == '0')
					*l = *l &(0xFFFFFFFFFFFFFFFF - (1UL << sizeof(double)*8 - cursorPosision - 1));
				else if(inputString[0] == '1')
					*l = *l |(1UL << sizeof(double)*8 - cursorPosision - 1);
				else if(inputString[0] == 'c')
					*l = *l ^(1UL << sizeof(double)*8 - cursorPosision - 1);
				else if(inputString[0] == 'e')
					return 0;
				else if(inputString[0] == 's')
					break;
			}
		}
		else if(type == INT){
			cursorPosision = 0;
			*u = 0;
			for(;;){ 
				system("clear");
				printf("INT: %.d\n", *u);
				printBitesOfi(*u);
				printf("\n");
				for(int i = 0; i < cursorPosision; i++)
					printf(" ");
				printf("^\n");
				printf(":");
				scanf("%s", inputString);

				if(inputString[0] == 'd')
					cursorPosision = (cursorPosision + 1)%(sizeof(float)*8);
				else if(inputString[0] == 'a')
					cursorPosision = ((cursorPosision - 1)%(sizeof(float)*8) + sizeof(float)*8)%(sizeof(float)*8);
				else if(inputString[0] == '0')
					*u = *u &(0xFFFFFFFF - (1U << sizeof(float)*8 - cursorPosision - 1));
				else if(inputString[0] == '1')
					*u = *u |(1U << sizeof(float)*8 - cursorPosision - 1);
				else if(inputString[0] == 'c')
					*u = *u ^(1U << sizeof(float)*8 - cursorPosision - 1);
				else if(inputString[0] == 'e')
					return 0;
				else if(inputString[0] == 's')
					break;
			}
		}
	}
}				
