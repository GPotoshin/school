#include <stdio.h>
#include <stdlib.h>

#define WE_WERE_NOT_THERE 0
#define END_OF_ROW 10101
#define END_OF_BOARD 10102

#define min(x, y) x<y ? x : y
#define max(x, y) x>y ? x : y


void printBoard(int board[100][101]){
	printf(">\n");
	for(int row = 0;; row++){
		for(int posInRow = 0;; posInRow++){
			if(board[row][posInRow] == END_OF_ROW){
				printf("\n\n");
				break;
			}
			else if(board[row][posInRow] == END_OF_BOARD){
				putchar('\n');
				return;
			}
			else
				printf("%d\t", board[row][posInRow]);
		}
	}
}

int positionIsAvailable(int board[100][101], long xpos, long ypos, long hight, long width){
	if(board[ypos][xpos] == 0 && xpos<width && ypos<hight && xpos >= 0 && ypos>= 0)
		return 1;
	return 0;
}

void try(int board[100][101], long xpos, long ypos, long hight, long width, int counter){
	if(counter == width*hight + 1){
		printBoard(board);
		return;
	}
	

	
	if(positionIsAvailable(board, xpos+2, ypos+1, hight, width)){
		board[ypos+1][xpos+2] = counter;
		try(board, xpos+2, ypos+1, hight, width, counter+1);
		board[ypos+1][xpos+2] = WE_WERE_NOT_THERE;
	}
	if(positionIsAvailable(board, xpos+2, ypos-1, hight, width)){
		board[ypos-1][xpos+2] = counter;
		try(board, xpos+2, ypos-1, hight, width, counter+1);
		board[ypos-1][xpos+2] = WE_WERE_NOT_THERE;
	}
	if(positionIsAvailable(board, xpos+1, ypos+2, hight, width)){
		board[ypos+2][xpos+1] = counter;
		try(board, xpos+1, ypos+2, hight, width, counter+1);
		board[ypos+2][xpos+1] = WE_WERE_NOT_THERE;
	}
	if(positionIsAvailable(board, xpos+1, ypos-2, hight, width)){
		board[ypos-2][xpos+1] = counter;
		try(board, xpos+1, ypos-2, hight, width, counter+1);
		board[ypos-2][xpos+1] = WE_WERE_NOT_THERE;
	}
	if(positionIsAvailable(board, xpos-2, ypos+1, hight, width)){
		board[ypos+1][xpos-2] = counter;
		try(board, xpos-2, ypos+1, hight, width, counter+1);
		board[ypos+1][xpos-2] = WE_WERE_NOT_THERE;
	}
	if(positionIsAvailable(board, xpos-2, ypos-1, hight, width)){
		board[ypos-1][xpos-2] = counter;
		try(board, xpos-2, ypos-1, hight, width, counter+1);
		board[ypos-1][xpos-2] = WE_WERE_NOT_THERE;
	}
	if(positionIsAvailable(board, xpos-1, ypos+2, hight, width)){
		board[ypos+2][xpos-1] = counter;
		try(board, xpos-1, ypos+2, hight, width, counter+1);
		board[ypos+2][xpos-1] = WE_WERE_NOT_THERE;
	}
	if(positionIsAvailable(board, xpos-1, ypos-2, hight, width)){
		board[ypos-2][xpos-1] = counter;
		try(board, xpos-1, ypos-2, hight, width, counter+1);
		board[ypos-2][xpos-1] = WE_WERE_NOT_THERE;
	}
}



int main(int argc, char *argv[]){
	long hight;
	long width;
	long xpos;
	long ypos;
	char *endhc;
	char *endwc;
	char *endxc;
	char *endyc;
	int board[100][101];
	for(int i = 0; i < argc/4; i++){
		hight = strtol(argv[i*4+1], &endhc, 10);
		width = strtol(argv[i*4+2], &endwc, 10);
		xpos  = strtol(argv[i*4+3], &endxc, 10);
		ypos  = strtol(argv[i*4+4], &endyc, 10);
		if(*endhc == '\0' && *endwc == '\0' &&  *endxc == '\0' && *endyc == '\0'){
			if(hight > 100)
				printf("%ld is a bad value. It must be less or equal to 100\n", hight);
			else if(width > 100)
				printf("%ld is a bad value. It must be less or equal to 100\n", width);
			else if(xpos+1 > width)
				printf("%ld is a bad value. It must be less or equal to %ld\n", xpos, width);
			else if(ypos+1 > hight)
				printf("%ld is a bad value. It must be less or equal to %ld\n", ypos, hight);
			else{
				printf("HIGHT: %ld  WIDTH: %ld  XPOS: %ld  YPOS: %ld\n", hight, width, xpos, ypos);
				for(int row = 0; row < hight; row++){
					for(int column = 0; column < width; column++)
						board[row][column] = WE_WERE_NOT_THERE;
					board[row][width] = END_OF_ROW;
				}
				board[ypos][xpos] = 1;
				board[hight-1][width] = END_OF_BOARD;
				try(board, xpos, ypos, hight, width, 2);
			}
		}
		else
			printf("%s, %s, %s, %s are bad values\n", argv[i*4+1], argv[i*4+2], argv[i*4+3], argv[i*4+4]);
	}
	return 0;
}
