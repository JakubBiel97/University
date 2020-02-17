#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int num[50];
    int sum = 0;
    time_t t;
    srand((unsigned)time(&t));

    for(int i = 0; i < 50; i++)
    {
        num[i] = rand() % 100 +1;
        printf("%d   ", num[i]);
        sum += num[i];

        if((i+1) % 10 == 0)     //wyglad
            printf("\n");
    }

    printf("\n\nSuma naszych liczb wynosi: %d.", sum);

    return 0;
}
