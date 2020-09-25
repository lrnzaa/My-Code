#include <stdio.h>

int main()
{
	int T, t1;
	long A, B;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%ld %ld", &A, &B);
		
		if(A > B)
		{
			printf(">\n");
		}
		else if(A < B)
		{
			printf("<\n");
		}
		else if(A == B)
		{
			printf("=\n");
		}
	}
	
	return 0;
}
