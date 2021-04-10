#include<stdio.h>

int main()
{
    int n, i;
    int narr[1000001] = {0};
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", &narr[i]);
    }
    
    for(i = n; i > 0; i--)
    {
        printf("%d\n", narr[i-1]);
    }
    
    return 0;
}
