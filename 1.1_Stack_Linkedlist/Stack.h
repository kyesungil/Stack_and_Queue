#pragma once
#include <stdlib.h>
#include "list.h"

/* Linked list Stack���� */

/* ���� ������ ��ġ�� ����� ������ ������ */
#define stack_peek(stack) ((stack)->head == NULL?NULL:(stack)->head->data)

/* ���� Push ���� */
/* linked list�� head�� ������ ���� */
int stack_push(Stack* stack, const void* data)
{
	return list_ins_next(stack, NULL, data);
}


/* ���� pop ���� */
/* linked list�� head���� ������ retrieve */
int stack_pop(Stack* stack, void** data)
{
	return list_rem_next(stack, NULL, data);
}