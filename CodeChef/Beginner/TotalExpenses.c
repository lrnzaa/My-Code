#include <stdio.h>

int main ()
{
	int T, t1;
	long quantity, price;
	double total;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%ld %ld", &quantity, &price);
		
		if(quantity > 1000)
		{
			total = ((quantity * price) - ((quantity * price) * 0.1));
		}
		
		else if(quantity < 1000)
		{
			total = quantity * price;
		}
		
		printf("%lf\n", total);
	}
		
	
	return 0;
}
