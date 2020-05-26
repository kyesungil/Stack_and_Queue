#pragma once
#include <stdlib.h>
#include "list.h"

/* Linked list Stack구현 */

/* 스택 포인터 위치에 저장된 데이터 포인터 */
#define stack_peek(stack) ((stack)->head == NULL?NULL:(stack)->head->data)

/* 스택 Push 동작 */
/* linked list의 head로 데이터 저장 */
int stack_push(Stack* stack, const void* data)
{
	return list_ins_next(stack, NULL, data);
}


/* 스택 pop 동작 */
/* linked list의 head에서 데이터 retrieve */
int stack_pop(Stack* stack, void** data)
{
	return list_rem_next(stack, NULL, data);
}