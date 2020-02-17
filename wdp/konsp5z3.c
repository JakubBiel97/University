#include <stdio.h>

int main()
{
    int num[2][10] ={
        {1,2,3,4,5,6,7,8,9,10,},
        {11,12,13,14,15,16,17,18,19,20}
        };

    int sum = 0;
    int i, j = 0;

    for(int i = 0; i < 2; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(i % 2 == 0)
                {
                    if(j % 2 == 0)
                        sum += num[i][j];
                }
            printf("i = %d , j = %d\n\n", i , j);
        }
    }

    printf("suma: %d", sum);

    return 0;
}
