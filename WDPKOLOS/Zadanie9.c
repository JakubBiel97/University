#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tworzenieTablicy()
{
    int size = 0, suma = 0;
    printf("Wpisz rozmiar tablicy do stworzenia: \n");
    scanf("%d", &size);

    int *tablica;

    tablica = malloc(size * sizeof(*tablica));

    time_t tt;
    int zarodek = time(&tt);
    srand(zarodek);

    for(int i = 0; i < size; i++)
    {
        tablica[i] = rand()% 31;
        suma += tablica[i];
    }

    float srednia = 0;
    srednia = (float)suma/(float)size;

    printf("Srednia liczb w tablicy wynosi: %.2f.", srednia);

}

int main()
{
    tworzenieTablicy();

    return 0;
}
