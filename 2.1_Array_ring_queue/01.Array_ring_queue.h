#pragma once

/*
	Ring_Queue(FIFO)

	마커(위치 표시)
	* tail은 다음칸에 저장되어야할 위치
	* head는 현재 첫번째 데이터 위치


	Enqueue(인큐)동작
	 - 큐의 tail에 데이터 저장
	 
	Dequeue(디큐)동작
	 - 큐의 head에서 데이터를 retrieval
	 


	함수 구현
		Full확인
		- (Tail+1) % QSIZE == Head 이면 Full
		- QSIZE(Queue공간)이 4라고 할때, 공간 모두 enqueue(data를 넣으면)하면
		  Empty와 구별이 되지 않기 때문에 부득이하게 한 공간은 사용하지 않는다.

		Empty확인
		- Head와 Tail이 같으면 Empty

		Enqueue
		1. Full인지 확인
		2. Tail index에 데이터 저장
		3. Tail = Tail + 1 (Tail = (Tail+1) % QSZIE) QSIZE 오버 방지

		Dequeue
		1. Empty인지 확인
		2. Head index에서 데이터 retrieval
		3. Head = Head + 1 (Head = (Head+1) % QSIZE)
		
*/

#include <stdio.h>
#include <stdbool.h>


#define QSIZE 4
#define LEN 20


/* 학생 데이터 */
typedef struct student_
{
	char st_name[LEN];

}student;


/* Queue */
typedef struct Queue_
{
	int head;
	int tail;
	int item_size; // 아이템 개수
	student st_data[QSIZE];

}Queue;


/* Queue 초기화 */
void init(Queue* q)
{
	q->head = 0;
	q->tail = 0;
	q->item_size = 0;
}

/* queue 비어있는지 확인 */
bool IsEmpty(Queue* q)
{
	return q->head == q->tail;
}


/* queue 차있는지 확인 */
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
		// 현재 tail index에 data 넣어주고, tail + 1 
		q->st_data[q->tail] = st_data; 
		q->tail = (q->tail + 1) % QSIZE; // QSIZE 넘지 못하게 하기위해서 % 이용

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
		// 현재 head index에 st_data 뻬고, head + 1
		*st_data = q->st_data[q->head];
		q->head = (q->head + 1) % QSIZE;

		q->item_size--;
		return true;
	}
}


/* Queue에 모든data출력 */
void Queue_traverse(Queue* q, void(*func)(student data))
{
	for (int i = q->head; i != q->tail; i = (i + 1) % QSIZE)
	{
		(*func)(q->st_data[i]);
	}
}