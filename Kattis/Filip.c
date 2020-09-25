#include <stdio.h>

int main ()
{
    int A, B;
    int a1, b1, i;
    
    scanf("%d %d", &A, &B);
    
    a1 = A;
    b1 = B;
    
    while(a1 >= 10)
    {
        a1 %= 10;
    }

    while(b1 >= 10)
    {
        b1 %= 10;
    }
    
    if(a1 > b1)
    {
        a1 = A;
        i = 0;
        
        while (a1 > 0)
        {
            i = (i*10) + (a1%10);
            a1 /= 10;
        }
    }
    
    else if(a1 < b1)
    {
        b1 = B;
        i = 0;
        
        while (b1 > 0)
        {
            i = (i*10) + (b1%10);
            b1 /= 10;
        }
    }
    
    else if(a1 == b1)
    {
        a1 = (A / 10) % 10;
        b1 = (B / 10) % 10;
        
        if(a1 > b1)
        {
            a1 = A;
            i = 0;
            
            while (a1 > 0)
            {
                i = (i*10) + (a1%10);
                a1 /= 10;
            }
        }
        
        else if(a1 < b1)
        {
            b1 = B;
            i = 0;
            
            while (b1 > 0)
            {
                i = (i*10) + (b1%10);
                b1 /= 10;
            }
        }       
    }
    
    printf("%d\n", i);
    
    return 0;
}
