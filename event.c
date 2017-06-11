#include "event.h"

/**
 * libev loop 
 */
struct ev_loop *Loop;

/**
 * The yearly calender
 */
EVENT_TIMER *Calender[12][31];

/**
 * For keyboard input watcher
 */
ev_io stdin_watcher;

/**
 * libev time out call back
 */
static void timeout_callback(struct ev_loop *loop, ev_timer *w_, int revents){
	EVENT_TIMER *w = (EVENT_TIMER *)w_;

	printf("\n\n-------------------Event time out alert-----------------------\n");
	fflush(stdout);
	printf("Event name : %s\n", w->event_node->event_name);
	fflush(stdout);
	printf("Evnet alert time : %s", asctime(&(w->event_node->event_date)));
	fflush(stdout);
	printf("-------------------Event time out alert end-----------------------\n\n");
	fflush(stdout);
	printf("call back Add new event or print the whole calender (a/b) : ");
	fflush(stdout);
}

/**
 * libev stdin call back
 */
static void stdin_cb(struct ev_loop *loop, ev_io *w_, int revents){
	char command;
	char event_name[event_name_len] = {0};
	TM info;
	scanf(" %c", &command);

	switch(command){
	  case 'a':
	     printf("Event name : ");
	     scanf("%s", event_name);
	     printf("Event slert time in YYYY/MMM/DDD/HHH/mmm/SSS (Year/Month/Day/Hour/minute/second) order :");
	     scanf("%d/%d/%d/%d/%d/%d", &(info.tm_year), &(info.tm_mon), &(info.tm_mday), &(info.tm_hour), &(info.tm_min), &(info.tm_sec));
	     info.tm_isdst = -1;

	     /*Add new event*/
	     add_event(info, event_name);
	     break;
	  case 'b':
	     /*Print the whole calender*/
	     print_calender();
	     break;
	  default:
	     /*Error handle*/
	     printf("command = %d\n", command);
	     break;
	}
	fflush(stdin);
	printf("call back Add new event or print the whole calender (a/b) : ");
	fflush(stdout);
}

/**
 * Initial IO watcher
 */
void Initial_IO_watcher(void){
 	ev_io_init (&stdin_watcher, stdin_cb, /*STDIN_FILENO*/ 0, EV_READ);
 	ev_io_start (Loop, &stdin_watcher);
}

/**
 * Initial calender
 */
void Initial_calender(void){
	/*Set all link list head as NULL*/
	int month_counter;
	int day_counter;
	for(month_counter = 0; month_counter < 12; month_counter++){
		for(day_counter = 0; day_counter < 31; day_counter++){
			Calender[month_counter][day_counter] = NULL;
		}
	}
	
}
/**
 * This function can add node to list
 */
void add_list(EVENT_TIMER *new_event, EVENT_TIMER **head){
	if(new_event == NULL){
		return;
	}
	new_event->next = *head;
	*head = new_event;
}

/**
 * This function can add a new event to calender
 */
void add_event(TM date, char *name){
	EVENT_TIMER *new_event_timer = (EVENT_TIMER *)malloc(sizeof(EVENT_TIMER));

	/*Get local time*/
   	ev_tstamp now_time = ev_now(Loop);

	if(date_to_seconds(date) - now_time > 0){
		/*Prepare new event*/
		new_event_timer->event_node = (EVENT *)malloc(sizeof(EVENT));
		snprintf(new_event_timer->event_node->event_name, sizeof(new_event_timer->event_node->event_name), "%s", name);
		TM_to_std_tm(date, &(new_event_timer->event_node->event_date));
		new_event_timer->next = NULL;	

		/*Set up libev timer*/
		//printf("delta = %f\n", (ev_tstamp)date_to_seconds(date) - now_time);
		ev_timer_init(&new_event_timer->timer, timeout_callback, (ev_tstamp)date_to_seconds(date) - now_time, 0);
		ev_timer_start(Loop, &new_event_timer->timer);

		add_list(new_event_timer, &(Calender[date.tm_mon - 1][date.tm_mday -1]));
	}
}
/**
 * Print the whole calender
 */
void print_calender(void){
	int month_counter;
	int day_counter;
	for(month_counter = 0; month_counter < 12; month_counter++){
		for(day_counter = 0; day_counter < 31; day_counter++){
			EVENT_TIMER *tmp = NULL;
			for(tmp = Calender[month_counter][day_counter]; tmp != NULL; tmp = tmp->next){
				printf("-----------------------Event-----------------------\n");
				printf("Event name = %s\n", tmp->event_node->event_name);
				printf("Evnet alert time : %s", asctime(&(tmp->event_node->event_date)));
				printf("-----------------------Event-----------------------\n\n");
			}
		}
	}
}

/**
 * Print specific month calender
 */
void print_calender_month(int month);