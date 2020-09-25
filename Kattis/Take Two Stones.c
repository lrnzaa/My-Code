#include  <stdio.h>

int main ()
{
    int stone;
    
    scanf("%d", &stone);
    
    if(stone % 2 == 0)
    {
        printf("Bob\n");
    }
    
    else if(stone % 2 != 0)
    {
        printf("Alice\n");
    }
    
    return 0;
}
