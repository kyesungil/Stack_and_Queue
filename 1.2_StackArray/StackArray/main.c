#include "ArrayStack.h"

int main()
{
	int i = 0;
	const int stack_size = 5;

	ArrayStack* stack = NULL;

	AS_CreateStack(&stack, stack_size);

	for (; i < stack_size; i++)
	{
		AS_Push(stack, i);
		printf("top: %d\n", AS_Top(stack));
	}

	AS_Push(stack, 100);
	AS_Push(stack, 200);

	printf("Capacity: %d, Size: %d, Top:%d\n\n",
		stack->capacity, AS_GetSize(stack), AS_Top(stack));


	printf("Pop: %d\n", AS_Pop(stack));
	printf("Pop: %d\n", AS_Pop(stack));
	printf("Pop: %d\n", AS_Pop(stack));
	printf("Pop: %d\n", AS_Pop(stack));
	printf("Pop: %d\n", AS_Pop(stack));
	
	
	return 0;
}