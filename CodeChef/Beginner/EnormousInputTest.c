#include <stdio.h>

int main ()
{
	long n, k, n1;
	long i, count = 0;
	
	scanf("%ld %ld", &n, &k);
	
	for(i = 0; i < n; i++)
	{
		scanf("%ld", &n1);
		
		if(n1 % k == 0)
		{
			count++;
		}
	}
	
	printf("%ld\n", count);
	
	return 0;
}
