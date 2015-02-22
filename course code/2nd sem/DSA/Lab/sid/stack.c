#include <stdio.h>
#include <stdlib.h>

struct linked_list {
	int num;
	struct linked_list *next;
};

typedef struct linked_list stack;

int size(stack *);
int top(stack *);
int is_empty(stack *);
void push(stack **, int);
void pop(stack **);
void print(stack *);

int main()
{
	stack *head;
	int n;
	int x;
	int i;

	head = (stack *)malloc(sizeof(stack));
	head -> next = NULL;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		push(&head, x);
	}
	print(head);
start:
	printf("Enter your Choice\n1. size\n2. top\n3. is_empty\n4. push\n5. pop\n6. Finish\n");
	scanf("%d", &n);

	if (n == 1) 
		printf("Size = %d\n", size(head));
	else if (n == 2)
		printf("Top = %d\n", top(head));
	else if (n == 3) {
		if (is_empty(head))
			printf("Empty\n");
		else
			printf("Not Empty\n");
	}
	else if (n == 4) {
		scanf("%d", &x);
		push(&head, x);
		print(head);
	}
	else if (n == 5) {
		printf("%d popped\n", top(head));
		pop(&head);
		print(head);
	}

	if (n > 0 && n < 6)
		goto start;

	return 0;
}

int size(stack *lst)
{
	int i;

	i = 0;
	while (lst != NULL) {
		lst = lst -> next;
		i++;
	}

	return i;
}

int top(stack *lst)
{
	return lst -> num;
}

int is_empty(stack *lst)
{
	if (lst -> num == 0)
		return 1;
	else
		return 0;
}

void push(stack **lst, int x)
{
	stack *tmp;
	tmp = (stack *)malloc(sizeof(stack));
	tmp -> num = x;
	tmp -> next = *lst;
	*lst = tmp;
}

void pop(stack **lst)
{
	*lst = (*lst) -> next;
}

void print(stack *lst)
{
	printf("Stack:\n");
	while (lst -> next != NULL) {
		printf("%d\n", lst -> num);
		lst = lst -> next;
	}
}
