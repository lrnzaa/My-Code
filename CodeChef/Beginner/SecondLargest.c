#include <stdio.h>

int main()
{
	int T, t1, i;
	int num[4], max, min;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		for(i = 0; i < 3; i++)
		{
			scanf("%d", &num[i]);
		}
		
		max = num[0];
		min = num[0];
				
		for(i = 0; i < 3; i++)
		{
			if(max < num[i])
			{
				max = num[i];
			}
			if(min > num[i])
			{
				min = num[i];
			}
		}
		
		for(i = 0; i < 3; i++)
		{
			if(num[i] > min && num[i] < max)
			{
				printf("%d\n", num[i]);
			}
		}
		
	}
	return 0;
}
