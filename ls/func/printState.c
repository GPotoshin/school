/*
 * =====================================================================================
 *
 *       Filename:  printState.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2021 12:36:05
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "printState.h"

void printState(struct stat *statObj){

	if((statObj->st_mode & S_IFDIR) == S_IFDIR)
		putchar('d');
	else
		putchar('-');

	if((statObj->st_mode & S_IRUSR) == S_IRUSR)
		putchar('r');
	else
		putchar('-');
	if((statObj->st_mode & S_IWUSR) == S_IWUSR)
		putchar('w');
	else
		putchar('-');
	if((statObj->st_mode & S_IXUSR) == S_IXUSR)
		putchar('x');
	else
		putchar('-');


	if((statObj->st_mode & S_IRGRP) == S_IRGRP)
		putchar('r');
	else
		putchar('-');
	if((statObj->st_mode & S_IWGRP) == S_IWGRP)
		putchar('w');
	else
		putchar('-');
	if((statObj->st_mode & S_IXGRP) == S_IXGRP)
		putchar('x');
	else
		putchar('-');


	if((statObj->st_mode & S_IROTH) == S_IROTH)
		putchar('r');
	else
		putchar('-');
	if((statObj->st_mode & S_IWOTH) == S_IWOTH)
		putchar('w');
	else
		putchar('-');
	if((statObj->st_mode & S_IXOTH) == S_IXOTH)
		putchar('x');
	else
		putchar('-');
}
