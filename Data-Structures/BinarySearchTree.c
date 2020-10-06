#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	//jumlah pointer disesuaikan dengan jumlah child
	struct node *left, *right; // binary tree = max 2 child
	struct node *parent;
}*root = NULL;

struct node * insert(struct node *curr, int insertedKey)
{
	if(curr == NULL)
	{
		//buat node
		curr = (struct node *)malloc(sizeof(struct node));
		curr->key = insertedKey;
		curr->left = curr->right = curr->parent = NULL;
	}
	else
	{
		//cek lokasi yang sesuai
		if(insertedKey < curr->key)
		{
			curr->left = insert(curr->left, insertedKey);
			curr->left->parent = curr;
		}
		else if(insertedKey >= curr->key)
		{
			curr->right = insert(curr->right, insertedKey);
			curr->right->parent = curr;
		}
	}
	return curr;
}

void view(struct node *curr)
{
	if(curr == NULL)
	{
		return;
	}
	printf("%d ", curr->key); //preorder
	view(curr->left);
	view(curr->right);
}

//ambil kiri paling besar
struct node * predecessor(struct node *curr)
{
	struct node *temp = curr->left;
	while(temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp;
}

//ambil kanan paling kecil
struct node *successor(struct node * curr)
{
	struct node *temp = curr->right;
	while(temp->left != NULL);
	{
		temp = temp->left;
	}
	return temp;
}

struct node * deleteValue(struct node * curr, int deletedKey)
{	//tree nya belum ada atau node tidak ketemu
	if(curr == NULL)
	{
		return NULL;
	}
	else
	{
		if(deletedKey < curr->key)
		{
			curr->left = deleteValue(curr->left, deletedKey);
		}
		else if(deletedKey > curr->key)
		{
			curr->right = deleteValue(curr->right, deletedKey);
		}
		else
		{
			//data yang  mau dihapus ketemu
			//1. apakah dia leaf
			//2. apakah dia punya 1 anak (anak kiri atau anak kanan)
			if(curr->left == NULL || curr->right == NULL)
			{
				//untuk menampung data yang ada
				struct node * temp = NULL;
				
				//anak kirinya tidak kosong
				if(curr->left != NULL)
				{
					temp = curr->left;
				}
				else // selain itu pegang anak kanannya
				{
					temp = curr->right;
				}
				
				//dia adalah leaf
				if(temp == NULL)
				{
					temp = curr;
					curr = NULL;
				}
				else
				{
					//kalau punya satu anak, naikin posisi anaknya
					temp->parent = curr->parent;
					*curr = *temp; //kayak curr->key = temp->key
				}
				free(temp);
			}
			//3. apakah dia punya 2 anak (kanan terkecil successor)
			else
			{
				//cari kiri yang paling besar (predecessor)
				struct node *temp = successor(temp);
				
				//copy data dari temp ke curr
				curr->key = temp->key;
				
				//panggil secara recursive hapus P
				//kalau predecessor pakai curr->left
				curr->left = deleteValue(curr->left, temp->key);
				
				//kalau sucessor pakai curr->right
				//curr->right = deleteValue(curr->right, temp->key);
			}
		}
	}
	return curr;
}

struct node * popAll(struct node * curr)
{
	if (curr == NULL)
	{
		return NULL;
	}
	curr->left = popAll(curr->left);
	curr->right = popAll(curr->right);
	free(curr);
	
	return NULL;
}

int main()
{
	int choice = 0, insertedKey = 0, deletedKey = 0;
	
	do{
		printf("Binary Search Tree\n");
		printf("1. Insert Data\n");
		printf("2. View\n");
		printf("3. Delete Key\n");
		printf("4. Exit\n");
		printf("Choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Masukkan Key = ");
				scanf("%d", &insertedKey);
				fflush(stdin);
				
				root = insert(root, insertedKey);
				getchar();
				break;
				
			case 2:
				view(root);
				getchar();
				break;
			
			case 3:
				printf("Masukkan key = ");
				scanf("%d", &deletedKey);
				fflush(stdin);
				
				root = deleteValue(root, deletedKey);
				getchar();
				break;
		}
	}while(choice != 4);
	
	root = popAll(root);
	
	return 0;
}
