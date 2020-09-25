#include <stdio.h>

int main ()
{
    int n, speed, jam, i, xj, total;
        
    do
    {
        scanf("%d", &n);
        
        if(n != -1)
        {
            xj = 0;
            total = 0;
            
            for(i = 0; i < n; i++)
            {
                scanf("%d %d", &speed, &jam);
                
                if(xj < jam)
                {
                    xj = jam - xj;
                }
                else if(xj > jam)
                {
                    xj -= jam;
                }
                
                total += (speed * xj);
                
                xj = jam;
            }
            
            printf("%d miles\n", total);
        }
    } while(n != -1);
    
    return 0;
}
