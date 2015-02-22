#include <stdio.h>
#include <stdlib.h>

struct link {
	int x;
	struct link *next;
};

typedef struct link node;

void create(node *p);
void print_all_node(node *p);
node* new_head(node *p, int a);
void find_node(node *p, int a);
int total_node(node *p);
node* delete_node(node *p, int a);


int main()
{
	node *head;
	int n;
	int f;
	int s;
	int d;
	int c;
	c = 0;

	head = (node*) (malloc(sizeof(node)));
	create(head);

	while (c != 6) {
		printf("\n1-print all node\n2-add new head\n");
		printf("3-find a node\n4-delete a node\n5-count all node\n6-exit\n\nEnter your choice\n");
		scanf("%d", &c);

		if (c == 1) {
			printf("\n\nYou have entered\n");
			print_all_node(head);	
		}else if (c == 2) {
			printf("\n\nEnter number\n");
			scanf("%d", &n);
			head = new_head(head, n);
		}else if (c == 3) {
			printf("\n\nEnter number to be find\n");
			scanf("%d", &f);
			find_node(head, f);
		}else if (c == 5) {
			s = total_node(head);
			printf("\n\nTotal number of node = %d\n", s);
		}else if (c == 4) {
			printf("\n\nEnter Number to be delete\n");
			scanf("%d", &d);
			head = delete_node(head, d);
		}else if (c != 6) {
			printf("\n\n****INVALID CHOICE****\n\n");
		}
	}	
	return 0;
	
}

void create(node *p)
{
	int var;
	
	printf("enter number\n");
	scanf("%d", &(p -> x));
	while (1) {
		printf("press 1 to continue entering\n");
		scanf("%d", &var);
		if ( var == 1) {
			p -> next = (node*) (malloc(sizeof(node)));
	                p = p -> next;
			printf("enter number\n");
			scanf("%d", &(p -> x));
		}
		else {
			p -> next  = NULL;
			break;
		}	
	}
}

void print_all_node(node *p)
{
	while(p != NULL) {
		printf("%d\n", p -> x);
		p = p -> next;
	}
}

node* new_head(node *p, int a)
{
	node *q;
	q = (node*) (malloc(sizeof(node)));
	
	q -> x = a;
	q -> next = p;
	p = q;
	return (p);
}

void find_node(node *p, int a)
{
	if ((p -> x) == a) {
		printf("Node found\n");
		return ;
	}
	else {
		 if ((p -> next) != NULL) {
			find_node( p -> next, a);
		} else {
			printf("Node not found\n");;
		}
	}
}
		
int total_node(node *p)
{
	if ( p != NULL) {
		return(1 + total_node(p -> next));
	}
	
	return 0;
}

node* delete_node(node *p, int a)
{
	
	node *q;
	node *tmp;
	tmp = p;

	if (p -> x == a) {
		q = p->next;
		free(p);
		tmp=q;
		p = tmp;
	} else {
		while (p -> next -> x != a) {
        		 p = p -> next;
		}
		q = p -> next;
		p -> next = p -> next -> next;
		free(q);
	}
	p = p -> next;
	
	
	return (tmp);
}
	 
