#include <stdio.h>

void swap(char str1[], char str2[]);
void sort(char str[][256], int numberOfElements);
int compare(char str1[], char str2[]);

int main(void){
	printf("Enter a number of lines:\n");
	int n;
	scanf("%d", &n);
	char str[n][256];

	for(int i = 0; i < n; i++){
		scanf("%s",&str[i][0]);
	}

	printf("\n");
	sort(str, n);

        for(int i = 0; i < n; i++){
                printf("%s\n", str[i]);
	}
	return 0;
}

void sort(char str[][256], int numberOfElements){
        for(int k = 1; k < numberOfElements; k++){
                for(int i = 0; i < k; i++){
                        if(!compare((char *)(str + k - i), (char *)(str + k - 1 - i))){
                                swap((char *)(str + k - i), (char *)(str + k - 1 - i));
                        }
                }
        }
}

void swap(char str1[], char str2[]){
        char str[256];
	for(int i = 0; i < 256; i++){
		str[i] = str1[i];
		str1[i] = str2[i];
		str2[i] = str[i];
	}
}

int compare(char str1[], char str2[]){
	int i;
	for(i = 0; str1[i] != 0 && str2[i] != 0 && i < 256; i++){
		if(str1[i] > str2[i]){
			return 0;
		}
		else if(str1[i] < str2[i]){
			return 1;
		}
	}
	return 0;
}
