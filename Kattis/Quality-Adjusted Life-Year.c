#include <stdio.h>

int main ()
{
    int N, i;
    double q, y, result;
    
    scanf("%d", &N);
    
    result = 0;
    
    for(i = 0; i < N; i++)
    {
        scanf("%lf %lf", &q, &y);
        
        result += (q * y);
    }
    
    printf("%.3lf\n", result);
    
    return 0;
}
