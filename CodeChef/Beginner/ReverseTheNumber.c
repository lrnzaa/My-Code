#include <stdio.h>

int main ()
{
	int T, t1;
	long N, num, rev;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%ld", &N);
		
		num = N;
		rev = 0;
		
		while(num > 0)
		{
			rev = (rev * 10) + (num % 10);
			num /= 10;
		}
		
		printf("%ld\n", rev);
	}
	
	return 0;
}
