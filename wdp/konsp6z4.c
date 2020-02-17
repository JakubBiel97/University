#include <stdio.h>


void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


int main()
{
    int *x, *y;

    printf("Podaj pierwsza liczbe: ");
    scanf("%d", &x);
    printf("Podaj druga liczbe: ");
    scanf("%d", &y);

    printf("Przed wywolaniem funkcji - x = %d, a y = %d\n", x, y);

    swap(&x, &y);

    printf("Po wywolaniu funkcji - x = %d, a y = %d", x, y);

    return 0;
}
