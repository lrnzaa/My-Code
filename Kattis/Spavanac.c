#include <stdio.h>

int main()
{
    int H, M, min;
    
    scanf("%d %d", &H, &M);
    
    min = M - 45;
    
    if(min < 0)
    {
        min += 60;
        H -= 1;
    }
    
    if(H < 0)
    {
        H += 24;
    }
    
    printf("%d %d\n", H, min);
    
    return 0;
}
