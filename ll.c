#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	char* s;
	struct Node* next;
} Node;

typedef struct list_t {
	Node* head;
} List;

void insert(List* l, char* s)
{
	Node* n = l->head;
	Node* nn = (Node*)malloc(sizeof(Node));
	nn->s = s;
	nn->next = NULL;

	if(n == NULL)
	{
		l->head = nn;
		return;
	}
	while(n-> next != NULL)
	{
		n = n->next;
	}
	n->next = nn;
	return;
}

void print_list(List* l)
{
	Node* n = l->head;
	while(n!= NULL)
	{
		printf("%s\n", n->s);
		n = n->next;
	}
	return;
}

int compare_node(Node* n1, Node* n2)
{
	if(n1 == NULL && n2 == NULL) { return 0; }
	if(n1 == NULL) { return -1; }
	if(n2 == NULL) { return 1; }
	return strcmp(n1->s,n2->s);
}

void append(List* l, Node* s)
{
	Node* n = l->head;
	if(n == NULL)
	{
		l->head = s;
		s->next = NULL;
		return;
	}
	while(n->next != NULL)
	{
		n = n->next;
	}
	n->next = s;
	s->next = NULL;
	return;
}

void sort_list(List* l)
{
	Node* n = l->head;
	if(n->next == NULL)
	{
		return;
	}
	List results = {.head = NULL};
	Node* lowest_parent = NULL;
	Node* temp;
	while(n != NULL)
	{
		lowest_parent = n;
		Node* m = n;
		while(m->next != NULL)
		{
			if(compare_node(lowest_parent->next, m->next) > 0)
			{
				lowest_parent = m;
			}
			m = m->next;
		}
		if(lowest_parent != n)
		{
			temp = lowest_parent->next;
			lowest_parent->next = lowest_parent->next->next;
			append(&results, temp);
		}
		else
		{
			if(n->next == NULL)
			{
				append(&results, n);
				n = NULL;
				continue;
			}
			if(compare_node(n, n->next) > 0)
			{
				temp = n->next;
				n->next = n->next->next;
				append(&results, temp);
			}
			else
			{
				n = n->next;
				append(&results, lowest_parent);
			}
		}
	}
	l->head = results.head;
	return;
}


int main()
{
	List* l = (List*)malloc(sizeof(List));
	insert(l, "d");
	insert(l, "c");
	insert(l, "a");
	insert(l, "b");
	insert(l, "e");
	insert(l, "f");
	print_list(l);
	sort_list(l);
	printf("====\n");
	print_list(l);
}
