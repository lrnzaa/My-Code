#include <stdio.h>

int main ()
{
	int T, A, B, t1, max, min;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%d %d", &A, &B);
		
		if(A > B)
		{
			min = A;
		}
		else if(A < B)
		{
			min = B;
		}
	
		max = A+B;
		
		printf("%d %d\n", min, max);
	}
	return 0;
}
