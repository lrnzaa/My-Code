#include <stdio.h>
#include <stdlib.h>

int main ()
{
//lurus
	int a, i, j, k;
	printf("Masukkan angka : ");
	scanf("\n %d", &a);
	
	for (i = 1; i <= a; i++)
	{
		for (k = i; k < a; k++)
			{
				printf(" ");
			}
		for (j = 1; j <= i; j++)
		{
			
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
