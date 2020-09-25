#include <stdio.h>
#include <math.h>

int main ()
{
	int T, t1;
	float N, sqroot;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%f", &N);
		
		sqroot = sqrt(N);
		
		printf("%.f\n", sqroot);
	}
	
	return 0;
}
