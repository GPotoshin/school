#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int *base, int nullElement, int width);
void swap(int *xp, int *yp);



int main(void){
	int width;

	printf("Enter the number of elements:\n>");
	scanf("%d", &width);

	int arr[width];
	srand((unsigned int)time(NULL));

	printf("\nRandom array:\n");
	for(int i = 0; i < width; i++){
		arr[i] = 0 * rand() % 101;
		printf("%d:\t%d\n", i, arr[i]);
	}

	printf("\nSorted:\n");

	sort(arr, 0, width);

	for(int i = 0; i < width; i++){
		printf("%d:\t%d\n", i, arr[i]);
	}

	return 0;
}

void sort(int *base, int nullElement, int width){
	if(width < 2){
		return;
	}

	srand((unsigned int)time(NULL));
	int pivotElement = rand() % width + nullElement;

	int i = nullElement, k = pivotElement + 1;
		for(; i < pivotElement; i++){
			if(*(base + i) > *(base + pivotElement)){
				for(; k < width + nullElement; k++){
					if(*(base + k) < *(base + pivotElement)){
						swap(base + i, base + k);
					}
				}
			}
			if(k >= width + nullElement){
				for(; i < pivotElement; i++){
					if(*(base + i) > *(base + pivotElement)){
						swap(base + pivotElement, base + i);
						pivotElement--;
						for(int m = i; m < pivotElement; m++){
							swap(base + m, base + m + 1);
						}
						i--;
					}
				}
			break;
			}
		}
		for(;k < width + nullElement; k++){
			if(*(base + k) < *(base + pivotElement)){
				swap(base + k, base + pivotElement);
				pivotElement++;
				for(int m = k; m > pivotElement; m--){
					swap(base + m, base + m - 1);
				}
			}
 		}

	sort(base, nullElement, pivotElement - nullElement);
	sort(base, pivotElement + 1, nullElement + width - 1 - pivotElement);
}


void swap(int *xp, int *yp){
	*xp = *xp + *yp;
	*yp = *xp - *yp;
	*xp = *xp - *yp;
}
