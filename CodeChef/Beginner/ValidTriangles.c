#include <stdio.h>

int main ()
{
	int T, t1, A, B, C, sum;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%d %d %d", &A, &B, &C);
		
		sum = A+B+C;
		
		if(sum == 180)
		{
			printf("YES\n");
		}
		else if(sum > 180 || sum < 180)
		{
			printf("NO\n");
		}
	}
	
	return 0;
}
