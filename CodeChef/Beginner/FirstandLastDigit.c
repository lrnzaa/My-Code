#include <stdio.h>

int main()
{
	int T, t1;
	long N, tempN, sum, last, first;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%ld", &N);
		
		tempN = N;

		last = N % 10;
				
		while(tempN >= 10)
		{
			tempN /= 10;
		}
		
		first = tempN;
		
		sum = first + last;
		
		printf("%ld\n", sum);
	}
	
	return 0;
}
