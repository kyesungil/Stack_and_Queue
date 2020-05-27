#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Array_ring_queue.h"
#include <string.h>

student get_Item(char* name)
{
	student mitem;
	strcpy(mitem.st_name, name);
	return mitem;
}

void print_item(student item)
{
	printf("%s ", item.st_name);
}

void print_queue(Queue* q)
{
	printf("head:%d, tail: %d, Size: %d\n", q->head, q->tail, q->item_size);

	printf("Queue: ");
	if (IsEmpty(q))
		printf("Empty");
	else
		Queue_traverse(q, &print_item);
	printf("\n\n");
}

int main()
{
	Queue queue;
	student temp;

	init(&queue);

	Enqueue(&queue, get_Item("Jack"));
	print_queue(&queue);

	Enqueue(&queue, get_Item("Henry"));
	print_queue(&queue);

	Enqueue(&queue, get_Item("Stan"));
	print_queue(&queue);

	Enqueue(&queue, get_Item("Butters"));
	print_queue(&queue);

	if (Dequeue(&queue, &temp))
		printf("Item from queue: %s\n", temp.st_name);
	print_queue(&queue);

	if (Dequeue(&queue, &temp))
		printf("Item from queue: %s\n", temp.st_name);
	print_queue(&queue);

	if (Dequeue(&queue, &temp))
		printf("Item from queue: %s\n", temp.st_name);
	print_queue(&queue);

	if (Dequeue(&queue, &temp))
		printf("Item from queue: %s\n", temp.st_name);
	print_queue(&queue);

	Enqueue(&queue, get_Item("Butters"));
	print_queue(&queue);


	return 0;
}