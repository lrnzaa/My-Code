#include<stdio.h>

int main()
{
    int n, n1, t, count;
    
    scanf("%d", &n);
    
    count = 0;
    
    for(n1 = 0; n1 < n; n1++)
    {
        scanf("%d", &t);
        
        if(t < 0)
        {
            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}
