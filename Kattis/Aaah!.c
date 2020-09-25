#include<stdio.h>
#include<string.h>

int main()
{
    char str1[1001];
    char str2[1001];
    
    scanf("%s", str1);
    getchar();
    
    scanf("%s", str2);
    getchar();
    
    if(strlen(str2) > strlen(str1))
    {
        printf("no\n");
    }
    else if(strlen(str2) < strlen(str1))
    {
        printf("go\n");
    }
    else
    {
        printf("go\n");
    }

    return 0;
}
