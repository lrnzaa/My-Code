#include<stdio.h>

int main()
{
    int n,  n1, x;
    
    scanf("%d", &n);
    
    for(n1 = 0; n1 < n; n1++)
    {
        scanf("%d", &x);
        
        if(x % 2 == 0)
        {
            printf("%d is even\n", x);
        }
        else
        {
            printf("%d is odd\n", x);
        }
    }
    
    return 0;
}
