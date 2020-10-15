#include "ArrayStack.h"

// stack 초기화 함수
void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	/* 스택을 자유 저장소에 생성 */
	*Stack = malloc(sizeof(Stack));

	/* 입력된 Capcity만큼의 노드를 자유 저장소에 생성*/
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	(*Stack)->capacity = Capacity;
	(*Stack)->top = -1;
}



// stack 종료 소멸함수
void AS_DestroyStack(ArrayStack* Stack)
{
	free(Stack->Nodes);
	free(Stack);
}

// stack push 함수
void AS_Push(ArrayStack* Stack, ElementType Input_Data)
{
	// full 인지 확인
	if ((AS_GetSize(Stack) + 1) == (Stack->capacity))
	{
		printf("Stack is Full!\n");
		return;
	}

	// Top++, Node에 ElementType data 넣기
	Stack->Nodes[++(Stack->top)].Data = Input_Data;
}

// stack pop 함수 비어있으면 return 0;
ElementType AS_Pop(ArrayStack* Stack)
{
	// 비어있는지 확인
	if (AS_IsEmpty(Stack))
	{
		printf("The Stack is Empty!\n");
		return 0;
	}
	return Stack->Nodes[(Stack->top)--].Data;
}

// stack top data 반환 함수
ElementType AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[Stack->top].Data;
}

// stack empty인지 확인하는 함수
bool AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->top == -1) ? true : false;
}

// stack size 반환
int AS_GetSize(ArrayStack* Stack)
{
	return Stack->top;
}