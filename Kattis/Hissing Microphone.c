#include <stdio.h>
#include <string.h>

int main ()
{
    char hisss[31];
    int i, panjang, count;
    
    scanf("%s", hisss);
    
    panjang = strlen (hisss);
    count = 0;
    
    for(i = 0; i < panjang; i++)
    {
        if(hisss[i] == 's' && hisss[i+1] == 's')
        {
            count++;
        }
    }
    
    if(count > 0)
    {
        printf("hiss\n");
    }
    
    else if(count == 0)
    {
        printf("no hiss\n");
    }
    
    return 0;
}
