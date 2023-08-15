#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNTING_METHOD 1
#define INSERTION_METHOD 2
#define BUBBLE_METHOD 3
#define INT_MIN -2147483647

void sortUsingCountingMethod(int *pointer, int numberOfElements);
void sortUsingInsertionMethod(int *pointer, int numberOfElements);
void sortUsingBubbleMethod(int *pointer, int numberOfElements);

void swap(int *xp, int *yp);




int main(void){

    int numberOfElements = 10;

    /*      
    printf("Enter number of elements:\n>");
    scanf(" %d", &numberOfElements);
    printf("\n");

    int arr[numberOfElements];
    */
    int *arrPointer;

    int arr[10] = {5, 4, 3, 3, 3, 0, 2, 1, 3,-50}; 

    arrPointer = arr;

    srand((unsigned int)time(NULL));

    /*        
    for(int i = 0; i < numberOfElements; i++){
    arr[i] = rand() % 101;
    printf("%d:\t%d\n", i, arr[i]);
    }
    */

    printf("\n");

    int method;
    printf("Choose the method:\n");
    printf("Press 1 to choose counting sort\n");
    printf("Press 2 to choose insertion sort\n");
    printf("Press 3 to choose bubble sort\n>");

    scanf(" %d", &method);


    if(method == COUNTING_METHOD){
        sortUsingCountingMethod(arrPointer, numberOfElements);
    }
    else if(method == INSERTION_METHOD){
        sortUsingInsertionMethod(arrPointer, numberOfElements);
    }
    else if(method == BUBBLE_METHOD){
        sortUsingBubbleMethod(arrPointer, numberOfElements);
    }

    printf("\n");

    for(int i = 0; i < numberOfElements; i++){
        printf("%d:\t%d\n", i, arr[i]);
    }

    return 0;
}



void sortUsingCountingMethod(int *pointer, int numberOfElements){
    int new_arr[numberOfElements];

    for(int i = 0; i < numberOfElements; i++){
        new_arr[i] = *(pointer + i);
    }

    for(int i = 0; i < numberOfElements; i++){
        int n = 0, _min = INT_MIN;
        for(int k = 0; k < numberOfElements; k++){
            if(new_arr[k] != INT_MIN){
                _min = new_arr[k];
                n = k;
                break;
            }
        }


        if(_min == INT_MIN){
            break;
        }


        for(int k = n + 1; k < numberOfElements; k++){
            if(new_arr[k] != INT_MIN){
                if(_min > new_arr[k]){
                    _min = new_arr[k];
                    n = k;
                }
            }
        }

        *(pointer + i) = _min;
        new_arr[n] = INT_MIN;
    }
}

void sortUsingInsertionMethod(int *pointer, int numberOfElements){
    for(int k = 1; k < numberOfElements; k++){
        for(int i = 0; i < k; i++){
            if(*(pointer + k - i) < *(pointer + k - 1 - i)){
                swap(pointer + k - i, pointer + k - 1 - i);
            }
        }
    }
}

void sortUsingBubbleMethod(int *pointer, int numberOfElements){
    int lastSwap;
    for(int k = numberOfElements; k > 1; k = lastSwap){
        lastSwap = 0;
        for(int i = 1; i < k; i++){
            if(*(pointer + i - 1) > *(pointer + i)){
                swap(pointer + i - 1, pointer + i);
                lastSwap = i;
            }
        }
    }
}

void swap(int *xp, int *yp){
    *xp = *xp + *yp;
    *yp = *xp - *yp;
    *xp = *xp - *yp;
}
