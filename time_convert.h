#ifndef _TIME_CONVERT_H
#define _TIME_CONVERT_H
/*Library include*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

typedef struct _TM_{
	int tm_sec;         /* seconds,  range 0 to 59          */
   	int tm_min;         /* minutes, range 0 to 59           */
   	int tm_hour;        /* hours, range 0 to 23             */
   	int tm_mday;        /* day of the month, range 1 to 31  */
   	int tm_mon;         /* month, range 1 to 12             */
   	int tm_year;        /* The number of years since 1900   */
   	int tm_wday;        /* day of the week, range 0 to 6    */
   	int tm_yday;        /* day in the year, range 0 to 365  */
   	int tm_isdst;       /* daylight saving time             */	
}TM;

/*
 * Convert TM time struct to seconds from 1900
 */
time_t date_to_seconds(TM date);
/*
 * Convert TM time strcut to standard library struct tm.
 */
void TM_to_std_tm(TM input, struct tm *output);

#endif