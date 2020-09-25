#include <stdio.h>

int main ()
{
	int A, B;
	char C;
	int sum, min, kali;
	float div;
	
	scanf("%d", &A);
	getchar();
	
	scanf("%d", &B);
	getchar();
	
	scanf("%c", &C);
	getchar();
	
	if(C == '+')
	{
		sum = A + B;
		
		printf("%d\n", sum);
	}
	else if(C == '*')
	{
		kali = A * B;
		
		printf("%d\n", kali);
	}
	else if(C == '-')
	{
		min = A - B;
		
		printf("%d\n", min);
	}
//masih salah disini
	else if(C == '/')
	{
		div = A / B;
		
		printf("%.1f\n", div);
	}
	else
	{
		printf("\n");
	}
	
	return 0;
}
