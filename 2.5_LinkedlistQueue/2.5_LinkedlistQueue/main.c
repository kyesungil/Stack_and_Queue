#include "LinkedQueue.h"

int main()
{
	LQ* queue;
	
	LQ_CreateLinkedQueue(&queue);

	Enqueue(queue, "Happy");
	Enqueue(queue, "Good");
	Enqueue(queue, "Interesting");

	printf("N_TIEM: %d\n", getItem(queue));

	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);

	printf("N_TIEM: %d\n", getItem(queue));

	return 0;
}