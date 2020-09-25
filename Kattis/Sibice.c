#include <stdio.h>
#include <math.h>

int main ()
{
    int N, W, H, i;
    int wh;
    int match;
    
    scanf("%d %d %d", &N, &W, &H);
    
    W *= W;
    H *= H;
    
    wh = sqrt(W+H);
    
    for(i = 0; i < N; i++)
    {
        scanf("%d", &match);
        
        if(match <= wh)
        {
            printf("DA\n");
        }
        else if(match > wh)
            printf("NE\n");
    }
    
    return 0;
}
