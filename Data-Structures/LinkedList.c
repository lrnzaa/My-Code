#include <stdio.h>
#include <stdlib.h>

struct data{
	int key;
	struct data *next;
}*head, *tail, *curr;

void pushDepan(insertKey)
{
	curr = (struct data *)malloc(sizeof(struct data));
	curr->key = insertKey;
	curr->next = NULL;
	
	if(head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		curr->next = head;
		head = curr;
	}
	tail->next = NULL;
}

void view()
{
	if(head == NULL)
	{
		printf("There is no data!!\n");
	}
	else
	{
		curr = head;
		while(curr != NULL)
		{
			printf("Nilai %d\n", curr->key);
			curr = curr->next;
		}
	}
}

void popAll()
{
	curr = head;
	while(curr != NULL)
	{
		head = head->next;
		free(curr);
		curr = head;
	}
	head = tail = NULL;
}

void popDepan()
{
	if(head == NULL)
	{
	}
	else
	{
		curr = head;
		head = head->next;
		free(curr);
	}
}

int main ()
{
	int insertKey;
	
	printf("Masukkan key = ");
	scanf("%d", &insertKey);
	fflush(stdin);
	
	pushDepan(insertKey);
	pushDepan(5);
	pushDepan(10);
	pushDepan(12);
	pushDepan(13);
	
	view();
	popAll();
	
	printf("%d\n", tail->key);
	
	return 0;
}
