#include <stdio.h>

int main ()
{
    int k, q, r, b, kn, p;
    int k1 , q1, r1 , b1, kn1, p1;
    
    scanf("%d %d %d %d %d %d", &k, &q, &r, &b, &kn, &p);
    
    if(k == 0)
    {
        k1 = 1;
    }
    else if(k == 1)
    {
        k1 = 0;
    }
    else if(k > 1)
    {
    
        k1 = 1- k;
    }
    
    if(q == 0)
    {
        q1 = 1;
    }
    else if(q == 1)
    {
        q1 = 0;
    }
    else if(q > 1)
    {
        
        q1 = 1- q;
    }
    
    if(r == 0)
    {
        r1 = 2;
    }
    else if(r == 1)
    {
        r1 = 1;
    }
    else if(r == 2)
    {
        r1 = 0;
    }
    else if(r > 2)
    {
        
        r1 = 2- r;
    }
    
    if(b == 0)
    {
        b1 = 2;
    }
    else if(b == 1)
    {
        b1 = 1;
    }
    else if(b == 2)
    {
        b1 = 0;
    }
    else if(b > 2)
    {
       
        b1 = 2-b;
    }
    
    if(kn == 0)
    {
        kn1 = 2;
    }
    else if(kn == 1)
    {
        kn1 = 1;
    }
    else if(kn == 2)
    {
        kn1 = 0;
    }
    else if(kn > 2)
    {
     
        kn1 = 2- kn;
    }
    
    if(p == 0)
    {
        p1 = 8;
    }
    else if(p == 1)
    {
        p1 = 7;
    }
    else if(p == 2)
    {
        p1 = 6;
    }
    else if(p == 3)
    {
        p1 = 5;
    }
    else if(p == 4)
    {
        p1 = 4;
    }
    else if(p == 5)
    {
        p1 = 3;
    }
    else if(p == 6)
    {
        p1 = 2;
    }
    else if(p == 7)
    {
        p1 = 1;
    }
    else if(p == 8)
    {
        p1 = 0;
    }
    else if(p > 8)
    {
        p1 = 8 - p;
    }
    
    printf("%d %d %d %d %d %d\n", k1, q1, r1, b1, kn1, p1);
    return 0;
}
