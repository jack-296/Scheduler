#ifndef _LIST_H_
#define _LIST_H_
#include <stdio.h>

#define ALLFF	0xFF

typedef unsigned char 	BYTE;
typedef unsigned int 	DWORD;
typedef unsigned short 	WORD;

typedef struct
{
	BYTE next;
}list8_node_t, *list8_node_ptr_t;

typedef struct
{
	BYTE head;
	BYTE tail;
	BYTE size;
	list8_node_ptr_t node;
}list8_t, *list8_ptr_t;

#define LIST_HEAD(l)			((l)->head)
#define LIST_TAIL(l)			((l)->tail)
#define LIST_NEXT(l,h)			((l)->node[(H)].next)
#define LIST_IS_EMPTY(l)		((l)->size == 0)
#define LIST_IS_NOT_EMPTY(l)	((l)->size != 0)


#endif