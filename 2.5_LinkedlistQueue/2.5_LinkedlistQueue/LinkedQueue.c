#include "LinkedQueue.h"


/* 링크드 큐 생성 */
void LQ_CreateLinkedQueue(LQ** lq)
{
	(*lq) = (LQ*)malloc(sizeof(LQ));
	if ((*lq) == NULL)
		exit(0);

	(*lq)->front = NULL;
	(*lq)->rear = NULL;
	(*lq)->count = 0;
}

/* Node 생성 */
Node* CreateNode(char* data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("Allocate error\n");
		return NULL;
	}
	new_node->data = (char*)malloc(strlen(data) + 1);	// 문자열 마지막 NULL

	strcpy(new_node->data, data);
	new_node->Next = NULL;

	return new_node;
}

/* Node 제거 */
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


	// 첫 노드 경우
	if (lq->front == NULL)
	{
		lq->front = new_node;
		lq->rear = new_node;
		lq->count++;
	}
	// 첫 노드가 아닐 경우
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
	// data 비어 있는지 확인
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
		// 노드 front 부분
		lq->front = lq->front->Next;
	}
	// 노드 destroy
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