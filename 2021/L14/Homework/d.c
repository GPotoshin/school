#include <stdio.h>
#include <math.h>

int main(void){
	printf("Enter a number:\n");
	int n;
	scanf("%d", &n);
	if(n == 0){
		printf("%c", '0');
		return 0;
	}
	if(n < 0){
		n = -n;
		printf("-");
	}
	int nd = (int) log10(n) + 1;
	for(int i = 0; i < nd; i++){
		printf("%c",(char)('0' + n/pow(10,nd - i - 1)));
		n -= (int)(n / pow(10, nd - i - 1)) * pow(10, nd - i - 1);
	}
	printf("\n");
	return 0;
}
