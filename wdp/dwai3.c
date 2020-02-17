#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int *tablica, size;

    printf("Wpisz wielkosc tablicy: ");
    scanf("%d", &size);

    tablica = malloc(size * sizeof(*tablica));

    time_t tt;
    int zarodek = time(&tt);
    srand(zarodek);

    for(int i = 0; i < size; i++)
    {
        tablica[i] = rand();

        if(tablica[i] % 2 == 0 || tablica[i] % 3 ==0)
            printf("%d\n", tablica[i]);
    }



    free(tablica);


    return 0;
}
