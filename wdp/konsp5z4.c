#include <stdio.h>

int main()
{
    int num[5][5] =
    {
        {3,1,2,4,5},
        {2,9,8,5,6},
        {1,2,3,4,5},
        {1,5,12,3,5},
        {0,8,5,6,7}
    };

    int sum1 = 0, sum2 = 0;
    int i, j = 0;

    for(int i = 0; i < 5; i++)
    {
        printf("Punkt (%d,%d) przekatnej to: %d.\n", i, j, num[i][j]);
        sum1 += num[i][j];
        j++;
    }

    printf("\nSuma liczb na przekatnej wynosi: %d\n", sum1);

    j = 1;

    for(int i = 0; i < 5; i++)
    {
        if(j == 5)
            break;

        printf("\nPunkt (%d, %d) nad przekatna wynosi: %d", i, j, num[i][j]);
        sum2 += num[i][j];
        j++;
    }

    printf("\n\nSuma liczb nad przekatna wynosi: %d\n", sum2);
    printf("\nSuma wszystkich liczb wynosi: %d\n", sum1 + sum2);


    return 0;
}
