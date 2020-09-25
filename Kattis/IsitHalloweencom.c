#include <stdio.h>
#include<string.h>

int main()
{
    char tes[7];
    
    scanf("%[^\n]", tes);
    
    if(strcmp(tes, "OCT 31") == 0 || strcmp(tes, "DEC 25") == 0)
    {
        printf("yup\n");
    }
    
    else
     printf("nope\n");
     
    return 0;
}
