#include <stdio.h>

int main ()
{
	int T, t1, n;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%d", &n);
		
		if(n >= -20 && n < 10)
		{
			printf("What an obedient servant you are!\n");
		}
		else if(n >= 10)
		{
			printf("-1\n");
		}
	}
	
	return 0;
}
