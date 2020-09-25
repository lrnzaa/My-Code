#include <stdio.h>

int main ()
{
	int T, t1;
	long salary;
	double gross;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%ld", &salary);
		
		if(salary < 1500)
		{
			gross = salary + (salary * 0.1) + (salary * 0.9);
		}
		
		else if(salary >= 1500)
		{
			gross = salary + (500) + (salary * 0.98);
		}
		
		printf("%.2lf\n", gross);
	}
	
	return 0;
}
