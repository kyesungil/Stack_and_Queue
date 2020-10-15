#include "ArrayStack.h"

// stack �ʱ�ȭ �Լ�
void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	/* ������ ���� ����ҿ� ���� */
	*Stack = malloc(sizeof(Stack));

	/* �Էµ� Capcity��ŭ�� ��带 ���� ����ҿ� ����*/
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	(*Stack)->capacity = Capacity;
	(*Stack)->top = -1;
}



// stack ���� �Ҹ��Լ�
void AS_DestroyStack(ArrayStack* Stack)
{
	free(Stack->Nodes);
	free(Stack);
}

// stack push �Լ�
void AS_Push(ArrayStack* Stack, ElementType Input_Data)
{
	// full ���� Ȯ��
	if ((AS_GetSize(Stack) + 1) == (Stack->capacity))
	{
		printf("Stack is Full!\n");
		return;
	}

	// Top++, Node�� ElementType data �ֱ�
	Stack->Nodes[++(Stack->top)].Data = Input_Data;
}

// stack pop �Լ� ��������� return 0;
ElementType AS_Pop(ArrayStack* Stack)
{
	// ����ִ��� Ȯ��
	if (AS_IsEmpty(Stack))
	{
		printf("The Stack is Empty!\n");
		return 0;
	}
	return Stack->Nodes[(Stack->top)--].Data;
}

// stack top data ��ȯ �Լ�
ElementType AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[Stack->top].Data;
}

// stack empty���� Ȯ���ϴ� �Լ�
bool AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->top == -1) ? true : false;
}

// stack size ��ȯ
int AS_GetSize(ArrayStack* Stack)
{
	return Stack->top;
}