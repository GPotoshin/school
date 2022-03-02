/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/14/2022 14:04:30
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), george.potoshin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int age;
	char *sort;
} salamon;


int main () {
	salamon s;
	s.age = -0x10;
	printf("%d\n", s.age);
	return 0;
}
