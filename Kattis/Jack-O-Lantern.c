#include<stdio.h>

int main()
{
    int N, T, M, sum;
    
    scanf("%d %d %d", &N, &T, &M);
    
    sum = 0;
    sum = N*T*M;
    
    printf("%d\n", sum);
    
    return 0;
}
