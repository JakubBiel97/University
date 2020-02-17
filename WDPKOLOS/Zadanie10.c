#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct kolo
{
    int xSrodek;
    int ySrodek;
    int promien;
};

void polozenieKol()
{
    time_t tt;
    int zarodek = time(&tt);
    srand(zarodek);

    struct kolo kolo[2];

    struct kolo pierwsze;
    pierwsze.xSrodek = rand()%100 - 50;
    pierwsze.ySrodek = rand()%100 - 50;
    pierwsze.promien = rand()%50;

    struct kolo drugie;
    drugie.promien = rand()%50;
    drugie.xSrodek = rand()%100 - 50;
    drugie.ySrodek = rand()%100 - 50;

    /*printf("%d\n", pierwsze.promien);
    printf("%d\n", drugie.promien);
    printf("%d\n", pierwsze.xSrodek);
    printf("%d\n", drugie.xSrodek);
    printf("%d\n", pierwsze.ySrodek);
    printf("%d\n", drugie.ySrodek); */


    double odleglosc;
    odleglosc = (double)sqrt(((pierwsze.xSrodek - drugie.xSrodek)*(pierwsze.xSrodek - drugie.xSrodek)) +
                           ((pierwsze.ySrodek - drugie.ySrodek)*(pierwsze.ySrodek - drugie.ySrodek)));

    //printf("%f", odleglosc);   //test

    if(pierwsze.promien + drugie.promien < odleglosc)
        printf("Kola sa rozlaczne.");
    else if(pierwsze.promien + drugie.promien == odleglosc)
        printf("Kola sa styczne.");
    else//(pierwsze.promien + drugie.promien > odleglosc)
        printf("Kola sa przecinajace.");
}


int main()
{
    polozenieKol();


    return 0;
}
