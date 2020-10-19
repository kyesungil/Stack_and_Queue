#include "CircularQueue.h"


int main()
{
	CQ* queue = NULL;
	CQ_CreateQueue(&queue, QSIZE);

	for (int i = 0; i < QSIZE; i++)
	{
		CQ_Enqueue(queue, i);
	}

	printf("n_items:%d\n", getItem(queue));

	for (int i = 0; i < QSIZE; i++)
	{
		printf("[%d]", i);
		CQ_Dequeue(queue);
	}

	printf("n_items:%d\n", getItem(queue));

	return 0;
}