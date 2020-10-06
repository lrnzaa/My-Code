#include <stdio.h>
#include <stdlib.h>

struct data{
	int key;
	struct data *next, *prev;
}*head, *tail, *curr;

void push(int insertedKey)
{
	curr = (struct data *)malloc(sizeof(struct data));
	curr->key = insertedKey;
	curr->next = curr->prev = NULL;
	
	//push depam
	if(head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		tail->next = curr;
		curr->prev = tail;
		tail = tail->next;
	}
	
	head->prev = tail;
	tail->next = head;
}

void view()
{
	curr = head;
	
	if(head == NULL)
	{
		printf("There is no data.\n");
	}
	else
	{
		while(curr != NULL)
		{
			printf("%d", curr->key);
			curr = curr->next;
			
			if(curr != head)
				printf(" => ");
			else
			{
				printf("\n");
				break;
			}
		}
	}
}

void pop()
{
	//pop belakang
	
	if(head == NULL)
	{
	}
	else
	{
		curr = tail;
		tail = tail->prev;
		//curr->next = curr->prev = NULL;
		free(curr);
		tail->next = head;
	}
}

void popAll()
{
	curr = head;
	while(curr != NULL)
	{
		head = head->next;
		curr->next = curr->prev = NULL;
		free(curr);
		curr = head;
	}
	head = tail = NULL;
}

int main()
{
	push(5);
	push(15);
	push(25);
	push(35);
	view();
	
	return 0;
}
