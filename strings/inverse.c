/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/21/2021 14:16:12
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>


typedef struct Snode snode;

struct Snode{
	const char* string;
	snode* prev;
};

char *inputString(FILE* fp){
	size_t size = 16;
    char *str;
    int ch;
    size_t len = 0;
	
	str = malloc(sizeof(*str)*size);
	if(!str)
		return str;

    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;

        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)
				return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(*str)*len);
}

snode* createSnode(FILE* fp){
	snode* node = malloc(sizeof(snode));
	if(!node)
		return NULL;
	node->string = inputString(fp);
	node->prev = NULL;
	return node;
}

void freeSlist(snode* first){
	if(!first)
		return;
	snode* prev = first->prev;
	free(first);
	freeSlist(prev);
}

void printSlist(snode* node){
	while(node){
		printf("%s\n", node->string);
		node = node->prev;
	}
}

int main(int argc, char *argv[]){
	FILE *inputf = fopen(argv[1], "r");

	snode *next, *node = NULL;

	for(;;){
		next = createSnode(inputf);
		if(!next || feof(inputf)){
			free(next);
			break;
		}
		next->prev = node;
		node = next;
	}

	printSlist(node);
	freeSlist(node);

	return 0;
}
