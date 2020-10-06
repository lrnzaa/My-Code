#include <stdio.h>
#include <stdlib.h>

struct data{
	int key;
	struct data *next; //Single Linked List (adanya 1 pointer menunjuk ke alamat memory list lainnya)
}*head, *tail, *curr;

/*
	1. Push menambahkan data
	2. Pop menghapus data
	3. View menampilkan data
	konsep queue pop depan push belakang
	konsep stack pop belakang push belakang
*/

void pushBelakang(int insertKey)
{
	curr = (struct data *)malloc(sizeof(struct data));
	curr->next = NULL;
	curr->key = insertKey;
	
	if(head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		//1. Selamatkan linknya
		tail->next = curr; 
		//2. Perbaiki linked list
		tail = curr; //atau tail = tail->next;
	}
	tail->next = NULL;
}

void view()
{
	if(head == NULL)
	{
		printf("There is no queue");
	}
	else
	{
		curr = head; //pindahkan penunjuk ke data paling depan
		while(curr != NULL)
		{
			printf("%d", curr->key);
			curr = curr->next;
			
			(curr != NULL) ? printf(" => ") : printf("\n");
		}
	}
}

void popAll()
{
	curr = head; //pindahkan penunjuk ke data paling depan
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
		//cek apakah ada data atau tidak, jika tidak ada biarkan saja
	}
	else
	{
		curr = head;
		//1. selamatkan kepalanya
		head = head->next;
		//2. hapus data pertama
		free(curr);
		
		if(head == NULL)
		{
			head = tail = NULL;
		}
	}
}

int main ()
{
	int pilihan = 0, i = 0;
	int insertKey;
	do{
		for(i = 0; i < 25; i++) printf("\n");
		view();
		printf("\n\nQueue\n===============\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Exit\n");
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
		}
		
	}while(pilihan !=3);
	
	popAll();
	
//	pushBelakang(5);
//	pushBelakang(15);
//	pushBelakang(25);
//	
//	view();
//	popDepan();
//	view();
//	popAll();
	
	return 0;
}
