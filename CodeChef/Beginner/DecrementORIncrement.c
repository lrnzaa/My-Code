#include <stdio.h>

int main ()
{
	int N;
	
	scanf("%d", &N);
	
	if(N % 4 == 0)
	{
		printf("%d\n", N+1);
	}
	else
	{
		printf("%d\n", N-1);
	}
	
	return 0;
}
