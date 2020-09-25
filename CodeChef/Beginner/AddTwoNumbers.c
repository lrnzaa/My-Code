#include <stdio.h>

int main ()
{
	int T, A, B, add;
	int t1;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%d %d", &A, &B);
		
		add = A + B;
		
		printf("%d\n", add);
	}
	
	return 0;
}
