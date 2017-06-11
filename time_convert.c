#include "time_convert.h"

/*
 * Convert TM time struct to seconds from 1900
 */
time_t date_to_seconds(TM date){
	   struct tm info;
	   info.tm_year = date.tm_year - 1900; /* The number of years since 1900   */
	   info.tm_sec = date.tm_sec;         	/* seconds,  range 0 to 59          */
   	info.tm_min = date.tm_min;         	/* minutes, range 0 to 59           */
   	info.tm_hour = date.tm_hour;       	/* hours, range 0 to 23             */
   	info.tm_mday = date.tm_mday;       	/* day of the month, range 1 to 31  */
   	info.tm_mon  = date.tm_mon -1;     	/* month, range 0 to 11             */ 
   	info.tm_isdst = -1;       			/* daylight saving time             */

   	return mktime(&info);
}
/*
 * Convert TM time strcut to standard library struct tm.
 */
void TM_to_std_tm(TM input, struct tm *output){
   if(input.tm_year >= 1900){
      output->tm_year = input.tm_year - 1900; /* The number of years since 1900   */
   }
	
   if(input.tm_sec >= 0 && input.tm_sec <= 59){
      output->tm_sec = input.tm_sec;            /* seconds,  range 0 to 59          */
   }

   if(input.tm_min >= 0 && input.tm_min <= 59){
      output->tm_min = input.tm_min;            /* minutes, range 0 to 59           */
   }

   if(input.tm_hour >= 0 && input.tm_hour <= 23){
      output->tm_hour = input.tm_hour;          /* hours, range 0 to 23             */
   }

   if(input.tm_mday >= 1 && input.tm_mday <= 31){
      output->tm_mday = input.tm_mday;          /* day of the month, range 1 to 31  */
   }

   if(input.tm_mon >= 0 && input.tm_mon <= 11){
      output->tm_mon  = input.tm_mon -1;        /* month, range 0 to 11             */
   }
	
   output->tm_isdst = -1;       			/* daylight saving time             */
}