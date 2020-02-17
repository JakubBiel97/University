#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int najmniejszy(int *tablica, int wymiar)
{
    int najm = tablica[0];
    for(int i = 0; i < wymiar; i++)
    {
        if(tablica[i] < najm)
            najm = tablica[i];
    }
    return najm;
}

int najwiekszy(int *tablica, int wymiar)
{
    int najw = tablica[0];
    for(int i = 0; i < wymiar; i++)
    {
        if(tablica[i] > najw)
            najw = tablica[i];
    }
    return najw;
}


int main()
{
    int wymiar;
    int *tablica;

    printf("Wpisz rozmiar tablicy do stworzenia: \n");
    scanf("%d", &wymiar);

    tablica = (int*)malloc(wymiar * sizeof(int));

    time_t t;
    srand((unsigned)time(&t));

    for(int i = 0; i < wymiar; i++)
    {
        tablica[i] = rand() % 101;
        printf("\n%d wyraz w tablicy to %d.", i, tablica[i]);
    }

    printf("\n\n");
    printf("\nNajmniejsza wartosc wpisana do tablicy wynosi: %d", najmniejszy(tablica, wymiar));

    printf("\n\n");
    printf("\nNajmniejsza wartosc wpisana do tablicy wynosi: %d\n", najwiekszy(tablica, wymiar));


    free(tablica);

    return 0;
}
