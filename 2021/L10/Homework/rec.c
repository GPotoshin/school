#include <stdio.h>

unsigned int fibonacci(unsigned int n){
	if(n == 1){
		return 1;
	}
	if(n == 0){
		return 1;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void){
	unsigned int n;
	printf("Enter n:\n>");
	scanf(" %d", &n);
	printf("Answer is %d\n", fibonacci(n));
	return 0;
}
