#ifndef _EVENT_H
#define _EVENT_H
/*Library include*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "time_convert.h"
#include "ev.h"

#define event_name_len 100

/**
 * Define ev loop as a global variable
 */

extern struct ev_loop *Loop;

/**
 * Event struct
 */
typedef struct _node{
	char event_name[event_name_len];
	struct tm event_date;
}EVENT;

/**
 * Event timer struct
 */
typedef struct _custom_timer{
	ev_timer timer;
	EVENT *event_node;
	struct _custom_timer *next;
}EVENT_TIMER;

/**
 * The yearly calender
 */
extern EVENT_TIMER *Calender[12][31];

/**
 * For keyboard input watcher
 */
extern ev_io stdin_watcher;

/**
 * Initial IO watcher
 */
void Initial_IO_watcher(void);

/**
 * Initial calender
 */
void Initial_calender(void);

/**
 * This function can add node to list
 */
void add_list(EVENT_TIMER *new_event, EVENT_TIMER **head);

/**
 * This function can add a new event to calender
 */
void add_event(TM date, char *name);

/**
 * Print the whole calender
 */
void print_calender(void);

/**
 * Print specific month calender
 */
void print_calender_month(int month);

#endif 