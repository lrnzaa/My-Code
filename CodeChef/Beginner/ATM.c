#include <stdio.h>

int main ()
{
	int X;
	float Y, balance;
	
	scanf("%d %f", &X, &Y);
	
	if(X % 5 == 0 && X + 0.50 < Y)
	{
		balance = (Y - X) - 0.50;
	}
	
	else if(X % 5 != 0 || X + 0.50 > Y)
	{
		balance = Y;
	}
	
	printf("%.2f\n", balance);
		
	return 0;
}
