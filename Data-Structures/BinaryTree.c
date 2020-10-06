#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int key;
	struct node *left, *right, *parent;
}*root = NULL;

struct node *insert(struct node *curr, int insertedKey)
{
	if(curr == NULL)
	{
		curr = (struct node *)malloc(sizeof(struct node));
		curr->key = insertedKey;
		curr->left = curr->right = NULL;
		curr->parent = NULL;
	}
	else
	{
		char pilih[10];
		printf("Mau ke kiri atau ke kanan dari %d?", curr->key);
		gets(pilih);
		
		if(strcmpi(pilih, "kiri") == 0)
		{
			curr->left = insert(curr->left, insertedKey);
			curr->left->parent = curr;
		}
		else if (strcmpi(pilih, "kanan") == 0)
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
	
	view(curr->left); //
	printf("%d ", curr->key);
	view(curr->right);
}

struct node *popAll(struct node *curr)
{
	if(curr == NULL)
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
	int choice = 0, insertedKey = 0;
	
	do{
		printf("Binary Tree\n");
		printf("1. Insert Data\n");
		printf("2. View Tree\n");
		printf("3. Exit\n");
		printf("Pilihan : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Masukkan key = ");
				scanf("%d", &insertedKey);
				fflush(stdin);
				
				root = insert(root, insertedKey);
				printf("Root = %d\n", root->key);
				
				if(root->left != NULL)
				{
					printf("Anak kiri root = %d\n", root->left->key);
					printf("%d\n", root->left->parent->key);
				}
				if(root->right != NULL)
				{
					printf("Anak kanan root = %d\n", root->right->key);
					printf("%d\n", root->right->parent->key);
				}
				break;
				
			case 2:
				view(root);
				puts("");
				getchar();
				break;
		}
	}while(choice != 3);
	
	root = popAll(root);
	
	return 0;
}
