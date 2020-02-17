#include <stdio.h>

int main()
{
    int a;

    printf("Podaj numer dnia tygodnia: \n");
    scanf("%d", &a);

    switch(a)
    {
    case 1:
        printf("Poniedzialek.\n");
        break;
    case 2:
        printf("wt.\n");
        break;
    case 3:
        printf("sr.\n");
        break;
    case 4:
        printf("czw.\n");
        break;
    case 5:
        printf("pt.\n");
        break;
    case 6:
        printf("sob.\n");
        break;
    case 7:
        printf("nd.\n");
        break;
    }




    return 0;
}
