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
#include <string.h>


typedef struct Snode snode;


struct Snode {
	const char* string;
	snode* next;
};

char *inputString (FILE *fp){
	size_t size = 16;
    char *str;
    int ch;
    size_t len = 0;
	
	str = malloc (sizeof (*str) * size);
	if (!str)
		return str;

    while (EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++] = ch;

        if(len == size){
            str = realloc (str, sizeof (*str)*(size+=16));
            if (!str)
				return str;
        }
    }
    str[len++] = '\0';

    return realloc (str, sizeof (*str)*len);
}

snode *nextSnode (FILE *fp) {
	snode *node = malloc (sizeof (snode));
	if (!node)
		goto _out;

	node->string = inputString (fp);
	node->next = NULL;

_out:
	return node;
}

snode *sInsert (snode *node, snode *list) {
	if (list == NULL) {
		list = node;
		goto _out;
	}

	snode *iter = list;
	snode *prev;
	while (strcmp(iter->string, node->string) < 0) {
		if (iter->next == NULL) {
			iter->next = node;
			goto _out;
		}
		
		prev = iter;
		iter = iter->next;
	}
	
	if (iter == list) {
		node->next = list;
		list = node;
		goto _out;
	}

	prev->next = node;
	node->next = iter;

_out:
	return list;

}

void printSlist (snode *list) {
	while (list) {
		puts(list->string);
		list = list->next;
	}
}

void freeSlist (snode *list) {
	while (list) {
		snode *buf = list->next;
		free (list);
		list = buf;
	}
}

int main (int argc, char *argv[]) {
	if (argc == 1) {
		printf ("There must be at least one argument!\n");
		return 0;
	}

	for (int i = 1; i < argc; i++) {
		FILE *fp = fopen (argv[i], "r");

		if (fp == NULL) {
			printf ("Can't find %s file\n", argv[i]);
			continue;
		}

		snode *node = NULL;
		snode *list = NULL;
		while (!feof (fp)) {
			node = nextSnode (fp);
			if (!node)
				break;
			list = sInsert (node, list);
		}

		printSlist (list);
		freeSlist (list);
	}
}
