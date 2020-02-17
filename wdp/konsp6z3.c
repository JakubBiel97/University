#include <stdio.h>


int add(int *x, int *y)
{
    int sum = 0;
    sum = *x + *y;
    return sum;
}


int main()
{
    int *x, *y;
    int sum;

    printf("Podaj pierwsza liczbe: ");
    scanf("%d", &x);
    printf("Podaj druga liczbe: ");
    scanf("%d", &y);

    sum =       add(&x, &y);

    printf("\nSuma tych dwoch liczb wynosi: %d",sum);

    return 0;
}
