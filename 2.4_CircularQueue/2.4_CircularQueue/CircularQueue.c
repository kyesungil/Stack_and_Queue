#include "CircularQueue.h"

/* 순환 큐 생성 */
void CQ_CreateQueue(CQ** queue, int Capacity)
{
	/* 큐를 자유 저장소에 생성*/
	(*queue) = (CQ*)malloc(sizeof(CQ));
	if (*queue == NULL)
		exit(0);

	/* 큐 배열 자유 저장소에 생성*/
	(*queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));
	if ((*queue)->Nodes == NULL)
	{
		printf("Allocate Error\n");
		return;
	}

	(*queue)->Capacity = Capacity;
	(*queue)->Front = 0;
	(*queue)->Rear = 0;
	(*queue)->n_items = 0;
}


/* 순환 큐 제거 */
void CQ_DestroyQueue(CQ* queue)
{
	/* 노드 배열 제거 */
	free(queue->Nodes);

	/* 큐 제거*/
	free(queue);
}

/* 노드 삽입 Enqueue */
bool CQ_Enqueue(CQ* queue, ElementType data)
{
	// queue full 인지 확인
	if (CQ_IsFull(queue))
	{
		printf("CQ_IsFull!\n");
		return false;
	}

	queue->Nodes[queue->Rear].Data = data;
	queue->Rear = (queue->Rear + 1) % (QSIZE+1);
	queue->n_items++;
	return true;
}

bool CQ_Dequeue(CQ* queue)
{
	if (CQ_IsEmpty(queue))
	{
		printf("CQ_IsEmpty\n");
		return false;
	}

	printf("Dequeue: %d\n", queue->Nodes[queue->Front].Data);
	queue->Front = (queue->Front + 1) % (QSIZE+1);
	queue->n_items--;
	return true;
}

bool CQ_IsFull(CQ* queue)
{
	return queue->Front == ((queue->Rear + 1) % (QSIZE+1));
}

bool CQ_IsEmpty(CQ* queue)
{
	return queue->Front == queue->Rear;
}

int getItem(CQ* queue)
{
	return queue->n_items;
}