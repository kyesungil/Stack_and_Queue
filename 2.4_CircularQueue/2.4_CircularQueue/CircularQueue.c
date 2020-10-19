#include "CircularQueue.h"

/* ��ȯ ť ���� */
void CQ_CreateQueue(CQ** queue, int Capacity)
{
	/* ť�� ���� ����ҿ� ����*/
	(*queue) = (CQ*)malloc(sizeof(CQ));
	if (*queue == NULL)
		exit(0);

	/* ť �迭 ���� ����ҿ� ����*/
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


/* ��ȯ ť ���� */
void CQ_DestroyQueue(CQ* queue)
{
	/* ��� �迭 ���� */
	free(queue->Nodes);

	/* ť ����*/
	free(queue);
}

/* ��� ���� Enqueue */
bool CQ_Enqueue(CQ* queue, ElementType data)
{
	// queue full ���� Ȯ��
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