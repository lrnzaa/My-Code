#include <stdio.h>
#include <stdlib.h>


int main ()
{
	int a, b, i;
	
	printf("Angka < 100 : ");
	scanf("\n %d", &a);
	
	//prime number < 100
	
	for(i = 2; i < a; i++)
	{
		for (b = 2; b <= (i / b); b++)
		
			if (!(i %b )) 
				break; //if factor not found break
			if (b > (i / b))
				printf("%d is prime number. \n", i);
	}
	
	return 0;
}
