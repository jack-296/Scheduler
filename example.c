#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "list.h"
#include "scheduler.h"

list8_t sch_task_ready_list[SCH_TASK_PRIORITY_MAX];
list8_t sch_event_list[SCH_EVENT_ID_MAX];

int main(void)
{

	return 0;
}
