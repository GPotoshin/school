/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  my ls
 *
 *        Version:  1.0
 *        Created:  09/17/2021 10:53:45
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "myls.h"



int main(int argc, char* argv[]){

	struct stat *statObj = malloc(sizeof(struct stat));

	for(int i = 1; i < argc; i++){

		if(lstat(argv[i], statObj) == -1){
			printf("ls: %s: No such file or directory\n", argv[i]);
			continue;
		}
		
		printState(statObj);
		putchar('\t');
//		printf("%s %s\n", genDate(statObj->st_mtim), argv[i]); /* for freeBSD */
		printf("%s %s\n", genDate(statObj->st_mtimespec), argv[i]); /* for macOS */
		
	}

	return 0;
}
