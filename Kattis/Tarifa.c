#include <stdio.h>

int main ()
{
    int X, N, P, i, total = 0;
    
    scanf("%d", &X);
    scanf("%d", &N);
    
    for(i = 0; i < N; i++)
    {
        scanf("%d", &P);
        
        total += (X-P);
    }
    
    printf("%d\n", total+X);
    return 0;
}
