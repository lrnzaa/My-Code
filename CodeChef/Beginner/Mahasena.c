#include <stdio.h>

int main ()
{
	int n, n1, odd = 0, even = 0;
	int a[101];
	
	scanf("%d", &n);
	
	for(n1 = 0; n1 < n; n1++)
	{
		scanf("%d", &a[n1]);
	}
	
	for(n1 = 0; n1 < n; n1++)
	{
		if(a[n1] % 2 == 0)
		{
			even++;
		}
		
		if(a[n1] % 2 != 0)
		{
			odd++;
		}
	}
	
	if(even > odd)
	{
		printf("READY FOR BATTLE\n");
	}
	
	else if(even <= odd)
	{
		printf("NOT READY\n");
	}

	
	return 0;
}
