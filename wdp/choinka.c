#include <stdio.h>

int main()
{
    int a;
    printf("Wpisz ilosc galezi: ");
    scanf("%d", &a);

    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= i; j++)
            printf("*");

        printf("\n");
    }

    printf("*\n*\n*\n");




    return 0;
}
