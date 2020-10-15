#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 데이터 타입 정하기
typedef int ElementType;

// Node 만들기
typedef struct tagNode
{
	ElementType Data;
} Node;

// Stack struct 만들기(용량, top, 노드)
typedef struct Stack
{
	int capacity;
	int top;
	Node* Nodes;
	
} ArrayStack;

// stack 초기화 함수
void AS_CreateStack(ArrayStack** Stack, int Capacity);
// stack 종료 소멸함수
void AS_DestroyStack(ArrayStack* Stack);
// stack push 함수
void AS_Push(ArrayStack* Stack, ElementType Input_Data);
// stack pop 함수
ElementType AS_Pop(ArrayStack* Stack);
// stack top 반환 함수
ElementType AS_Top(ArrayStack* Stack);
// stack empty인지 확인하는 함수
bool AS_IsEmpty(ArrayStack* Stack);
// stack node 개수 반환 함수
int AS_GetSize(ArrayStack* Stack);
