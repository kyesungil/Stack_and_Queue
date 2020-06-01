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
	// ���ο� ��� �����Ҵ�
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
		return false;

	// ������ ����
	new_node->item = item;
	new_node->next = NULL;

	// ť�� ���ִٸ�
	if (QueueIsEmpty(pq))
		pq->front = new_node;
	else
		pq->rear->next = new_node;		// ������ ��� �ڿ� ���ο� ��� ����
	pq->rear = new_node;				// ���θ������ ���(������ ���)�� rear�� ����
	pq->n_items++;

	return true;
}


bool DeQueue(Item* pitem, Queue* pq)
{
	// ť ���ִ��� Ȯ��
	if (QueueIsEmpty(pq))
	{
		printf("Queue is empty.Cannot dequeue.\n");
		return false;
	}

	*pitem = pq->front->item;		// ������ ������ ��Ƶα�
	Node* tmp = pq->front;			// ������ ��� tmp��������Ϳ� ���
	pq->front = pq->front->next;	// front��� next��忡 ����
	free(tmp);						// ��� ����
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
