#include <stdio.h>

#define PI 3.14

double pole(int r)
{
    double wynik = 0;
    wynik = PI * r * r;
    return wynik;
}

double obwod(int r)
{
    double wynik = 0;
    wynik = 2 * PI * r;
    return wynik;
}

int main()
{
    int r = 0,a ;

    printf("Wprowadz promien kola: \n");
    scanf("%d", &r);
    printf("Co chcesz policzyc: 1 - pole, 2 - obwod: \n");
    scanf("%d", &a);

    switch(a)
    {
    case 1:
        printf("Pole kola wynosi: %.2f.\n", pole(r));
        break;
    case 2:
        printf("obwod kola wynosi: %.2f.\n", obwod(r));
    }

    //printf("Pole kola wynosi: \n");


    return 0;
}
