#include <stdio.h>

int main ()
{
	long T, t1, i, j;
	long N[101000];
	long temp;
	
	scanf("%ld", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%ld", &N[t1]);
	}
	
	for(i = 0; i < T-1; i++)
	{
		for(j = (T-1); j >= i; j--)
		{
			if(N[j-1] > N[j])
			{
				temp = N[j];
				N[j] = N[j-1];
				N[j-1] = temp;
			}
		}
	}
	
	for(i = 0; i <= T-1; i++)
	{
		printf("%ld\n", N[i]);
	}
	
	return 0;
}
