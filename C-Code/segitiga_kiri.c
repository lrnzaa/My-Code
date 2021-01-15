#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main()
{
    int a, b, i;
    printf("Angka : ");
    scanf("\n %d", &i);

    for (a = 1 ; a <= i ; a++)
    {
        for(b = 1 ; b <= a ; b++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

/*
//sikuterbalik

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main()
{
    int a, b, i;
    
    printf("Angka : ");
    scanf("\n %d", &i);

    for (a = i; a >= 1; a--)
    {
        for(b = a; b >= 1; b--)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
*/
