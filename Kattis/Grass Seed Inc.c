#include <stdio.h>

int main ()
{
    double cost;
    int T, t1;
    double width, length, cross = 0, hrg = 0;
    
    scanf("%lf", &cost);
    scanf("%d", &T);
    
    for(t1 = 0; t1 < T; t1++)
    {
        scanf("%lf %lf", &width, &length);
        
        cross += (width * length);
    }
    
    hrg = cross * cost;
    
    printf("%.7lf\n", hrg);
    
    return 0;
}
