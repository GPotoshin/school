#include <stdio.h>

#if CASE == 2
void drawCase2(int *arr);
void goDown(int *arr);
void goUp(int *arr);
#endif /* CASE == 2 */

#if CASE == 3
void drawCase3(int *arr);
void goRight(int *arr);
void goDown(int *arr);
void goLeft(int *arr);
void goUp(int *arr);
#endif /* CASE == 3 */

int h, w, x, y, i;


int main(void){
	printf("Enter hight:\n");
	scanf("%d", &h);
	printf("Enter width:\n");
	scanf("%d", &w);
	int arr[h][w];

#if CASE == 1
	for(int i = 0; i < h*w; i++){
		if(i/w%2 == 0){
			arr[i/w][i%w] = i;
		}
		else{
			arr[i/w][h-i%w-1] = i;
		}
	}
#endif /* CASE == 1 */

#if CASE == 2
	drawCase2((int *)arr);
#endif /* CASE == 2 */

#if CASE == 3
	drawCase3((int *)arr);
#endif /* CASE == 3 */

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}



#if CASE == 2
void drawCase2(int *arr){
	*arr = 0;
	x = 1;
	y = 0;	i = 1;
	goDown(arr);
}
void goDown(int *arr){
	if(i == h*w - 1){
		*(arr + w*h - 1) = i;
		return;
	}
	for(;y < h && x >= 0; i++){
		*(arr + y*h + x) = i;
		x--;
		y++;
	}
	x++;
	if(y >= h){
		y--;
		x++;
	}
	goUp(arr);
}
void goUp(int *arr){	
        if(i == h*w - 1){
                *(arr + w*h - 1) = i;
                return;
        }
        for(;y >= 0 && x < w; i++){
                *(arr + y*h + x) = i;
                x++;
                y--;
        }
        y++;
	if(x >= w){
		x--;
		y++;
	goDown(arr);
}

}
#endif /* CASE == 2 */

#if CASE == 3
void drawCase3(int *arr){
	for(i = 0; i < w; i++){
		*(arr + i) = i;
	}
	if(h == 1){
		return;
	}
	for(int j = i; j < h*w; j++){
		*(arr + j) = h*w;
	}
	for(; i < h + w - 1; i++){
		*(arr + (i - w + 2)*w - 1) = i;
	}
	for(; i < h + 2*w - 2; i++){
		*(arr + h*w - i + h + w - 3) = i;
	}
	x = 0;
	y = h - 1;
	goUp(arr);
}
void goRight(int *arr){
	if(*(arr + y*w + x + 1) != h*w){
		return;
	}
	for(; i < *(arr + y*w + x + 1); i++){
		x++;
		*(arr + y*w + x) = i;
	}
	goDown(arr);
}
void goDown(int *arr){
	if(*(arr + (y + 1)*w + x) != h*w){
		return;
	}
	for(; i < *(arr + (y + 1)*w + x); i++){
		y++;
		*(arr + y*w + x) = i;
	}
	goLeft(arr);
}
void goLeft(int *arr){
	if(*(arr + y*w + x - 1) != h*w){
		return;
	}
	for(; i < *(arr + y*w + x - 1); i++){
		x--;
		*(arr + y*w + x) = i;
	}
	goUp(arr);
}
void goUp(int *arr){
	if(*(arr + (y - 1)*w + x) != h*w){
		return;
	}
	for(; i < *(arr + (y - 1)*w + x); i++){
		y--;
		*(arr + y*w + x) = i;
	}
	goRight(arr);
}
#endif /* CASE == 3 */
