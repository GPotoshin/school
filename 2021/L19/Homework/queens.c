#include <stdio.h>
#include <stdlib.h>

#define NO_QUEEN 0
#define QUEEN 1
#define END_OF_ROW 2
#define END_OF_BOARD 3

#define min(x, y) x<y ? x : y
#define max(x, y) x>y ? x : y
#define LOG(x)  



void printBoard(int board[100][101]){
	LOG("...printing started...\n");
	printf(" \n");
	for(int row = 0;; row++){
		for(int posInRow = 0;; posInRow++){
			if(board[row][posInRow] == NO_QUEEN)
				putchar('-');
			else if(board[row][posInRow] == QUEEN)
				putchar('Q');
			else if(board[row][posInRow] == END_OF_ROW){
				putchar('\n');
				break;
			}
			else if(board[row][posInRow] == END_OF_BOARD){
				putchar('\n');
				LOG("...end of printing...\n");
				return;
			}
			else{
				printf("\nError in **board: %d is invalid value\n", board[row][posInRow]);
				return;
			}
		}
	}
}

int positionIsAvailable(int board[100][101], int posInColumn, int column, int size){
	for(int i = 0; i < column; i++){
		if(board[posInColumn][i] == QUEEN)
			return 0;
	}
	for(int i = 1; posInColumn-i >= 0 && column+i < size; i++){
		if(board[posInColumn-i][column+i] == QUEEN)
			return 0;
	}
	for(int i = 1; posInColumn-i >= 0 && column-i >= 0; i++){
		if(board[posInColumn-i][column-i] == QUEEN)
			return 0;
	}
	for(int i = 1; posInColumn+i < size && column+i < size; i++){
		if(board[posInColumn+i][column+i] == QUEEN)
			return 0;
	}
	for(int i = 1; posInColumn+i < size && column-i >= 0; i++){
		if(board[posInColumn+i][column-i] == QUEEN)
			return 0;
	}
	return 1;
}

void try(int board[100][101], int column, long size){
	if(column == size){
		printBoard(board);
		return;
	}
	

	for(int posInColumn = 0; posInColumn < size; posInColumn++){
		if(positionIsAvailable(board, posInColumn, column, size)){
			board[posInColumn][column] = QUEEN;
			try(board, column+1, size);
			board[posInColumn][column] = NO_QUEEN;
		}
	}
}



int main(int argc, char *argv[]){
	long size;
	char *endc;
	int board[100][101];
	LOG("...preinitialization finished...\n");
	for(int i = 1; i < argc; i++){
		size = strtol(argv[i], &endc, 10);
		if(*endc == '\0'){
			if(size > 100)
				printf("%s is a bad value. It must be less or equal to 100\n", argv[i]);
				
			else{
				printf("SIZE: %ld\n", size);
				for(int row = 0; row < size; row++){
					for(int column = 0; column < size; column++)
						board[row][column] = NO_QUEEN;
					board[row][size] = END_OF_ROW;
				}
				board[size-1][size] = END_OF_BOARD;
				try(board, 0, size);
			}
		}
		else
			printf("%s is a bad value\n", argv[i]);
	}
	return 0;
}
