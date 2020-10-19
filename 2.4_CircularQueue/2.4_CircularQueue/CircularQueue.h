#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define QSIZE 5


/* ��ȯ ť ��� */
typedef int ElementType;

typedef struct tagNode_ 
{
	ElementType Data;
} Node;


/* ��ȯ ť */
typedef struct tagCircularQueue
{
	int Capacity;	/* �뷮 */
	int n_items;	/* ������ ���� */
	int Front;		/* front �ε��� */
	int Rear;		/* rear �ε��� */
	Node* Nodes;	/* ��� �迭 */
} CQ;

/* ��ȯ ť �������̽� �Լ� */
void CQ_CreateQueue(CQ** queue, int Capacity);

/* ��ȯ ť ���� */
void CQ_DestroyQueue(CQ* queue);

/* ��� ���� Enqueue */
bool CQ_Enqueue(CQ* queue, ElementType data);

/* ��� ���� Dequeue */
bool CQ_Dequeue(CQ* queue);

bool CQ_IsFull(CQ* queue);

bool CQ_IsEmpty(CQ* queue);

int getItem(CQ* queue);