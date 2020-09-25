#include <stdio.h>

int main ()
{
	int T, t1;
	long int a, b, sum;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%d", &a);
		scanf("%d", &b);
	
		sum = (a + b) - 10;
		
		printf("%d\n", sum);
	}
	
	return 0;
}
