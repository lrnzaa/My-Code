#include<stdio.h>

int main()
{
    int n, n1, bats[1001], count, total;
    float outtt;
    
    scanf("%d", &n);
    
    count = 0;
    total = 0;
    outtt = 0;
    count = n;
    
    for(n1 = 0; n1 < n; n1++)
    {
        scanf("%d", &bats[n1]);
    }
    
    for(n1 = 0; n1 < n; n1++)
    {
        if(bats[n1] == -1)
        {
            total += 0;
            count--;
        }
        else
        {
            total += bats[n1];
        }
    }
    
    outtt = (float)total/count;
    
    printf("%f\n", outtt);
    
    return 0;
}
