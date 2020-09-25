#include <stdio.h>

int main ()
{
	int T, N, t1, n1,count;
	char txt[1001];
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%d", &N);
		
		scanf("%s", txt);
		
		count = 0;
		
		for(n1 = 0; n1 < N; n1++)
		{
			if(txt[n1] == 'N')
			{
				count ++;
			}
			
			else if(txt[n1] == 'Y')
			{
				printf("NOT INDIAN\n");
				count = 0;
				break;
			}
			
			else if(txt[n1] == 'I')
			{
				printf("INDIAN\n");
				count = 0;
				break;
			}
		}
		
		if(count > 0)
		{
			printf("NOT SURE\n");
		}
	}
	
	return 0;
}
