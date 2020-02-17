#include <stdio.h>
#include <stdbool.h>

int intLength(int a)
{
    int dl = 1;
    return (a > 9) ? intLength(a / 10, dl + 1) : dl;
}

bool isNarcissistic(int a)
{
    int suma = 0;
    int dl = intLength(a);
    for(int i = 0; i < dl; i++)
    {
        suma += pow((int)(a / pow(10, i)) % 10, dl);
    }
    return suma == a;
}

/*void kNarcissisticSimple(int a, int range){
    for(int i = 0; i < range; i++)
    {
        if(isNarcissistic(i))
            //cout << i << " ";
            printf("%d", i);

    }
}*/

int main()
{
    int a, range = 0;
    printf("podaj zakres: \n");
    scanf("%d", &range);

    for(int i = 0; i < range; i++)
    {
        isNarcissistic(i);
    }




    return 0;
}
