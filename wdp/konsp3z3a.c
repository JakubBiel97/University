#include <stdio.h>

int main()
{
    int a,b,c;

    printf("podaj pierwsza liczbe: \n");
    scanf("%d", &a);
    printf("podaj druga liczbe: \n");
    scanf("%d", &b);
    printf("podaj trzecia liczbe: \n");
    scanf("%d", &c);

    int eq;

    if(a >= b)
    {
        if(b > c)
            eq = b+c-a;
        else if(a > c)
            eq = b+c-a;
        else
            eq = a+b-c;
    }
    else if(a < b)
    {
        if(b >= c)
            eq = a+c-b;
        else if(a > c)
            eq = a+c-b;
        else
            eq = a+b-c;
    }

    //printf("%d.\n", eq);    //test

    if(eq > 0)
        printf("Warunek na trojkat jest spelniony.\n");
    else
        printf("warunek na trojkat nie jest spelniony.\n");


    return 0;
}
