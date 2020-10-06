#include <stdio.h>

int main()
{
	int T, t1, N, count, i;
	char angka[100001];
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		scanf("%d %s", &N, angka);
		
		count = 0;
		
		for(i = 0; angka[i] != '\0'; i++)
		{
			if(angka[i] == '0')
			{
				count++;
			}
		}
		
		printf("Case #%d: %d\n", t1+1, count);
	}
	
	return 0;
}
