#include<stdio.h>

int main()
{
    int n, i;
    long int r, e, c;
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        scanf("%ld %ld %ld", &r, &e, &c);
        
        if(e - c > r)
        {
        	printf("advertise\n");
        }
        else if(e - c < r)
        {
        	printf("do not advertise\n");
        }
        else
        {
        	printf("does not matter\n");
        }
	}
    
    return 0;
}
