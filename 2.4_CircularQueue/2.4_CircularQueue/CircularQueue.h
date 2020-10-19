#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define QSIZE 5


/* 순환 큐 노드 */
typedef int ElementType;

typedef struct tagNode_ 
{
	ElementType Data;
} Node;


/* 순환 큐 */
typedef struct tagCircularQueue
{
	int Capacity;	/* 용량 */
	int n_items;	/* 아이템 개수 */
	int Front;		/* front 인덱스 */
	int Rear;		/* rear 인덱스 */
	Node* Nodes;	/* 노드 배열 */
} CQ;

/* 순환 큐 인터페이스 함수 */
void CQ_CreateQueue(CQ** queue, int Capacity);

/* 순환 큐 제거 */
void CQ_DestroyQueue(CQ* queue);

/* 노드 삽입 Enqueue */
bool CQ_Enqueue(CQ* queue, ElementType data);

/* 노드 제거 Dequeue */
bool CQ_Dequeue(CQ* queue);

bool CQ_IsFull(CQ* queue);

bool CQ_IsEmpty(CQ* queue);

int getItem(CQ* queue);