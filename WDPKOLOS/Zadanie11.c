#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 20

void generowanieTablicy()
{
    time_t tt;
    int zarodek = time(&tt);
    srand(zarodek);

    int tablica[SIZE][SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            tablica[i][j] = rand()% 512 + 512;
            printf("%d  ", tablica[i][j]);
        }
        printf("\n");
    }
}

void sumowanieBrzegow()
{
    int tablica[SIZE][SIZE];
    int sumB = 0;

    for(int i = 0; i < SIZE; i++)
        sumB += tablica[i][0];
    for(int i = 0; i < SIZE; i++)
        sumB += tablica[i][SIZE-1];
    for(int j = 1; j < (SIZE-1); j++)
        sumB += tablica[0][j];
    for(int j = 1; j < (SIZE-1); j++)
        sumB += tablica[SIZE-1][j];

    printf("\n\nSuma brzegow wynosi: %d", sumB);    // wynik z kosmosu
}

void sumowaniePrzekatnej()
{
    int sumP = 0;
    int tablica[SIZE][SIZE];

    int j = 0;
    for(int i = 0; i < SIZE; i++)
    {
        sumP += tablica[i][j];
        j++;
    }

    printf("\nSuma przekatnej wynosi: %d", sumP);
}

int main()
{
    generowanieTablicy();
    sumowanieBrzegow();
    sumowaniePrzekatnej();

    return 0;
}
