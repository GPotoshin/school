/*
 * =====================================================================================
 *
 *       Filename:  gizmos.c
 *
 *    Description:	functions that are not straightly related to grooph idea
 *					but I realy want (need) to implement them
 *
 *        Version:  1.0
 *        Created:  02/19/2022 23:23:07
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), george.potoshin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

char *cstr (const char* str) {
	char* retval = NULL;

	int l;
	for (l = 0; str[l] != 0; l++);

	retval = malloc (sizeof(char) * l);
	if (retval == NULL)
		goto _bailout;

	for (int i = 0; i <= l; i++)
		*(retval + i) = *(str + i);

_bailout:
	return retval;
}


