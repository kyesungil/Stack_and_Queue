#include "LinkedQueue.h"


/* ��ũ�� ť ���� */
void LQ_CreateLinkedQueue(LQ** lq)
{
	(*lq) = (LQ*)malloc(sizeof(LQ));
	if ((*lq) == NULL)
		exit(0);

	(*lq)->front = NULL;
	(*lq)->rear = NULL;
	(*lq)->count = 0;
}

/* Node ���� */
Node* CreateNode(char* data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("Allocate error\n");
		return NULL;
	}
	new_node->data = (char*)malloc(strlen(data) + 1);	// ���ڿ� ������ NULL

	strcpy(new_node->data, data);
	new_node->Next = NULL;

	return new_node;
}

/* Node ���� */
void DestroyNode(Node* node)
{
	free(node->data);
	free(node);
}

bool Enqueue(LQ* lq, char* data)
{
	// create node
	Node* new_node = CreateNode(data);
	if (new_node == NULL)
		return false;


	// ù ��� ���
	if (lq->front == NULL)
	{
		lq->front = new_node;
		lq->rear = new_node;
		lq->count++;
	}
	// ù ��尡 �ƴ� ���
	else
	{
		lq->rear->Next = new_node;
		lq->rear = new_node;
		lq->count++;
	}

	return true;
}

bool dequeue(LQ* lq)
{
	// data ��� �ִ��� Ȯ��
	if (IsEmpty(lq))
	{
		printf("No Data\n");
		return false;
	}

	Node* tempNode = lq->front;
	printf("%s\n", lq->front->data);

	if (lq->front->Next == NULL)
	{
		lq->front = NULL;
		lq->rear = NULL;
	}
	else
	{
		// ��� front �κ�
		lq->front = lq->front->Next;
	}
	// ��� destroy
	DestroyNode(tempNode);
	lq->count--;
	return true;
}

bool IsEmpty(LQ* lq)
{
	return (lq->front == NULL);
}

int getItem(LQ* lq)
{
	return lq->count;
}