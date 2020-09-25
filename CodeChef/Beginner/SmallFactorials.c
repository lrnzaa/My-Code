#include <stdio.h>

int fact(int n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}
	
	return n * fact(n-1);
}

int main ()
{
	int t, i, n, m;
	long long ans = 0;
	int t1;
	
	scanf("%d", &t);
	
	for(t1 = 0; t1 < t; t1++)
	{
		scanf("%d", &n);
		
		ans = fact(n);
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
