#include <stdio.h>

int main(void){
	printf("Enter two lines:\n");
	char str1[256];
	char str2[256];
	scanf("%s", str1);
	scanf("%s", str2);

	int n;
	for(n = 0; str1[n] != 0; n++){
	}
	printf("Length of first line is %d\n", n);
	int n1 = n;
	
	for(n = 0; str2[n] != '\0'; n++){
	}
	printf("Length of second line is %d\n", n);
	int n2 = n;

	for(n = 0;;n++){
		if(n >= 256 || (str1[n] == '\0' && str2[n] == '\0')){
			printf("Lines are similar\n");
			break;
		}
		else if(str1[n] != str2[n] || str1[n] == '\0' || str2[n] == '\0'){
			printf("Lines are different\n");
			break;
		}
	}

	char newarr[256];
	for(n = 0; n <= n1; n++){
		newarr[n] = str1[n];
		printf("%c", newarr[n]);
	}
	printf("\n");

	for(n = n1; n < 256 && n < (n1 + n2); n++){
		str1[n] = str2[n - n1];
	}
	if(n == 256){
		str1[255] = '\0';
	}
	else{
		str[n1 + n2] = '\0';
	}

	for(n = 0; n < 256 && n < (n1 + n2); n++){
		printf("%c", str1[n]);
	}
	printf("\n");
	return 0;
}
