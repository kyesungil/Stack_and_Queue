#pragma once

/*
	Ring_Queue(FIFO)

	��Ŀ(��ġ ǥ��)
	* tail�� ����ĭ�� ����Ǿ���� ��ġ
	* head�� ���� ù��° ������ ��ġ


	Enqueue(��ť)����
	 - ť�� tail�� ������ ����
	 
	Dequeue(��ť)����
	 - ť�� head���� �����͸� retrieval
	 


	�Լ� ����
		FullȮ��
		- (Tail+1) % QSIZE == Head �̸� Full
		- QSIZE(Queue����)�� 4��� �Ҷ�, ���� ��� enqueue(data�� ������)�ϸ�
		  Empty�� ������ ���� �ʱ� ������ �ε����ϰ� �� ������ ������� �ʴ´�.

		EmptyȮ��
		- Head�� Tail�� ������ Empty

		Enqueue
		1. Full���� Ȯ��
		2. Tail index�� ������ ����
		3. Tail = Tail + 1 (Tail = (Tail+1) % QSZIE) QSIZE ���� ����

		Dequeue
		1. Empty���� Ȯ��
		2. Head index���� ������ retrieval
		3. Head = Head + 1 (Head = (Head+1) % QSIZE)
		
*/

#include <stdio.h>
#include <stdbool.h>


#define QSIZE 4
#define LEN 20


/* �л� ������ */
typedef struct student_
{
	char st_name[LEN];

}student;


/* Queue */
typedef struct Queue_
{
	int head;
	int tail;
	int item_size; // ������ ����
	student st_data[QSIZE];

}Queue;


/* Queue �ʱ�ȭ */
void init(Queue* q)
{
	q->head = 0;
	q->tail = 0;
	q->item_size = 0;
}

/* queue ����ִ��� Ȯ�� */
bool IsEmpty(Queue* q)
{
	return q->head == q->tail;
}


/* queue ���ִ��� Ȯ�� */
bool IsFull(Queue* q)
{
	return q->head == (q->tail + 1) % QSIZE;
}


/* Enqueue */
bool Enqueue(Queue* q, student st_data)
{
	if (IsFull(q))
	{
		printf("Queue is Full\n");
		return false;
	}
	else
	{
		// ���� tail index�� data �־��ְ�, tail + 1 
		q->st_data[q->tail] = st_data; 
		q->tail = (q->tail + 1) % QSIZE; // QSIZE ���� ���ϰ� �ϱ����ؼ� % �̿�

		q->item_size++;
		return true;
	}
}


/* Dequeue */
bool Dequeue(Queue* q, student* st_data)
{
	if (IsEmpty(q))
	{
		printf("Queue is Empty\n");
		return false;
	}
	else
	{
		// ���� head index�� st_data ����, head + 1
		*st_data = q->st_data[q->head];
		q->head = (q->head + 1) % QSIZE;

		q->item_size--;
		return true;
	}
}


/* Queue�� ���data��� */
void Queue_traverse(Queue* q, void(*func)(student data))
{
	for (int i = q->head; i != q->tail; i = (i + 1) % QSIZE)
	{
		(*func)(q->st_data[i]);
	}
}