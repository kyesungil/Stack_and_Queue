#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* 노드 구조 */
typedef struct tagNode
{
	char* data;
	struct tagNode* Next;
}Node;

/* 큐 구조 */
typedef struct tagLinkedQueue_
{
	int count; // 노드 수
	Node* front;
	Node* rear;
} LQ;

/* LinkedQueue 인터페이스 함수 */

/* 링크드 큐 생성 */
void LQ_CreateLinkedQueue(LQ** lq);

/* Node 생성 */
Node* CreateNode(char* data);

/* Node 제거 */
void DestroyNode(Node* node);

bool Enqueue(LQ* lq, char* data);

bool dequeue(LQ* lq);

bool IsEmpty(LQ* lq);

int getItem(LQ* lq);