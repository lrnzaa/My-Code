#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	int height;
	struct node *left, *right;	
}*root = NULL;

int getHeight(struct node * curr)
{
	if(curr == NULL)
	{
		return 0;
	}
	
	return curr->height;
}

int getBF(struct node * curr)
{
	if(curr == NULL)
	{
		return 0;
	}
	
	return getHeight(curr->left) - getHeight(curr->right);
}

int max(int a, int b)
{
	return a > b ? a : b;
}

/*
		T		S
	   / \	   / \
	  S  c    a  T
	 / \		/ \
	a  b        b  c
*/

struct node * rightRotate( struct node * T)
{
	//atur posisi kunci dari yg di rotate
	struct node * S = T->left;
	struct node * b = S->right;
	
	//rotate
	S->right = T;
	T->left = b;
	
	S->height = max(getHeight(S->left), getHeight(S->right)) + 1;
	T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
	
	return S;
}

/*
		T		  S
	   / \	     / \
	  a  S      T  c
	    / \	   / \
	    b  c  a  b
*/

struct node * leftRotate(struct node * T)
{
	//gambarkan posisi T, S dan b
	struct node * S = T->right;
	struct node * b = S->left;
	
	//rotate
	S->left = T;
	T->right = b;
	
	S->height = max(getHeight(S->left), getHeight(S->right)) + 1;
	T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
	
	return S;
}


struct node * insert(struct node * curr, int insertedKey)
{
	if(curr == NULL)
	{
		curr = (struct node *) malloc(sizeof(struct node));
		curr->key = insertedKey;
		curr->height = 1;
		curr->left = curr->right = NULL;
	}
	else
	{
		if( insertedKey < curr->key)
		{
			curr->left = insert(curr->left, insertedKey);
		}
		else
		{
			curr->right = insert(curr->right, insertedKey);
		}
	}
	
	//update height
	curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
	
	//cek violation
	int BFactor = getHeight(curr->left) - getHeight(curr->right);
	// bernilai positif (kalau kirinya lebih panjang) level lebih tinggi
	//atau bernilai negatif (kalau kanannya lebih panjang) level lebih tinggi
	
	//cek balance factor lebih dari 2 atau lebih kecil dari -2
	if(BFactor > 1 && insertedKey < curr->left->key)
	{
		//case 1 LL Rotation
		printf("Case 1 : LL Rotation %d\n", curr->key);
		return rightRotate(curr);
	}
	
	if(BFactor < -1 && insertedKey > curr->right->key)
	{
		//case 2 RR Rotation
		printf("Case 2 : RR Rotation %d\n", curr->key);
		return leftRotate(curr);
	}
	
	if(BFactor > 1 && insertedKey > curr->left->key)
	{
		//case 3 LR Rotation
		printf("Case 3 : LR Rotation %d\n", curr->key);
		curr->left = leftRotate(curr->left);
		return rightRotate(curr);
	}
	
	if(BFactor < -1 && insertedKey < curr->right->key)
	{
		//case 4 RL Rotation
		printf("Case 4 : RL Rotation %d\n", curr->key);
		curr->right = rightRotate(curr->right);
		return leftRotate(curr);
	}	
	
	return curr;
}

struct node * deleteValue(struct node * curr, int deletedKey)
{
	//data tidak ditemukan atau tree masih kosong
	if( curr == NULL )
	{
		return NULL;
	}
	
	else if(deletedKey < curr->key)
	{
		curr->left = deleteValue(curr->left, deletedKey);		
	}
	
	else if(deletedKey > curr->key)
	{
		curr->right = deleteValue(curr->right, deletedKey);
	}
	
	else
	{ 		
		//data ketemu
		//1. dia adalah leaf
		//2. hanya punya 1 anak
		if(curr->left == NULL || curr->right == NULL)
		{
			struct node * temp = NULL;
			
			if(curr->left != NULL) 
			{
				temp = curr->left;
			}
			else 
			{
				temp = curr->right;
			}
			
			//key yang dicari di leaf
			if(temp == NULL)
			{
				temp = curr;
				curr = NULL;
			}
			//key yang dicari bukan leaf
			else
			{
				*curr = *temp;
			}
			
			free(temp);
		}
		
		//3. dia punya 2 anak				
		else
		{
			//ambil data kiri paling besar (predecessor)
			struct node * temp = curr->left;
			while(temp->right != NULL)
			{
				temp = temp->right;
			}
			
			//successor kanan terkecil
//			struct node * temp = curr->right;
//			while(temp->left != NULL)
//			{
//				temp = temp->left;
//			}			
			//copy semua data dari temp ke curr
			curr->key = temp->key;
			
			//delete secara rekursif angka yang dicari
			curr->left = deleteValue(curr->left, temp->key);
			//successor
//			curr->right = deleteValue(curr->right, temp->key);
		}
	}
	
	//ketika yang dihapus leaf
	if(curr == NULL) 
	{
		return NULL;
	}
	
	//rebalance AVL Tree
	curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
	int BFactor = getHeight(curr->left) - getHeight(curr->right);
		
	if(BFactor > 1 && getBF(curr->left) >= 0)
	{
		//LL Rotation
		printf("LL Rotation %d\n", curr->key);
		return rightRotate(curr);
	}
	
	if(BFactor > 1 && getBF(curr->left) < 0)
	{
		//LR Rotation
		printf("LR Rotation %d\n", curr->key);
		curr->left = leftRotate(curr->left);
		return rightRotate(curr);
	}
	
	if(BFactor < -1 && getBF(curr->right) <= 0)
	{
		//RR Rotation
		printf("RR Rotation %d\n", curr->key);
		return leftRotate(curr);
	}
	if(BFactor < -1 && getBF(curr->right) > 0)
	{
		//RL Rotation
		printf("RL Rotation %d\n", curr->key);
		curr->right = rightRotate(curr->right);
		return leftRotate(curr);
	}
	
	return curr;
}

void inorder(struct node * curr)
{
	if(curr->left != NULL) 
	{
		inorder(curr->left);
	}
	
	printf("%d ", curr->key);
	
	if(curr->right != NULL)
	{
		inorder(curr->right);
	}
}

struct node * popAll(struct node * curr)
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
	int choice = 0, insertedKey = 0, deletedKey = 0; 
	
	do{
		printf("1. Insert Data\n");
		printf("2. View Data\n");
		printf("3. Delete Data\n");
		printf("4. Exit\n");
		printf("Choice : ");
		scanf("%d", &choice); fflush(stdin);
		
		switch(choice){
			case 1:
				printf("Masukkan key : ");
				scanf("%d", &insertedKey);
				fflush(stdin);
				
				root = insert(root, insertedKey);
				break;
				
			case 2:
				inorder(root);
				getchar();
				break;
				
			case 3:
				printf("Masukkan key : ");
				scanf("%d", &deletedKey);
				fflush(stdin);
				
				root = deleteValue(root, deletedKey);
				break;
		}		
	}while(choice != 4);
	
	root = popAll(root);
	
	return 0;
}
