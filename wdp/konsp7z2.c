#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int iloscLiczbP(int *tablica, int wymiar)
{
    int par = 0;
    for(int i = 0; i < wymiar; i++)
        if(tablica[i] % 2 == 0)
            par++;

    return par;
}

int tablicaLiczbP(int *tablica, int wymiar, int par)
{
    int *tablicaLiczbParzystych;

    tablicaLiczbParzystych = (int*)malloc(par * sizeof(int));

    int j = 0;

    for(int i = 0; i < wymiar; i++)
        if(tablica[i] % 2 == 0)
            {
                tablicaLiczbParzystych[j] = tablica[i];
                j++;
            }

    return *tablicaLiczbParzystych;
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
        printf("\n%d wyraz w tablicy to %d.", i+1, tablica[i]);
    }

    printf("\n\nW naszej tablicy sa %d liczby parzyste.\n", iloscLiczbP(tablica, wymiar));

    for(int i = 0; i < iloscLiczbP(tablica, wymiar); i++)
       printf("\n%d.  %d", i+1, tablicaLiczbP(tablica, wymiar, iloscLiczbP(tablica, wymiar)));


    free(tablica);

    return 0;
}

