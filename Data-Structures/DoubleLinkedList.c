#include <stdio.h>
#include <stdlib.h>

struct data{
	int key;
	struct data *next, *prev;
}*head, *tail, *curr;

void pushBelakang(int insertKey)
{
	curr = (struct data *)malloc(sizeof(struct data));
	curr->key = insertKey;
	curr->next = curr->prev = NULL;
	
	if(head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		//1. selamatkan linknya (keduanya)
		curr->prev = tail;
		tail->next = curr;
		//2. perbaiki linked listnya
		tail = curr;
	}
	tail->next = head->prev = NULL;
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
		if(head == NULL)
			head = tail = NULL;
		else
			head->prev = NULL;
	}
}

void pushDepan(int insertKey)
{
	curr = (struct data *)malloc(sizeof(struct data));
	curr->key = insertKey;
	curr->next = curr->prev = NULL;
	
	if(head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		head->prev = curr;
		curr->next = head;
		head = curr;
	}
	head->prev = tail->next = NULL;
}

void popBelakang()
{
	if(head == NULL)
	{
	}
	else
	{
		curr = tail;
		tail = tail->prev;
		free(curr);
		
		if(tail == NULL)
			head = tail = NULL;
		else
			tail->next = NULL;
	}	
}

void priority(int insertKey)
{
	curr = (struct data *)malloc(sizeof(struct data));
	curr->key = insertKey;
	curr->next = curr->prev = NULL;
	
	if(head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		if(insertKey <= head->key)
		{
			//pushdepan
			head->prev = curr;
			curr->next = head;
			head = curr;
		}
		else if(insertKey >= tail->key)
		{
			//pushbelakang
			tail->next = curr;
			curr->prev = tail;
			tail = curr;
		}
		else
		{
			//pushtengah
			struct data *temp = head;
			while(temp->next != NULL && temp->next->key < insertKey)			
			{
				temp = temp->next;
			}
			//1. selamatkan linknya
			curr->next = temp->next;
			curr->prev = temp;
			temp->next = curr;
			curr->next->prev = curr;
		}
	}
	head->prev = tail->next = NULL;
}

void popSearching(int deleteKey)
{
	if(head == NULL)
	{
	}
	else
	{
		if(head->key == deleteKey)
		{
			//popdepan
			curr = head;
			head = head->next;
			free(curr);
			if(head == NULL)
				head = tail = NULL;
			else
				head->prev = NULL;
		}
		else if(tail->key == deleteKey)
		{
			//popbelakang
			curr = tail;
			tail = tail->prev;
			free(curr);
			if(tail == NULL)
				head = tail = NULL;
			else
				tail->next = NULL;
		}
		else
		{
			curr = head;
			while(curr != NULL && curr->key != deleteKey)
			{
				curr = curr->next;
			}
			if(curr = NULL)
			{
				printf("Angka yang dicari tidak ditemukan!!\n");
			}
			else
			{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				free(curr);
			}
		}
	}
}

void view()
{
	if(head == NULL)
	{
		printf("There is no queue");
	}
	else
	{
		curr = head; //curr = tail
		while(curr != NULL)
		{
			printf("%d", curr->key);
			curr = curr->next; // curr = curr->prev
			
			(curr != NULL) ? printf(" => ") : printf("\n"); // <=
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

int main ()
{
	int pilihan = 0, i = 0;
	int insertKey, deleteKey;
	do{
		for(i = 0; i < 25; i++) printf("\n");
		view();
		printf("\n\nQueue with Doubly Linked List\n===============\n");
		printf("1. PushBelakang\n");
		printf("2. PopDepan\n");
		printf("3. PushDepan\n");
		printf("4. PopBelakang\n");
		printf("5. InsertPriority\n");
		printf("6. PopSearching\n");
		printf("7. Exit\n");
		printf("Masukkan pilihan anda : ");
		
		scanf("%d", &pilihan);
		
		switch(pilihan)
		{
			case 1:
				printf("Masukkan angka : ");
				scanf("%d", &insertKey);
				
				pushBelakang(insertKey);
				break;
			case 2:
				popDepan();
				break;				
			case 3:				
				printf("Masukkan angka = ");
				scanf("%d", &insertKey);
				
				pushDepan(insertKey);
				break;
			case 4:
				popBelakang();
				break;
			case 5:
				printf("Masukkan angka = ");
				scanf("%d", &insertKey);
				
				priority(insertKey);
				break;
			case 6:
				printf("Masukkan angka yang mau dihapus : ");
				scanf("%d", &deleteKey);
				
				popSearching(deleteKey);
				break;
		}
		
	}while(pilihan != 6);
	
	popAll();
	
	return 0;
}
