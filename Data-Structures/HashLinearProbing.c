#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1. masukkan nama
//2. key = nama dijumlahkan ascii
//3. hash function : division
//4. size : 13
//5. chaining

int size = 13;

struct data{
	int hashKey;
	char nama[100];
}hashTable[13];

int hash(char str[100]){
	int panjang = strlen(str);
	int i, hashKey, keyValue = 0;
	int midSquare;
	char strMid[100];
	
	//mengubah string menjadi key
	for(i = 0; i < panjang; i++){
//		printf("%d = %d\n", str[i], keyValue);
		keyValue += str[i];
	}
	
	//hash function nya : division
	hashKey = keyValue % size;
	
	return hashKey % size;
}

int main(){
	int choice = 0;
//	char hashTable[13][100];
	char strValue[100];
	do{
		printf("1. Insert Data\n");
		printf("2. View Hash Table\n");
		printf("3. Exit\n");
		printf("Choice = ");
		scanf("%d", &choice); fflush(stdin);
		switch(choice){
			case 1:
				do{
					printf("Masukkan data [3..50] : ");
					gets(strValue);				
				}while(strlen(strValue) < 3 || strlen(strValue) > 50);
				
				if(strcmpi(hashTable[hash(strValue)].nama, "") == 0){
					hashTable[hash(strValue)].hashKey = hash(strValue);
					strcpy(hashTable[hash(strValue)].nama, strValue);					
				}
				else{
					int lastIndex = hash(strValue) + 1;
					while(strcmpi(hashTable[lastIndex].nama, "") != 0)
						lastIndex++;
						
					lastIndex = lastIndex % size;
					hashTable[lastIndex].hashKey = lastIndex;
					strcpy(hashTable[lastIndex].nama, strValue);					
				}
				
				break;
			case 2:
				view();
				break;
		}
	}while(choice != 3);	
	
	return 0;
}
