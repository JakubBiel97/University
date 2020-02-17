#include <stdio.h>

int main()
{
    int zakres, a, sum = 0;

    printf("Prosze wprowadzic zakres: \n");
    scanf("%d", &zakres);

    for(int a = 0; a <= zakres; a++)
    {
        if(a%2 == 0)
            sum += a;

    }

    printf("suma liczb parzystych w zakresie: %d wynosi: %d", zakres, sum);

    return 0;
}
