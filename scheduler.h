#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_
#include "list.h"

#define SCHEDULER_POOL_SIZE 10
#define SCHEDULER_EXECUTE_FOREVER -1
#define SCH_TASK_PRIORITY_MAX    2


typedef enum 
{
	PTL_HW_POLLING_TASK,
	SCH_EVENT_ID_MAX
}sch_event_id_e;

typedef enum 
{
	SCH_EVENT_READ_DONE,
	SCH_TASK_ID_MAX
}sch_task_id_e;



typedef struct task_t
{
	BYTE task_id;
	BYTE task_state;
	BYTE task_priority;
	BYTE reserve1;
	BYTE (* task_entry)(void * param);
	void * param;
}ty_task_t;

typedef struct TaskBufManage_t
{
	int (*AvailibleArrayIndex)[SCHEDULER_POOL_SIZE];
	unsigned char AvalibleIndexNum;
	unsigned char BufManageListHead;
	unsigned char BufManageListTail;
}TaskBufManage_t;

/* Internal structure of the vtiny, don't use it's attributes directly */
struct my_scheduler_t_
{
	struct
	{
		ty_task_t task_t;
		void *parameter;
		int TaskStates;
		int TaskCurState;
	} tasks[SCHEDULER_POOL_SIZE];
	int index;
};

#endif