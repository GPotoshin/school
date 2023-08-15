#include <stdio.h>


void swap(char *xp, char *yp){
	*xp = *yp + *xp;
	*yp = *xp - *yp;
	*xp = *xp - *yp;
}

int main(void){
	char str[256];
	printf("Enter the line:\n");
	scanf("%s", str);

	int n;
	for(n = 0; str[n] != '\0' && n < 256; n++){
		if((str[n] > '\0' && str[n] < 'A') || (str[n] > 'Z' && str[n] < 'a') || str[n] > 'z'){
			for(int i = n; str[i] != '\0' && i < 256; i++){
				swap(str + i, str + i + 1);
			}
			n--;
		}
	}

	int i;
	#if CASE == 2
		for(i = 0; i < n; i++){
			if(str[i] > 'A' - 1 && str[i] < 'Z' + 1){
				str[i] = str[i] + ('a' - 'A');
			}
		}	
	#endif /* CASE == 2 */


        for(i = 0; i < n / 2; i++){
                if(str[i] != str[n - i - 1]){
                        printf("It is not a palindrome\n");
                        break;
                }
        }

        if(i == n / 2){            
                printf("It is a polindrome\n");
        }

	return 0;
}
