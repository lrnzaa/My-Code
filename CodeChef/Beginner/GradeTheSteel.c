#include <stdio.h>

int main ()
{
	int T, t1;
	int hard, tensile;
	float carbon;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%d %f %d", &hard, &carbon, &tensile);
		
		if(hard > 50 && carbon < 0.7 && tensile > 5600)
		{
			printf("10\n");
		}
		
		else if(hard > 50 && carbon < 0.7)
		{
			printf("9\n");
		}
		
		else if(carbon < 0.7 && tensile > 5600)
		{
			printf("8\n");
		}
		
		else if(hard > 50 && tensile > 5600)
		{
			printf("7\n");
		}
		
		else if(hard > 50 || carbon < 0.7 || tensile > 5600)
		{
			printf("6\n");
		}
		
		else if(hard <= 50 && carbon >= 0.7 && tensile <= 5600)
		{
			printf("5\n");
		}
	}
	
	return 0;
}
