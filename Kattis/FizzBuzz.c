#include <stdio.h>

int main()
{
    int X, Y, N, n1;
    
    scanf("%d %d %d", &X, &Y, &N);
    
    for(n1 = 1; n1 <= N; n1++)
    {
        if(n1 % X == 0 && n1 % Y == 0)
        {
            printf("FizzBuzz\n");
        }
        else if(n1 % X == 0)
        {
            printf("Fizz\n");
        }
        else if(n1 % Y == 0)
        {
            printf("Buzz\n");
        }
        else
        {
            printf("%d\n", n1);
        }
    }
    
    return 0;
}
