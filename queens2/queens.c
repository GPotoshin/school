#include <stdio.h>
#include <stdlib.h>
#include <png.h>
#include <strings.h>

#define NO_QUEEN 0
#define QUEEN 1
#define END_OF_ROW 2
#define END_OF_BOARD 3

#define min(x, y) x<y ? x : y
#define max(x, y) x>y ? x : y
#define LOG(x)  

long num = 0;

int logd(long n){
	int l = 0;
	while(n/10 > 0){
		n /= 10;
		l++;
	}
	return l;
}

void printBoard(int board[100][101]){
	LOG("...printing started...\n");
	num++;
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

void drawBoard(int board[100][101]){
	
	char *filename = malloc(sizeof(char)*(logd(num)+1100));
	num++;
	if (!filename) {
		goto _bailout;
	}
	sprintf(filename, "img/%ld.png", num);

	FILE *fp = NULL;
    png_structp png_p = NULL;
    png_infop info_p = NULL;

    fp = fopen(filename, "wb");
    if (fp == NULL)
        goto _bailout;
    png_p = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (png_p == NULL)
        goto _bailout;

    info_p = png_create_info_struct(png_p);
    if (!info_p)
        goto _bailout;

    png_init_io(png_p, fp);

	
	int size = 0;

	while (board[0][size] != END_OF_ROW)
		size++;

	size = 11*size - 1;

	size_t row_bytes = size * sizeof (png_bytep);
	size_t col_bytes = 3 * size * sizeof (png_byte);

	png_bytep *rows = malloc(row_bytes);
    if (!rows)
        goto _bailout;

    bzero(rows, row_bytes);
    for (int i = 0; i < size; i++) {
        rows[i] = (png_byte *)malloc(col_bytes);
        if (!rows[i])
			goto _bailout;
    }

	for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            png_byte *bp = rows[x] + 3 * y;
			if (board[x/11][y/11] == QUEEN && 
					((0 < x%11 && x%11 < 9 && (y%11 == 4 || y%11 == 5)) ||
					((x%11 == 1 || x%11 == 3 || x%11 == 7 || x%11 == 8) && 
					 (y%11 == 3 || y%11 == 6)) ||
					(x%11 == 8 && (y%11 == 2 || y%11 == 7)))) {

				bp[0] = 121;
				bp[1] = 67;
				bp[2] = 145;

			}
			else if (x%11 == 10 || y%11 == 10) {
				bp[0] = 95;
				bp[1] = 111;
				bp[2] = 145;
			}
			else {
				int color = 255 * (((x / 11) + (y / 11)) % 2);
				bp[0] = color;
				bp[1] = color;
				bp[2] = color;
			}
		}        
	}
	
	png_set_IHDR(png_p, info_p, size, size, 8,
      PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE,
      PNG_FILTER_TYPE_BASE);

    png_write_info(png_p, info_p);
    png_write_image(png_p, rows);

    png_write_end(png_p, NULL);

	goto _out;

_bailout:
	printf("Not enough memory!\n");
	printBoard(board);
_out:
	if (filename)
		free (filename);
	if (png_p)
		png_destroy_write_struct (&png_p, &info_p);
	if (fp)
		fclose (fp);
	if (rows) {
        for (int i = 0; i < size; i++) {
            if (rows[i]) {
                free(rows[i]);
                rows[i] = NULL;
            }
        }

        free(rows);
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
		drawBoard(board);
//		printBoard(board);
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
	printf(">>>%ld\n", num);
	return 0;
}
