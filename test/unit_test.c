#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "time_convert.h"
#include "event.h"
#include "ev.h"

void test_time_convert_date_to_seconds(void){
   printf("test_time_convert_date_to_seconds\n");
   int diff;
   TM info;

   info.tm_year = 2001;
   info.tm_mon = 7;
   info.tm_mday = 4;
   info.tm_hour = 0;
   info.tm_min = 0;
   info.tm_sec = 1;
   info.tm_isdst = -1;

   int ret;
   struct tm info_tm;

   info_tm.tm_year = 2001 - 1900;
   info_tm.tm_mon = 7 - 1;
   info_tm.tm_mday = 4;
   info_tm.tm_hour = 0;
   info_tm.tm_min = 0;
   info_tm.tm_sec = 1;
   info_tm.tm_isdst = -1;

   ret = mktime(&info_tm);

   printf("%d\n",date_to_seconds(info));
   printf("%d\n", ret);
   diff = ret - date_to_seconds(info);
   if(diff == 0){
      printf("test_time_convert_date_to_seconds : Pass\n");
   }else{
      printf("test_time_convert_date_to_seconds : Fail\n");
   }
}

void test_time_convert_TM_to_std_tm(void){
   printf("test_time_convert_TM_to_std_tm\n");
   TM info;

   info.tm_year = 2002;
   info.tm_mon = 7;
   info.tm_mday = 4;
   info.tm_hour = 0;
   info.tm_min = 0;
   info.tm_sec = 1;
   info.tm_isdst = -1;
   printf("%d\n", date_to_seconds(info));
   
   struct tm info_tm;
   TM_to_std_tm(info, &info_tm);
   
   int ret = mktime(&info_tm);
   printf("%d\n", ret);

   int diff = ret - date_to_seconds(info);
   if(diff == 0){
      printf("test_time_convert_TM_to_std_tm : Pass\n");
   }else{
      printf("test_time_convert_TM_to_std_tm : Fail\n");
   }
}

int main(int argc, char const *argv[])
{
   test_time_convert_TM_to_std_tm();
   test_time_convert_date_to_seconds();
   return 0;
}