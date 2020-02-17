#include <stdio.h>

int dodawanie(int a, int b)
{
    int wynik = 0;
    wynik = a + b;
    return wynik;
}
int odejmowanie(int a, int b)
{
    int wynik = 0;
    wynik = a - b;
    return wynik;
}
int mnozenie(int a, int b)
{
    int wynik = 0;
    wynik = a * b;
    return wynik;
}
float dzielenie(int a, int b)
{
    float wynik = 0;
    wynik = (a * 1.0) / b;
    return wynik;
}



int main()
{


    for(; ;)
    {
        char operator;
        int a = 0, b = 0;

        printf("Wprowadz pierwsza liczbe: \n");
        scanf("%d", &a);
        printf("Wprowadz druga liczbe: \n");
        scanf("%d", &b);
        printf("Wprowadz operator akcji( - , + , / , * ): \n");
        scanf("%s", &operator);

        switch(operator)
        {
        case '-':
            printf("%d - %d = %d \n\n\n", a, b, odejmowanie(a,b));
            break;
        case '+':
            printf("%d + %d = %d \n\n\n", a, b, dodawanie(a,b));
            break;
        case '/':
            printf("%d / %d = %.2f \n\n\n", a, b, dzielenie(a,b));
            break;
        case '*':
            printf("%d * %d = %d \n\n\n", a, b, mnozenie(a,b));
            break;
        default:
            printf("Zly operator.\n\n\n");
            break;
        }
    }



    return 0;
}
