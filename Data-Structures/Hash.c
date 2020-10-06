#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1. data yang di hash : masukkan nama
//2. nama itu diubah menjadi key dengan menjumlahkan ascii nya
//3. hash function yang digunakan adalah division
//4. kalo ada collision pakenya chaining
//5. size dari table : 97

int size = 0;


//linear probing ga butuh struct

struct data{
	int key;
	char nama[51];
	struct data *next;
}*head[97], *tail[97], *curr; //head nya sebanyak size nya 97 linkedlist

int hash(char insertedName[51])
{
	int panjang = strlen(insertedName);
	int hashValue;
	int jumAscii = 0, i = 0;
	
	//2. mengubah nama menjadi key dengan jumlahkan ascii
	for(i = 0; i < panjang; i++)
	{
		jumAscii += insertedName[i];
	}
	
	//3. hash function pakai division
	//division
	hashValue = jumAscii % size;
	
	return hashValue;
}

void pushHashTable(int hashValue, char insertedName[])
{
	curr = (struct data *)malloc(sizeof(struct data));
	curr->key = hashValue;
	strcpy(curr->nama, insertedName);
	curr->next = NULL;
	
	if(head[hashValue] == NULL)
	{
		head[hashValue] = tail[hashValue] = curr;
	}
	else
	{
		tail[hashValue]->next = curr;
		tail[hashValue] = tail[hashValue]->next;
	}
	
	tail[hashValue]->next = NULL;
}

void view()
{
	int i;
	printf("| H[] | String |\n");
	
	for(i = 0; i < size; i++)
	{
		if(head[i] == NULL)
		{
//			printf("Hash Value %d = kosong\n", i);
		}
		else
		{
			curr = head[i];
			printf("|  %d  | ", i);
//			printf("Hash Value %d = ", i);
			while(curr != NULL)
			{
				printf("%s", curr->nama);
				curr = curr->next;
				
				curr != NULL ? printf(" => ") : printf("|\n");
			}
		}
	}
}

void getValue(int hashValue, char searchedName[])
{
	curr = head[hashValue];
	
	while(curr != NULL)
	{
		if(strcmpi(curr->nama, searchedName) == 0)
		{
			printf("%d : %s\n", curr->key, curr->nama);
			break; //jika tidak boleh ada data yang sama di hash table
		}
		curr = curr->next;
	}
}

void popAll()
{
	int i = 0;
	
	for(i = 0; i < size; i++)
	{
		curr = head[i];
		
		while(curr != NULL)
		{
			head[i] = head[i]->next;
			free(curr);
			curr = head[i];
		}
		
		head[i] = tail[i] = NULL;
	}
}

int main()
{
	int pilihan = 0, i =0;
	char insertedName[51];
	size = 97;
	char hashTable[97][51] = {""}; //linear
	
	do{
		for(i = 0; i < 25; i++)
		{
			printf("Hashing\n");
			printf("1. Insert\n");
			printf("2. View\n");
			printf("3. View Detail\n");
			printf("4. Exit\n");
			printf("Masukkan pilihan : ");
			scanf("%d", &pilihan);
			fflush(stdin);
			
			switch(pilihan)
			{
				case 1:
					//1. masukkan data
					printf("Masukkan nama [3..50] : ");
					gets(insertedName);
					
					printf("HashValue : %d\n", hash(insertedName));
					
					//4. collision pakai chaining
					//chaining
					pushHashTable(hash(insertedName), insertedName);
					
					//linear probing
					if(strcmpi(hashTable[hash(insertedName)], "") == 0)
					{
						strcpy(hashTable[hash(insertedName)], insertedName);
					}
					else
					{
						//insert ke tempat kosong selanjutnya
						
					}
					break;
					
				case 2:
	//				linear
	//				for(i = 0; i < size; i++)
	//				{
	//					printf("HashValue = %d : %s\n", i, hashTable[i]);
	//				}
					
					view();
					break;
					
				case 3:
					printf("Masukkan nama [3..50] : ");
					gets(insertedName);
					
					getValue(hash(insertedName), insertedName);
					break;
			}
		}
	}while(pilihan != 4);
	
	return 0;
}
