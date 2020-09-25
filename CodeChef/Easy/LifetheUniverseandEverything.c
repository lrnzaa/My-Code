#include <stdio.h>

int main ()
{
	int a;
	
	do
	{
		scanf("%d", &a);
		
		if(a != 42)
		{
			printf("%d\n", a);
		}
	} while(a != 42);
	
	
	return 0;
}
