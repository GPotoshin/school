#include <stdio.h>
#include <math.h>

typedef	unsigned int t_gcd;

int max(int a, int b){
	if (a > b){
		return a;
	}
	else{
		return b;
	}
}
	
t_gcd gcd(int a, int b){
	for(;;){
		if (a == 1 || b == 1){
			return 1;
		}
		if (a % b == 0){
			return b;
		}
		if (b % a == 0){
			return a;
		}

		a = a % b;
		printf("%d\n", a);
		b = b % a;
		printf("%d\n", b);
	}
}


int main(void){
	unsigned int a, b, c;

	printf("Enter first number\n>");
	scanf(" %u", &a);

	printf("Enter second number\n>");
	scanf(" %u", &b);

	printf("Enter therd number\n>");
	scanf(" %u", &c);


	t_gcd ngcd = gcd(a, b);

	printf("GCD of first and second numbers is %u\n", ngcd);
	printf("GCD of first, second and third numbers is %u\n", gcd(ngcd, c));
	printf("LCM of first and second numbers is %u\n", a * b / ngcd);
	
	return 0;
}
