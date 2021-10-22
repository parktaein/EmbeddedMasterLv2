#include <stdio.h>
#include <stdlib.h>

typedef struct _stack stack;
struct _stack
{
	int data;
	struct _stack *link;
};

stack *create_stack_node(void)
{
	stack *tmp;

	tmp = (stack *)malloc(sizeof(stack));
	tmp->link = NULL;

	return tmp;
}

void push_data(stack **top, int data)
{
	stack *tmp = *top; //현재 stack의 최상위 위치 임시 저장 

	*top = create_stack_node(); //새로 생성된 stack의 주소 
	(*top)->data = data;
	(*top)->link = tmp;
}

int pop_data(stack **top)
{
	int data;
	stack *tmp;

	if(!(*top))
	{
		printf("Stack is empty\n");
		return -1;
	}

	tmp = *top; //현재 stack의 최상위 위치 임시 저장

	data = tmp->data;
	*top = tmp->link;

	free(tmp);

	return data;
}

void print_stack_data(stack *top)
{
	while(top)
	{
		printf("data = %d\n", top->data);
		top = top->link;
	}
	printf("\n");
}

int main(void)
{
	stack *top = NULL;
	int data[] = { 10, 20, 30, 40, 50, 60, 70 };
	int i;

	for (i = 0; i < 7; i++)
	{
		push_data(&top, data[i]);
	}

	print_stack_data(top);

	for (i = 0; i < 8; i++)
	{
		printf("pop = %d\n", pop_data(&top));
		print_stack_data(top);
	}

	return 0;
}

