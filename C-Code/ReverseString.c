#include <stdio.h>

int panjang(char *kata)
{
	int i = 0, count = 0;
	
	while(kata[i] != '\0')
	{
		i++;
		count++;
	}
	
	return count;
}

void strrev(char *kata)
{
	int ke = panjang(kata);
	
	while(ke != -1)
	{
		ke--;
		printf("%c", kata[ke]);
	}
	
	printf("\n");
}

int main ()
{
	int N, n1;
	char kata[1001];
	
	scanf("%d", &N);
	
	for(n1 = 0; n1 < N; n1++)
	{
		scanf("%s", kata);
		
		printf("Case #%d: ", n1+1);
		
		strrev(kata);
	}
	
	return 0;
}
