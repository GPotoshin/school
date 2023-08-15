#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int t_natural;

int max(int a, int b);
int min(int a, int b);

int main(void){
	t_natural numberOfElements;
	printf("Enter number of elements:\n>");
	scanf(" %u", &numberOfElements);

	int arr[numberOfElements];
	srand(time(NULL));

	for(int i = 0; i < numberOfElements; i++){
		arr[i] = rand() % 1256;
		printf("%d:  %d\n", i, arr[i]);
	}

	int _max = arr[0];
	int _min = arr[0];
	long sum = arr[0];
	double meanSquare = arr[0] * arr[0] / numberOfElements;

	for(int i = 1; i < numberOfElements; i++){
		_max = max(_max, arr[i]);
		_min = min(_min, arr[i]);
		sum += arr[i];
		meanSquare += arr[i] * arr[i] / numberOfElements;
	}

	double mean = (double) sum / numberOfElements;
	double dispersion = 0;

	for(int i = 0; i < numberOfElements; i++){
		dispersion += (double) (arr[i] - mean) * (arr[i] - mean) / numberOfElements; 
	}

	printf("Mean square is %lf\n", meanSquare);
	printf("Dispersion is equal to %lf\n", dispersion);
	printf("Maximum is equal to %d\n", _max);
	printf("Minimum is equal to %d\n", _min);
	printf("Mean is equal to %lf\n", mean);


	return 0;
}



int min(int a, int b){
	if (a < b){
		return a;
	}
	else{
		return b;
	}
}
int max(int a, int b){
	if (a > b){
		return a;
	}
	else{
		return b;
	}
}
