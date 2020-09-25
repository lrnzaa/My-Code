#include <stdio.h>

int main()
{
	int T, t1;
	long N, sum;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%ld", &N);
		
		sum = 0;
		
		while(N != 0)
		{
			sum = sum + (N %10);
			N /= 10;
		}
		
		printf("%ld\n", sum);
	}
	
	return 0;
}
