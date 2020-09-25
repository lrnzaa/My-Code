#include <stdio.h>

int main ()
{
	long T, n, t1, n1;
	long long a[101000];
	
	scanf("%ld", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%ld", &n);
		
		for(n1 = 0; n1 < n; n1++)
		{
			scanf("%lld", &a[n1]);
		}
		
	}
	
	return 0;
}
