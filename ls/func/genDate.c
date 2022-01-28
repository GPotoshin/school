/*
 * =====================================================================================
 *
 *       Filename:  genDate.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2021 22:51:15
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  George Potoshin (GP), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "genDate.h"

const char* genDate(struct timespec input){
	const char* monthNames[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", \
								  "aug", "sep", "oct", "nov", "dec"};
	int daysInYear;
	int gtm = 3;
	int extraDay = 0;
	char* date = malloc(20*sizeof(char));

	if(date == NULL){
		return "Error: no free space for date\n";
	}

	int year   = 1970;
	int month  = 0;
	int day    = 1;
	int hour   = 0;
	int minute = 0;
	int sec    = 0;
	
	input.tv_sec += gtm * 60 * 60;

	for(;;){
		if(year%400 == 0)
			daysInYear = 366;

		else if(year%100 == 0)
			daysInYear = 365;

		else if(year%4 == 0)
			daysInYear = 366;

		else
			daysInYear = 365;

		if(input.tv_sec < daysInYear*24*60*60)
			break;

		input.tv_sec -= daysInYear*24*60*60;
		year++;
	}

	if(daysInYear == 366){
		extraDay = 1;
	}

	for(;;){
		if(input.tv_sec < 24*60*60)
			break;

		input.tv_sec -= 24*60*60;
		day++;
	}

	if(day > 31){
		month++;
		day -= 31;
	}
	if(day > 28 + extraDay){
		month++;
		day -= 28 + extraDay;
	}
	if(day > 31){
		month++;
		day -= 31;
	}
	if(day > 30){
		month++;
		day -= 30;
	}
	if(day > 31){
		month++;
		day -= 31;
	}
	if(day > 30){
		month++;
		day -= 30;
	}
	if(day > 31){
		month++;
		day -= 31;
	}
	if(day > 31){
		month++;
		day -= 31;
	}
	if(day > 30){
		month++;
		day -= 30;
	}
	if(day > 31){
		month++;
		day -= 31;
	}
	if(day > 30){
		month++;
		day -= 30;
	}
	if(day > 31){
		month++;
		day -= 31;
	}

	for(;;){
		if(input.tv_sec < 60*60)
			break;

		input.tv_sec -= 60*60;
		hour++;
	}

	for(;;){
		if(input.tv_sec < 60)
			break;

		input.tv_sec -= 60;
		minute++;
	}

	sec = input.tv_sec;

	

	sprintf(date, "%d\t%d%s\t%d:%d:%d", year, day, monthNames[month], hour, \
			minute, sec);

	return date;
}

