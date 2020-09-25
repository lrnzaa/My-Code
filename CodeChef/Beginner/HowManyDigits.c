#include <stdio.h>

int main ()
{
	long N, num;
	int count = 0;
	
	scanf("%ld", &N);
	
	num = N;
	
	if(N == 0)
	{
		count = 1;
	}
	
	while(num > 0)
	{
		num /= 10;
		count++;
	}
	
	
	printf("%d\n", count);
	
	return 0;
}
