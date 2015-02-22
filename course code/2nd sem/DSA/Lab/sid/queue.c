#include <stdio.h>
#include <stdlib.h>

struct linked_list {
	int num;
	struct linked_list *next;
};

typedef struct linked_list queue;

int size(queue *);
int top(queue *);
int is_empty(queue *);
void enqueue(queue *, int);
void dequeue(queue **);
void print(queue *);

int main()
{
	queue *head;
	int n;
	int x;
	int i;

	head = (queue *)malloc(sizeof(queue));
	head -> next = NULL;

	scanf("%d", &n);
	scanf("%d", &x);
	head -> num = x;
	for (i = 0; i < n - 1; i++) {
		scanf("%d", &x);
		enqueue(head, x);
	}
	print(head);
start:
	printf("Enter your Choice\n1. size\n2. top\n3. is_empty\n4. enqueue\n5. dequeue\n6. Finish\n");
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
		enqueue(head, x);
		print(head);
	}
	else if (n == 5) {
		printf("%d dequeued\n", top(head));
		dequeue(&head);
		print(head);
	}

	if (n > 0 && n < 6)
		goto start;

	return 0;
}

int size(queue *lst)
{
	int i;

	i = 0;
	while (lst != NULL) {
		lst = lst -> next;
		i++;
	}

	return i;
}

int top(queue *lst)
{
	return lst -> num;
}

int is_empty(queue *lst)
{
	if (lst == NULL)
		return 1;
	else
		return 0;
}

void enqueue(queue *lst, int x)
{
	if (lst == NULL) {
		lst -> num = x;
		lst -> next = NULL;
	}
	else {
		queue *tmp;
		tmp = (queue *)malloc(sizeof(queue));
		tmp -> num = x;
		tmp -> next = NULL;
		while (lst -> next != NULL) {
			lst = lst -> next;
		}
		lst -> next = tmp;
	}
}

void dequeue(queue **lst)
{
	(*lst) = (*lst) -> next;
}

void print(queue *lst)
{
	printf("Queue:\n");
	while (lst != NULL) {
		printf("%d ", lst -> num);
		lst = lst -> next;
	}
	printf("\n");
}
