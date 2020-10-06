#include <stdio.h>

int main ()
{
	int T, t1, i, count;
	char kata[1001] = {0};
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%s", &kata);
		
		count = 0;
		
		for(i = 0; kata[i] != '\0'; i++)
		{
			count++;
		}
		
		printf("Case #%d:\n", t1+1);
		
		for(i = 0; i < count; i++)
		{
			printf("%d", kata[i]);
			
			if(i < count - 1)
			{
				printf("-");
			}
		}
		
		printf("\n");
	}
	
	return 0;
}
