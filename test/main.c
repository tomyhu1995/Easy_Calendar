#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "time_convert.h"
#include "event.h"
#include "ev.h"


int main(int argc, char const *argv[])
{
   Loop = ev_loop_new(EVFLAG_AUTO);

   Initial_IO_watcher();
   Initial_calender();

   printf("Add new event or print the whole calender (a/b) : ");
   fflush(stdout);

   while(1){
      ev_run(Loop, EVRUN_NOWAIT);
   }

	return 0;
}