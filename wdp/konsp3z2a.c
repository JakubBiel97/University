#include <stdio.h>

int main()
{
    int a, b;

    printf("podaj pierwsza liczbe: \n");
    scanf("%d", &a);
    printf("podaj druga liczbe: \n");
    scanf("%d", &b);

    switch(a, b)
    {
        case (a > b):
            printf("a jest wieksze od b.\n");
            break;
        case(b > a):
            printf("b jest wieksze od a.\n");
            break;
    }





    return 0;
}
