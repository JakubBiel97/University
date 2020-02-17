#include <stdio.h>

int main()
{
    int *pointer = 5;

    printf("Wartosc wskaznika: %d.", pointer);
    printf("\nAdres wskaznika: %p.", &pointer);

    return 0;
}
