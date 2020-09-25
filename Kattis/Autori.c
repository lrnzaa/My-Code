#include <stdio.h>
#include <string.h>

int main ()
{
    int panjang, i;
    char name[101];
    
    scanf("%[^\n]", name);
    
    panjang = strlen(name);
    
    for(i = 0; i < panjang; i++)
    {
        if(i == 0)
        {
            printf("%c", name[i]);
        }
        
        if(name[i] == 45)
        {
            printf("%c", name[i+1]);
        }
    }
    
    printf("\n");
    
    return 0;
}
