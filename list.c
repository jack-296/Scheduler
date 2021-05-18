#include "list.h"

void list8_reset(list8_ptr_t list)
{
	list->head = ALLFF;
	list->tail = ALLFF;
	list->size = 0;
	list->node = NULL;
}

void list8_init(list8_ptr_t list, list8_node_ptr_t node)
{
	list8_reset(list);
	list->node = node;
}

void list8_push(list8_ptr_t list, BYTE h)
{
	if(list->size == 0)
	{
		list->head = h;
		list->tail = h;
		list->node[h].next = ALLFF;
	}
	else
	{
		list->node[list->tail].next = h;
		list->node[h].next = ALLFF;
		list->tail = h;
	}
	list->size++;
}

BYTE list8_pop(list8_ptr_t list)
{
	BYTE h;
	BYTE n;

	h = list->head;
	n = list->node[list->head].next;

	list->head = n;
	list->node[h].next = ALLFF;

	list->size--;

	if(list->size == 0)
	{
		list->tail = ALLFF;
	}
	
	return h;
}