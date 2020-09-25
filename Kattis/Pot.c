#include<stdio.h>
#include <math.h>

int main()
{
    int N, n1, P[11], i;
    float ld, fd;
    long X;
    double sum;
    
    scanf("%d", &N);
    
    X = 0;
    sum = 0;
    ld = 0;
    fd = 0;
    
    for(n1 = 0; n1 < N; n1++)
    {       
        scanf("%d", &P[n1]);
    }
    
    for(i = 0; i < N; i++)
    {
        
        ld = P[i] % 10;
        fd = P[i] / 10;
        
        sum += pow(fd, ld);
    }
    
    X = (long int) sum;
        
    printf("%ld\n", X);

    return 0;
}
