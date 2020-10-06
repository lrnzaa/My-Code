  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1. masukkin nama
//2. key = nama dijumalahkan ascii
//3. hash function : division
//4. size : 13
//5. chaining

int size = 13;

struct data{
	int hashKey;
	char nama[100];
	struct data *next;
}*head[13], *tail[13], *curr;

int hash(char str[100])
{
	int panjang = strlen(str);
	int i, hashKey, keyValue = 0;
//	int midsquare = 0;
//	char strMid[100];

	//mengubah string menjadi key
	for(i = 0; i < panjang; i++)
	{
		keyValue += str[i];
	}
	
	//hash function nya -> division
	hashKey = keyValue % size;
	
	//kalo midsquare
//	midsquare = keyValue * keyValue; // square
//	sprintf(strMid, "%d", midsquare); // ubah string
//	panjang = strlen(strMid) / 2 - 1; // ambil nilai tengah

// dapatkan nilai tengah pertama + nilai tengah kedua
//	hashKey = (strMid[panjang] - '0') * 10 + (strMid[panjang+1] - '0');

// printf("%d %s %d\n", keyValue, strMid, panjang);
// return hashKey % size; <-- returnnya
	return hashKey;
}

void push(int hashKey, char str[100]) // pushbelakang
{
	curr = (struct data *)malloc(sizeof(struct data));
	curr->hashKey = hashKey;
	strcpy(curr->nama, str);
	curr->next = NULL;
	
	if(head[hashKey] == NULL)
	{
		head[hashKey] = tail[hashKey] = curr;
	}
	else
	{
		tail[hashKey]->next = curr;
		tail[hashKey] = curr;
	}
	tail[hashKey]->next = NULL;
}

void view()
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		curr = head[i];
		printf("h[%d]. ", i);
		
		while(curr != NULL)
		{
			printf("%s", curr->nama);
			curr = curr->next;
			
			(curr != NULL) ? printf(" => ") : printf("\n");
		}
		printf("\n");
	}
}

int main()
{
	int choice = 0;
	char strValue[100];
	
	do{
		printf("1. Insert Data\n");
		printf("2. View Hash Table\n");
		printf("3. Exit\n");
		printf("Choice : ");
		scanf("%d", &choice);
		fflush(stdin); //atau pake getchar();
		
		switch(choice)
		{
			case 1:
				do{
					printf("Masukkan data [3..50] : ");
					gets(strValue);
				}while(strlen(strValue) < 3 || strlen(strValue) > 50);
				
//				printf("%d\n", hash(strValue));
				push(hash(strValue), strValue);
				
				break;
				
			case 2:
				
				view();
				break;
		}
		
	}while(choice != 3);
	
	return 0;
}
