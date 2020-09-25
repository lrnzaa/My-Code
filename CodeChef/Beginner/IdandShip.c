#include <stdio.h>

int main ()
{
	int T, t1;
	char C;
	
	scanf("%d", &T);
	
	for(t1 = 0; t1 < T; t1++)
	{
		getchar();
		
		scanf("%c", &C);
		
		if(C == 'B' || C == 'b')
		{
			printf("BattleShip\n");
		}
		
		else if(C == 'C' || C == 'c')
		{
			printf("Cruiser\n");
		}
		
		else if(C =='D' || C == 'd')
		{
			printf("Destroyer\n");
		}
		
		else if(C == 'F' || C == 'f')
		{
			printf("Frigate\n");
		}
	}
	
	return 0;
}
