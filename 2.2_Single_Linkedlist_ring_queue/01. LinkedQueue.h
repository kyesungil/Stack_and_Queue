#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TSIZE 45
#define MAXTIEMS 3

struct element
{
	char name[TSIZE];
} element;

typedef struct element Item;


typedef struct node
{
	Item item;
	struct node* next;
} Node;


typedef struct queue
{
	Node* front;
	Node* rear;
	int n_items;
} Queue;

void InitializeQueue(Queue* pq);
bool QueueIsFull(const Queue* pq);
bool QueueIsEmpty(const Queue* pq);
int QueueItemCount(const Queue* pq);
bool EnQueue(Item item, Queue* pq);
bool DeQueue(Item* pitem, Queue* pq);
void EmptyTheQueue(Queue* pq);
void TraverseQueue(Queue* pq, void(*func)(Item item));



void InitializeQueue(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->n_items = 0;
}


bool QueueIsFull(const Queue* pq)
{
	return pq->n_items == MAXTIEMS;
}

bool QueueIsEmpty(const Queue* pq)
{
	return pq->n_items == 0;
}


int QueueItemCount(const Queue* pq)
{
	return pq->n_items;
}


bool EnQueue(Item item, Queue* pq)
{
	if (QueueIsFull(pq))
	{
		printf("Queue is full. Cannot enqueue\n");
		return false;
	}
	// 새로운 노드 동적할당
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
		return false;

	// 데이터 연결
	new_node->item = item;
	new_node->next = NULL;

	// 큐가 비여있다면
	if (QueueIsEmpty(pq))
		pq->front = new_node;
	else
		pq->rear->next = new_node;		// 마지막 노드 뒤에 새로운 노드 연결
	pq->rear = new_node;				// 새로만들어진 노드(마지막 노드)을 rear로 지정
	pq->n_items++;

	return true;
}


bool DeQueue(Item* pitem, Queue* pq)
{
	// 큐 비여있는지 확인
	if (QueueIsEmpty(pq))
	{
		printf("Queue is empty.Cannot dequeue.\n");
		return false;
	}

	*pitem = pq->front->item;		// 제거할 데이터 담아두기
	Node* tmp = pq->front;			// 제거할 노드 tmp노드포인터에 담기
	pq->front = pq->front->next;	// front노드 next노드에 연결
	free(tmp);						// 노드 제거
	pq->n_items--;
	if (pq->n_items == 0)
		pq->rear = NULL;

	return true;
}

void EmptyTheQueue(Queue* pq)
{
	Item temp;
	while (!QueueIsEmpty(pq))
		DeQueue(&temp, pq);
}


void TraverseQueue(Queue* pq, void(*func)(Item item))
{
	Node* search;

	for (search = pq->front; search != NULL; search = search->next)
	{
		(*func)(search->item);
	}
}
