#include <stdio.h>

int main ()
{
	int N1, N2;
	
	scanf("%d", &N1);
	scanf("%d", &N2);
	
	if(N1 > N2)
	{
		printf("%d\n", (N1 - N2));
	}
	
	else
	{
		printf("%d\n", (N1 + N2));
	}
	
	return 0;
}
