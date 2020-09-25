#include <stdio.h>

int main ()
{
    int N, P, i;
    char nama[1001];
    
    scanf("%d %d", &N, &P);
    
    for(i = 0; i < N; i++)
    {
        scanf("%s", nama);
    }
    
    printf("%d\n", P);
    
    return 0;
}
