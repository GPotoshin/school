#include <stdio.h>

#if CASE == 2

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
	for(x = 0; x < w; x++){
		for(y = 0; y < h; y++){
			if((x + y)%2 == 0){
				if(x + y < (w < h ? w : h)){
					arr[y][x] = (x + y)*(x + y + 1)/2 + x;
				}
				else if(x + y < (w > h ? w : h)){
					arr[y][x] = (w < h ? w : h)*((w < h ? w : h) + 1)/2 + (x + y - (w < h ? w : h))*((x < y ? x : y) + 1) + x;
				}
				else{
					arr[y][x] = h*w - (h-y + w-x - 1)*(h-y + w-x)/2 + h - y - 1;
				}
			}
			else{
				if(x + y < (w < h ? w : h)){
					arr[y][x] = (x + y)*(x + y + 1)/2 + y;
				}
				else if(x + y < (w > h ? w : h)){
					arr[y][x] = (w < h ? w : h)*((w < h ? w : h) + 1)/2 + (x + y - (w < h ? w : h))*((x < y ? x : y) + 1) + y;
				}
				else{
					arr[y][x] = h*w - (h-y + w-x - 1)*(h-y + w-x)/2 + w - x - 1;
				}
			}
		}
	}
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
