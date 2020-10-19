#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* ��� ���� */
typedef struct tagNode
{
	char* data;
	struct tagNode* Next;
}Node;

/* ť ���� */
typedef struct tagLinkedQueue_
{
	int count; // ��� ��
	Node* front;
	Node* rear;
} LQ;

/* LinkedQueue �������̽� �Լ� */

/* ��ũ�� ť ���� */
void LQ_CreateLinkedQueue(LQ** lq);

/* Node ���� */
Node* CreateNode(char* data);

/* Node ���� */
void DestroyNode(Node* node);

bool Enqueue(LQ* lq, char* data);

bool dequeue(LQ* lq);

bool IsEmpty(LQ* lq);

int getItem(LQ* lq);