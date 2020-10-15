#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ������ Ÿ�� ���ϱ�
typedef int ElementType;

// Node �����
typedef struct tagNode
{
	ElementType Data;
} Node;

// Stack struct �����(�뷮, top, ���)
typedef struct Stack
{
	int capacity;
	int top;
	Node* Nodes;
	
} ArrayStack;

// stack �ʱ�ȭ �Լ�
void AS_CreateStack(ArrayStack** Stack, int Capacity);
// stack ���� �Ҹ��Լ�
void AS_DestroyStack(ArrayStack* Stack);
// stack push �Լ�
void AS_Push(ArrayStack* Stack, ElementType Input_Data);
// stack pop �Լ�
ElementType AS_Pop(ArrayStack* Stack);

// stack full ���� Ȯ���ϴ� �Լ�
ElementType AS_Top(ArrayStack* Stack);
// stack empty���� Ȯ���ϴ� �Լ�
bool AS_IsEmpty(ArrayStack* Stack);

int AS_GetSize(ArrayStack* Stack);
