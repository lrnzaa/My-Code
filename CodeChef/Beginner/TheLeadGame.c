#include <stdio.h>

int main ()
{
	int N, n1;
	int S, T, W, L, L2;
	
	scanf("%d", &N);
	
	for(n1 = 0; n1 < N; n1++)
	{
		scanf("%d %d", &S, &T);
		
		if(S > T)
		{
			W = 1;
			L = S - T;
		}
		else if(S < T)
		{
			W = 2;
			L = T - S;
		}
		
	}
	
	printf("%d %d\n", W, L);		
			
	
	return 0;
}
