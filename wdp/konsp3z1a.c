#include <stdio.h>

int main()
{
    int a = 0;
    printf("Wpisz liczbe:  \n");
    scanf("%d", &a);

    if(a % 5 == 0)
        printf("liczba %d jest podzielna przez 5 bez reszty.", a);
    else
        printf("Liczba %d nie jest podzielna przez 5.", a);



    return 0;
}
