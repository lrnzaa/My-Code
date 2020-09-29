#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char map[20][20];
	int x,y;
	int speedX, speedY;
	srand(time(NULL));
	x=rand()%18+1;
	y=rand()%18+1;
	speedX=1;
	speedY=1;
	
	
	while(true){
		system("cls");
		
		if(x+speedX<1||x+speedX>18){
			speedX*=-1;
		}
		if(y+speedY<1||y+speedY>18){
			speedY*=-1;
		}
		x+=speedX;
		y+=speedY;
		
	
		for (int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				if(i==0||i==19||j==0||j==19)
					map[j][i]='#';
				else
					map[j][i]=' ';
				if(j==x&&i==y)
					map[j][i]='0';		
			}
		}
		
		for (int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				printf("%c",map[j][i]);				
			}
			puts("");
		}
		Sleep(500);
	}

return 0;
}
