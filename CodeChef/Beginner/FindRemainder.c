#include <stdio.h>

int main ()
{
	int T, A, B;
	int t1, rem;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%d %d", &A, &B);
		
		rem = A%B;
		
		printf("%d\n", rem);
	}
	
	return 0;
}
