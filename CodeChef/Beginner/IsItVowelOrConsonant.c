#include <stdio.h>

int main()
{
	char C;
	
	scanf("%c", &C);
	getchar();
	
	if(C == 'A' || C == 'I' || C == 'U' || C == 'E' || C == 'O')
	{
		printf("Vowel\n");
	}
	else
	{
		printf("Consonant\n");
	}
	
	return 0;
}
