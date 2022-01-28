/*
 * =====================================================================================
 *
 *       Filename:  genDate.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2021 22:55:34
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef GENDATE_H
#define GENDATE_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

const char* genDate(struct timespec input);

#endif /* GENDATE_H */

